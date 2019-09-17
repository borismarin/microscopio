use std::thread;
use std::time::Instant;

/// O tipo que o microscópio real retornaria.
type Pixel = u32;

pub fn run_benchmark() {
    let (tx, rx) = crossbeam_channel::unbounded();

    let sender = thread::spawn(move || {
        let pixels_to_write = 2048 * 2048;
        let mut total_time = 0u128;

        for _i in 0..pixels_to_write {
            let now = Instant::now();
            tx.send(42 as Pixel).unwrap();
            let elapsed = now.elapsed();

            total_time = total_time + elapsed.as_nanos();
        }
        drop(tx); // Fecha o canal. o .recv() abaixo vai retornar Err, saindo do loop

        let average = (total_time as f32) / (pixels_to_write as f32);
        println!("Average write: {} ns/px", average);
    });

    let receiver = thread::spawn(move || {
        let mut pixels_read = 0;

        let now = Instant::now();

        while let Ok(_data) = rx.recv() {
            pixels_read = pixels_read + 1;
        }

        println!("Read {} pixels in {:?} ms", 
                 pixels_read,
                 now.elapsed().as_millis());
    });

    sender.join().unwrap();
    receiver.join().unwrap();
}

pub fn run_buffered_benchmark() {
    let buffer_size = 20; // Envia 20pixels por send

    let (tx, rx) = crossbeam_channel::unbounded(); 

    let sender = thread::spawn(move || {
        let pixels_to_write = 2048 * 2048;
        let mut total_time = 0u128;

        for _i in 0..(pixels_to_write/buffer_size) {
            let buf: Vec<Pixel> = (0..(buffer_size)).map(|_| 42).collect();
            let now = Instant::now();

            tx.send(buf).unwrap();

            total_time = total_time + now.elapsed().as_nanos();
        }
        drop(tx); // Fecha o canal. o .recv() abaixo vai retornar Err, saindo do loop

        let average = (total_time as f32) / (pixels_to_write as f32);
        println!("Average write: {} ns/px", average);
    });

    let receiver = thread::spawn(move || {
        let buffer_size = 20;

        let mut pixels_read = 0;

        let now = Instant::now();

        while let Ok(_data) = rx.recv() {
            pixels_read = pixels_read + 1;
        }

        println!("Read {} pixels in {:?} ms", 
                 pixels_read * buffer_size,
                 now.elapsed().as_millis());
    });

    sender.join().unwrap();
    receiver.join().unwrap();
}
