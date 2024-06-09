fn rec_fib(n: usize) -> usize {
	if n<2 {return 1;}
	return rec_fib(n-1) + rec_fib(n-2);
}

fn main() {
    let n = 20;
    let mut ans = 1;
    let mut tmp = 1;
    for _ in 0..n {
        ans += tmp;
        tmp = ans - tmp;
    }
    println!("{}", tmp);
	println!("{}", rec_fib(n));
}
