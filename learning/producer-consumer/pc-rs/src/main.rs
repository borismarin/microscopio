mod vanilla;
mod crossbeam;

use std::time::Instant;

fn main() {
    println!("====One pixel per send====");
    println!("Running vanilla PC test...");
    vanilla::run_benchmark();

    println!("---------------------------");
    
    println!("Running crossbeam PC test...");
    crossbeam::run_benchmark();

    println!("====Buffered Send====");
    println!("Running vanilla PC test...");
    vanilla::run_buffered_benchmark();

    println!("---------------------------");
    
    println!("Running crossbeam PC test...");
    crossbeam::run_buffered_benchmark();
}
