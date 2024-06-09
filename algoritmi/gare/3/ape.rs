include!("std.rs");

fn passi(passo: usize, pos: &[usize; 6]) -> usize {
    return 0;
}
// si tratta di una successione: basta trovare il caso base 
// e come cambia n rispetto ad esso

fn main() {
    let iterations: usize= get_type().unwrap();
    let mut tmp;
    let mut pos: [usize; 6];
    for _ in 0..interations {
        tmp = get_type::<usize>().unwrap();
        for i in 0..6 {
            pos[i] = 0;
        }
        println!("{}", passi(tmp, pos));
    }
}

