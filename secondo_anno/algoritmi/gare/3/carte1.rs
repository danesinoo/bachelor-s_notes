include!("std.rs");

fn binomio(arr: &Vec<usize>) -> usize {
    fact(arr[2]+arr[0] -1, arr[2]) / fact(arr[0]-1, 1) 
}

fn fact(n: usize, fine: usize) -> usize {
    if n>fine { n * fact(n-1, fine) }
    else { 1 }
}

fn conta(arr: &Vec<usize>) -> usize {
    if arr[2] == 0 { return 1; }
    else if arr[2] < arr[1] { 
        return binomio(arr); 
    }
    else if arr[0] == 0 || (arr[1]-1) * arr[0] < arr[2] { return 0; }
    let mut ans = 0;
    for i in 0..arr[1] {
        if arr[2] >= i {
            ans += conta(&vec![arr[0] -1, arr[1], arr[2] - i]);
        }
    }
    return ans;
}

fn main() {
    let mut arr= get_line::<usize>().unwrap();
    arr[2] -= arr[0];
    arr[1] -= 1;

//    println!("{}", conta(&arr) % 1000000009);
    println!("{}", fact(
}
