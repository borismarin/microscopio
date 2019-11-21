use lazy_static::lazy_static;

use crossbeam_channel::{
    Receiver,
    Sender,
    unbounded
};

#[repr(C)]
pub struct Pixel(u32);

#[derive(Debug)]
pub struct ServerState {
    rx: Receiver<Pixel>,
    tx: Sender<Pixel>,
    dummy: u32
}

impl Drop for ServerState {
    fn drop(&mut self) {
        println!("Dropped {:?}", self);
    }
}

lazy_static! {
    static ref INSTANCE: Box<ServerState> = new_instance();
}

pub fn new_instance() -> Box<ServerState> {
    let (tx, rx) = unbounded();

    let instance = Box::new(ServerState { tx, rx, dummy: 420 });

    println!("Created instance {:?}", instance);

    instance
}

#[no_mangle]
pub extern fn start_thread(buf_size: usize) {
    println!("Starting thread with instance {:?}", *INSTANCE);

    let tx = INSTANCE.tx.clone();

    std::thread::spawn(move || {
        for i in 0..buf_size {
            match tx.send(Pixel(i as u32)) {
                Ok(_) => {},
                Err(error) => println!("{:?}", error)
            }
        }
    });
}

#[no_mangle]
pub fn read_data(len: usize) -> *const Pixel {
    println!("Reading from instance {:?}", *INSTANCE);

    let data: Vec<Pixel> = INSTANCE.rx
        .iter()
        .take(len)
        .collect();

    let ptr = data.as_ptr();

    //std::mem::forget(data);

    ptr
}

#[no_mangle]
extern "C" fn read_data_safe(ptr: *mut Pixel, len: usize) {
    println!("Reading safely from instance {:?}", *INSTANCE);

    let data: Vec<Pixel> = INSTANCE.rx
        .iter()
        .take(len)
        .collect();

    let ptr = data.as_ptr();

}

#[no_mangle]
pub fn stop() {
    //let _ = INSTANCE::leak(INSTANCE);
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
