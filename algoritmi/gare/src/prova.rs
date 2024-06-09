include!("stl.rs"); use std::collections::BinaryHeap;
type Num = usize;

fn get_max(a: &mut BinaryHeap<Num>, b: &mut BinaryHeap<Num>, c: &mut BinaryHeap<Num>) -> usize {
    let mut ans = 0;
    let mut w = 0;
    if a.len() > 0 { ans = *a.peek().unwrap() }
    if b.len() > 0 && ans < *b.peek().unwrap() { ans = *b.peek().unwrap(); w += 1; }
    if c.len() > 0 && ans < *c.peek().unwrap() { w += 2; }
    if w == 1 {
        a.pop().unwrap() * b.pop().unwrap()
    }
    else if w==2 {
        a.pop().unwrap() * c.pop().unwrap()
    }
    else {
        b.pop().unwrap() * c.pop().unwrap()
    }
}

fn main() -> Result<(), Error> {
    let _arr = get_line::<Num>()?;
    let mut r= BinaryHeap::from(get_line::<Num>()?);
    let mut g= BinaryHeap::from(get_line::<Num>()?);
    let mut b= BinaryHeap::from(get_line::<Num>()?);
    let mut ans = 0;
    while r.len() > 0 && g.len() > 0 || r.len()>0 && b.len() > 0 || g.len()>0 && b.len() > 0 {
        ans += get_max(&mut r, &mut g, &mut b);
    }
    println!("{}", ans);
    Ok(())
}
