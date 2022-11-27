mod stl;
use stl::*;
type Num = usize;

fn col(t: usize, w: &Vec<Vec<Num>>) -> usize {
    t%w[0].len()
}

fn row(t: usize, w: &Vec<Vec<Num>>) -> usize {
    t/w[0].len()
}

fn init(p: &mut Vec<Vec<Num>>, w: &mut Vec<Vec<Num>>, t: usize) {
    let mut i = t+w[0].len();
    let mut min = w[row(t,w)+1][col(t, w)];
    if col(t, w) > 1 {
        if min > w[row(t,w)][col(t,w)-1] + w[row(t,w)+1][col(t,w)-2] {
            min = w[row(t,w)][col(t,w)-1]+ w[row(t,w)+1][col(t,w)-2];
            i = t -1;
        }
    }
    if col(t, w) > 0 && min > w[row(t,w)+1][col(t,w)-1] {
        min = w[row(t,w)+1][col(t,w)-1];
        i = t - 1 + w[0].len();
    }
    if col(t,w) +1 < w[0].len() {
        if min > w[row(t,w)][col(t,w)+1] {
            min = w[row(t,w)][col(t,w)+1];
            i = t+1;
        }
        if min > w[row(t,w)+1][col(t,w)+1] {
            min = w[row(t,w)+1][col(t,w)+1];
            i = t+1+w[0].len();
        }
    }
    p[row(t, w)][col(t, w)] = i;
    w[row(t, p)][col(t, p)] += min;
}

fn solve(p: &mut Vec<Vec<Num>>, mut w: Vec<Vec<Num>>) -> Vec<Num> {
    let mut t = ((w.len()-1) * w[0].len() -1) as i16;
    while t > -1 {
        init(p, &mut w, t as usize);
        t-= 1;
    }
    w.remove(0)
}

fn main() -> Result<(), Error> {
    let mut arr = get_line::<Num>()?;
    let mut wall;
    while arr[0] != 0 {
        wall = Vec::new();
        for _ in 0..arr[0] {
            wall.push(get_digit::<Num>()?);
        }
        let mut p = wall.clone();
        arr = solve(&mut p, wall.clone());
        let mut min=0;
        for i in 1..arr.len() {
            if arr[min] > arr[i] { min = i; }
        }
        for i in 0..wall.len()*wall[0].len() {
            if min == i {
                min = if p[row(min,&p)][col(min,&p)] > wall[0].len() {
                    p[row(min,&p)][col(min,&p)]
                } else {0};
                print!(" ");
            }
            else { print!("{}", wall[row(i,&wall)][col(i,&wall)]) }
            if (i+1)%wall[0].len()==0 {println!("")}
        }
        println!("");
        arr = get_line::<Num>()?;
    }
    Ok(())
}
