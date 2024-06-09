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

