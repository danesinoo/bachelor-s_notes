
use std::io::stdin;
#[derive(Debug)]
pub enum Error {
    OnInput,
    OnParse,
    OnLine,
    OnDigit,
}

pub fn get_input() -> Result<String, Error> {
    let mut input = format!("");
    match stdin().read_line(&mut input) {
        Ok(_) => {},
        Err(_) => { return Err(Error::OnInput) }
    };
    input = input.trim().to_string();
    Ok(input)
}

#[allow(dead_code)]
pub fn get_type<T: std::str::FromStr>() -> Result<T, Error>  {
    let input = get_input()?;
    match input.parse::<T>() {
        Ok(i) => { return Ok(i) },
        Err(_) => { return Err(Error::OnParse); }
    };
}

#[allow(dead_code)]
pub fn get_line<T: std::str::FromStr>() -> Result<Vec<T>, Error> {
    let input = get_input()?;
    let mut ans= Vec::new();
    for i in input.split_whitespace() {
        match i.parse::<T>() {
            Ok(j) => { ans.push(j) },
            Err(_) => { return Err(Error::OnLine) }
        };
    }
    Ok(ans)
}
use std::cmp::max;
type Num = usize;

fn solve(a: &mut Vec<Num>, b: &mut Vec<Num>) {
    let mut i = 2;
    if a.len() > 1 {
        a[1] += b[0];
        b[1] += a[0];
        while i<a.len() {
            a[i] += max(b[i-1], b[i-2]);
            b[i] += max(a[i-1], a[i-2]);
            i+=1;
        }
    }
}

fn main() -> Result<(), Error> {
    let tmp = get_type::<Num>()?;
    let mut a = get_line::<Num>()?;
    let mut b = get_line::<Num>()?;
    solve(&mut a, &mut b);
    println!("{}", max(a[tmp-1], b[tmp-1]));
    Ok(())
}
