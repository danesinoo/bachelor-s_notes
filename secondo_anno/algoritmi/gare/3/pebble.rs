include!("std.rs");

fn count_bool(line: &[bool; 12]) -> u8 {
    let mut tmp = 0;
    for i in 0..12 {
        if line[i] { tmp+=1 }
    }
    tmp
}

fn count_moves(line: &[bool; 12]) -> u8 {
    let mut tmp = 0;
    for i in 0..10 {
        if !line[i] && line[i+1] && line[i+2] {
            tmp+=1;
        }
        else if line[i] && line[i+1] && !line[i+2] {
            tmp+=1;
        }
    }
    tmp
}

fn make_move(line: &[bool; 12], muv: u8) -> [bool; 12] {
    let mut tmp = 0;
    let mut copy = [false; 12];
    for i in 0..12 {
        copy[i] = line[i];
    }

    for i in 0..10 {
        if !copy[i] && copy[i+1] && copy[i+2] {
            tmp += 1;
            if tmp == muv {
                copy[i]= true;
                copy[i+1] = false;
                copy[i+2] = false;
                break;
            }
        }
        if copy[i] && copy[i+1] && !copy[i+2] {
            tmp += 1;
            if tmp == muv {
                copy[i] = false;
                copy[i+1] = false;
                copy[i+2] = true;
                break;
            }
        }
    }
//    println!("{:?}", copy);
    copy
}

fn take_off(line: &[bool; 12]) -> u8 {
    let moves = count_moves(line);
    if moves < 1 { return count_bool(line) }
    let mut min = 12;
    let mut tmp: u8;
    for i in 0..moves {
        tmp = take_off(&make_move(line, i+1));
        if tmp < min { min = tmp; }
    }
    min
}

fn main() {
    let size = get_type::<usize>().unwrap();
    let mut line = [false; 12];
    for _ in 0..size {
        let stringa = get_input().unwrap();
        let mut stringa = stringa.chars();
        for i in 0..12 {
            line[i] = match stringa.next() {
                Some('o') => { true },
                _ => { false }
            };
        }
        let ans = take_off(&line);
        println!("{ans}");
    }
}
