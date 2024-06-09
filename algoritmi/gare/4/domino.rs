use std::collections::HashMap;
use std::collections::HashSet;
use std::collections::VecDeque;
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

#[allow(dead_code)]
pub fn get_digit<T: std::str::FromStr>() -> Result<Vec<T>, Error> {
    let input = get_input()?;
    let mut ans = Vec::new();
    for i in input.chars() {
        match i.to_string().parse::<T>() {
            Ok(j) => { ans.push(j) },
            Err(_) => { return Err(Error::OnDigit) }
        };
    }
    Ok(ans)
}

type Num = usize;

fn solve(make_fall: &mut HashMap<Num, Vec<Num>>, cadenti: &mut VecDeque<Num>) -> Num {
    let mut fallen= HashSet::new();
    for i in cadenti.iter() {
        fallen.insert(*i);
    }
    while cadenti.len() > 0 {
        let tmp = cadenti.pop_front().unwrap();
        match make_fall.remove(&tmp) {
            Some(x) => {
                for i in x {
                    if fallen.insert(i) { cadenti.push_back(i); }
                }
            },
            None => {}
        }
        if make_fall.contains_key(&tmp) {
            cadenti.push_back(tmp);
        }
    }
    fallen.len()
}

fn main() -> Result<(), Error> {
    let samples = get_type::<Num>()?;
    for _ in 0..samples {
        let vars = get_line::<Num>()?;
        let mut make_fall: HashMap<Num, Vec<Num>> = HashMap::new();
        let mut vals;
        for _ in 0..vars[1] {
            vals = get_line::<Num>()?;
            match make_fall.remove(&vals[0]) {
                Some(mut x) => {
                    x.push(vals[1]);
                    make_fall.insert(vals[0], x);
                },
                _ => { make_fall.insert(vals[0], vec![vals[1]]); }
            }
        }
        let mut cadenti = VecDeque::with_capacity(vars[2]);
        for _ in 0..vars[2] {
            cadenti.push_back(get_type::<Num>()?);
        }
        let ans = solve(&mut make_fall, &mut cadenti);
        println!("{}", ans);
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test] 
    fn solver() {
        let mut make_fall= HashMap::new();
        make_fall.insert(1, vec![2]);
        make_fall.insert(2, vec![3,4,5]);
        make_fall.insert(3, vec![4,5]);
        make_fall.insert(5, vec![6]);
        make_fall.insert(6, vec![7]);
        make_fall.insert(7, vec![1]);
        let mut cadenti = VecDeque::with_capacity(1);
        cadenti.push_back(2);
        assert_eq!(7, solve(&mut make_fall, &mut cadenti));
    }
}
