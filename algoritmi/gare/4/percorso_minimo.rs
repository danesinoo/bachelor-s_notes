use std::collections::{HashMap, VecDeque};
include!("stl.rs");
type Num=usize;

fn insert(l: &mut HashMap<Num, Vec<Num>>, tmp: &Vec<Num>) {
    for i in 0..2 {
        match l.remove(&tmp[i]) {
            Some(mut x) => {
                x.push(tmp[1-i]);
                l.insert(tmp[i], x);
            },
            None => { l.insert(tmp[i], vec![tmp[1-i]]); }
        };
    }
}

fn change(a: &mut Vec<usize>, i: Num, j: Num) -> bool {
    if a[i]+1 > a[j] { false }
    else {
        a[j] = a[i] + 1;
        true
    }
}

fn solve(l: &mut HashMap<usize, Vec<usize>>, a: &mut Vec<usize>) {
    let mut p = VecDeque::with_capacity(20);
    p.push_back(0);
    let mut tmp;
    while p.len() > 0 {
        tmp = p.pop_front().unwrap();
        match l.get(&tmp) {
            Some(x) => {
                for i in x {
                    if change(a, tmp, *i) {
                        p.push_back(*i);
                    }
                }
            },
            None => {}
        };
    }
}

fn main() -> Result<(), Error> {
    let arr = get_line::<Num>()?;
    let mut tmp;
    let mut links: HashMap<Num, Vec<Num>> = HashMap::new();
    for _ in 0..arr[1] {
        tmp = get_line::<Num>()?;
        tmp[0] -= 1; tmp[1] -= 1;
        insert(&mut links, &tmp);
    }
    let mut ans = vec![usize::MAX; arr[0]];
    ans[0] = 0;
    solve(&mut links, &mut ans);
    println!("{}", ans[arr[0]-1] -1);
    Ok(())
}
