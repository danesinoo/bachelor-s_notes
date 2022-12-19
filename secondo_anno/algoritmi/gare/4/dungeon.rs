use std::collections::VecDeque;
include!("stl.rs");
type Num = isize;
   
fn lung(d: &Vec<Vec<Vec<Num>>>, p: &Vec<usize>, dir: i8) -> bool {
    if dir == 0 && p[0] < d.len() -1 { true }
    else if dir == 1 && p[1] < d[0].len() -1 { true }
    else if dir == 2 && p[2] < d[0][0].len() -1 { true }
    else { false }
}

// mi muovo in una cella accanto in base alla direzione
// la direzione è indicata con un valore che va da 0 a 5
fn step(d: &Vec<Vec<Vec<Num>>>, mut p: Vec<usize>, dir: i8) -> Option<Vec<usize>> {
    if dir > 2 && lungh(d, &p, dir-3) {
        p[(dir-3) as usize] += 1;
        Some(p)
    }
    else if dir < 3 && p[dir as usize]>0 {
        p[dir as usize] -= 1;
        Some(p)
    }
    else { None }
}

fn free(d: &Vec<Vec<Vec<Num>>>, p: &Vec<usize>, dir: i8) -> bool {
    let p = match step(d, p.to_vec(), dir) {    // can you move?
        Some(x) => { x },                       // you can move
        None => { return false }                // you can't move
    };
    d[p[0]][p[1]][p[2]] == -1                   // is it empty?
}

fn exit(d: &Vec<Vec<Vec<Num>>>, p: &Vec<usize>, dir: i8) -> bool {
    let p = match step(d, p.to_vec(), dir) {    // can you go there?
        Some(x) => { x },                       // yes, you're in the dungeon
        None => { return false }                // no, you went out
    };
    d[p[0]][p[1]][p[2]] == -2                   // is it the exit?
}

//PRE: you can access the cell, already checked
fn cell<'a>(d: &'a mut Vec<Vec<Vec<Num>>>, mut p: Vec<usize>, dir: i8) -> &'a mut Num {
    if dir>2 { p[(dir-3) as usize] += 1; }      // add
    else { p[dir as usize] -= 1; }              // sub
    &mut d[p[0]][p[1]][p[2]]                    // access
}

fn get_value(d: &Vec<Vec<Vec<Num>>>, p: &Vec<usize>) -> Num {
    d[p[0]][p[1]][p[2]]                         // get the value in p(x, y, z) -> stand for position
}

fn mut_value(d: &mut Vec<Vec<Vec<Num>>>, p: &Vec<usize>, dir: i8) -> Option<Vec<usize>> {
    if free(d, p, dir) {                                    // you can move and it is empty
        *cell(d, p.to_vec(), dir) = get_value(d, p) + 1;    // access = value+1
        step(d, p.to_vec(), dir)                            // same fn you see in free
                                                            // return the pos moved
    }
    else if exit(d, p, dir) {
        Some(vec![(get_value(d, p) + 1) as usize; 1])
    }
    else { None }
}

fn solve(d: &mut Vec<Vec<Vec<Num>>>, mut tmp: Vec<usize>) -> Option<usize> {
    let mut pos = VecDeque::with_capacity(20);  // ring buffer with positions to checked
    pos.push_back(tmp);                         // push the entrance in
    while pos.len() > 0 {                       // go 'til there is any position to check
        tmp = pos.pop_front()?;                 // fifo: the lasts positions are the farthest 
        for i in 0..6 {                         // there are 6 moves
            match mut_value(d, &tmp, i) {       // check the result
                Some(x) => {
                    if x.len() == 3 { pos.push_back(x); }
                    else { return Some(x[0]); }
                },
                _ => {}
            }
        }
    }
    None
}

fn main() -> Result<(), Error> {
    let mut arr = get_line()?;
    while arr[0] != 0 {
        let mut dun= Vec::new();
        let mut pos = [0, 0, 0];
        for i in 0..arr[0] {
            let mut tmp= Vec::new();
            for j in 0..arr[1] {
                tmp.push(get_input()?.chars().enumerate().map(|(k, chr)| -> isize {
                    match chr {
                        '.' => { -1 },
                        '#' => { -3 },
                        'S' => { pos = [i, j, k]; 0 },
                        _   => { -2 }
                    }
                }).collect::<Vec<isize>>());
            }
            dun.push(tmp);
            get_input()?;
        }
        match solve(&mut dun, pos.to_vec()) {
            Some(x) => { println!("Escaped in {x} minute(s)."); },
            None => { println!("Trapped!"); }
        }
        arr = get_line()?;
    }
    Ok(())
}
