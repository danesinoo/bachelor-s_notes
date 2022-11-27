mod heap;
mod maxheap;
use maxheap::heap_sort;

fn main() {
    println!();
    let mut arr: [isize; 10] = [0; 10];
    for i in 0..10 {
        arr[i] = 10 - i as isize;
    }
    let mut cp = arr;
    heap_sort(&mut cp);
    println!("{:?}", cp);
}
