include!("std.rs");
use std::cmp::{max, min};

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

fn solve(n: usize, k: usize, t: usize, i: usize) -> usize {
    //println!("n: {} k: {} t: {} ", n, k-i, t);
    if n == 1 {
        if t<k { 1 }
        else { 0 }
    }
    else if t < k { binomio(t+n-1, n-1) }
    else if t > n * k { 0 }
    /* abbiamo t palline e dobbiamo contare tutti i modi in cui le possiamo dividere su n scatole,
     * t<k, per cui a questo punto non abbiamo bisogno di controllare se una scatola sfora: 
     * binomio di (t + n-1 su n-1)
     */
    else if t < 2*k { binomio(t+n-1, n-1) - n * binomio(t-k+n-1, n-1) }
    //else if t < 3*k { binomio(t+n-1, n-1) - n * (binomio(t-k-n-1, n-1) - binomio(t-k-k-n-1, n-1)/2) }
    else if i<k { 
            solve(n-1, k, t-k+i, 1) + solve(n, k, t, i+1)
    }
    else { 0 }
}

fn main() {
    let tmp = get_line::<usize>().unwrap();

    let ans = solve(tmp[0], tmp[1], min(tmp[2]-tmp[0], tmp[0] * tmp[1]-tmp[2]), 1);
    println!("{}", ans % 1000000009);
}
