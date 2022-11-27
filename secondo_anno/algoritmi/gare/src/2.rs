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
use std::collections::VecDeque;
type Num = isize;

fn isin(dir: usize, m: usize, a: &Vec<Vec<isize>>, pos: &Vec<usize>) -> bool {
    dir==0 && pos[1]+m < a[0].len() && cell(dir, m, a, pos)>-3 ||
    dir==2 && pos[0]+m < a.len() && cell(dir, m, a, pos)>-3  ||
    dir==1 && pos[1] as isize -m as isize >= 0 && cell(dir, m, a, pos)>-3  ||
    dir==3 && pos[0] as isize -m as isize >= 0 && cell(dir, m, a, pos)>-3 
}


fn cell(dir: usize, m: usize, a: &Vec<Vec<isize>>, pos: &Vec<usize>) -> isize {
    if dir ==0 { a[pos[0]][pos[1]+m] }
    else if dir ==1 { a[pos[0]][pos[1]-m] }
    else if dir ==2 { a[pos[0]+m][pos[1]] }
    else { a[pos[0]-m][pos[1]] }
}

fn cell_mut<'a>(dir: usize, m: usize, a: &'a mut Vec<Vec<isize>>, pos: &Vec<usize>) -> &'a mut isize {
    if dir ==0 { &mut a[pos[0]][pos[1]+m] }
    else if dir ==1 { &mut a[pos[0]][pos[1]-m] }
    else if dir ==2 { &mut a[pos[0]+m][pos[1]]
    }
    else { &mut a[pos[0]-m][pos[1]] }
}

fn cpos(dir: usize, m: usize, pos: &Vec<usize>) -> Vec<usize> {
    let mut pos = pos.to_vec();
    if dir == 0 { pos[1] += m; }
    else if dir == 1 { pos[1] -= m; }
    else if dir == 2 { pos[0] += m; }
    else { pos[0] -= m; }
    vec![pos[0], pos[1]]
}

fn solve(a: &mut Vec<Vec<isize>>, speed: usize, mut pos: Vec<usize>) {
    let mut p = VecDeque::with_capacity(20);
    p.push_back(vec![pos[0], pos[1]]);
    while p.len() > 0 {
        pos = p.pop_front().unwrap();
        for dir in 0..4 {
            for m in 1..speed+1 {
                if !isin(dir, m, a, &pos) || cell(dir, m, a, &pos) > 0 { break; } 
                else if cell(dir, m, a, &pos) == -2 {
                    *cell_mut(dir, m, a, &pos) = a[pos[0]][pos[1]] +1;
                    p.push_back(cpos(dir, m, &pos));
                } // devo aggiungere le celle nuove
                else if cell(dir, m, a, &pos) == -1 {
                    *cell_mut(dir, m, a, &pos) = a[pos[0]][pos[1]] +1; 
                        return; 
                }
            }
        }
    }
}


fn main() -> Result<(), Error> {
    let arr = get_line()?; // dimensione e velocità
    let mut dun: Vec<Vec<Num>>= Vec::new();
    for _ in 0..arr[0] {
        dun.push(get_input()?.chars().map(|chr| -> isize {
            match chr {
                '.' => { -2 },
                _ => { -3},
            }
        }).collect::<Vec<isize>>());
    }
    let mut pos = get_line::<usize>()?;
    for i in &mut pos {
        *i -= 1;
    }
    dun[pos[0]][pos[1]] = 0;
    dun[pos[2]][pos[3]] = -1;
    solve(&mut dun, arr[2], pos[0..2].to_vec());
    println!("{}", dun[pos[2]][pos[3]]);
    Ok(())
}
