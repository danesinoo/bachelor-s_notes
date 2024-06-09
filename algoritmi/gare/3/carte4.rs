//use std::cmp::{max, min};
include!("std.rs");

type Num = u128;

/*
fn binomio(up: Num, down: Num) -> Num {
    fact(up, max(up-down, down)) / fact(min(up-down, down), 1)
}
*/

fn fact(mut n: Num, fine: Num) -> Num {
    let mut ans = 1;
    while n > fine {
        ans *= n;
        n-=1;
    }
    println!("ans: {}", ans);
    ans
}

fn conta(f: &Vec<Num>, i: usize) -> Num {
    let mut ans = 1;
    if i==f.len()-1 {
        let mut count= 0;
        for i in 1..f.len()+1 {
            if f[f.len()-i] > 1 {
                count += f[f.len()-i];
                ans *= fact(f[f.len()-i]-count, 2);
            }
        }
        fact(f[0], 1) / ans 
    }
    else {
        ans += conta(f, i+1) % 1000000009;
        if f[i]-1 > f[i+1] {
            let mut tmp = f.clone();
            tmp[i] -=1; tmp[i+1]+=1;
            ans += conta(&tmp, i) % 1000000009;
        }
        ans
    }
}

fn main() {
    let mut arr= get_line::<usize>().unwrap();

    let mut f = vec![0 as Num; arr[1]]; 
    while arr[2] > arr[0] {
        f.push(arr[0] as Num);
        arr[2] -= arr[0];
    }
    f.push(arr[2] as Num);
    arr[2] = 0;
    while f.len() < arr[1] { f.push(0); }
    let ans = conta(&f, 0);
    println!("{}", ans);
}
