use std::cmp::{max, min};
include!("std.rs");

fn fact(mut n: usize, fine: usize) -> usize {
    let mut ans = 1;
    while n>fine {
        ans *= n;
        n -=1;
    }
    ans
}

fn binomio(up: usize, down: usize) -> usize {
    fact(up, max(up-down, down)) / fact(min(up-down, down), 1)
}

fn solve(n: usize, k: usize, t: usize) -> usize {
    if t == 0 { 1 }
    else if n == 0 || (k-1) * n< t { 0 }
    else if t < k { binomio(t+n-1, n-1) }
    else if t < 2*k { binomio(t+n-1, n-1) - n * binomio(t-k+n-1, n-1) }
    else {
        let mut ans = 0;
        for i in 0..min(k, t+1) {
            if t >= i {
                ans += solve(n-1, k, t-i);
            }
        }
        ans
    }
}

fn main() {
    let tmp= get_line::<usize>().unwrap();
    //ho preso gli input
    let ans = solve(tmp[0], tmp[1], min(tmp[2]-tmp[0], tmp[0] * tmp[1]-tmp[2]));
    println!("{}", ans % 1000000009);
}
