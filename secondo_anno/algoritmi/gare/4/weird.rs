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

fn main() -> Result<(), Error> {
    let mut tmp = get_type::<usize>()?;
    while tmp != 1 {
        print!("{} ", tmp);
        if tmp%2==0 { tmp /=2; }
        else { tmp = tmp*3+1; }
    }
    println!("1");
    Ok(())
}

