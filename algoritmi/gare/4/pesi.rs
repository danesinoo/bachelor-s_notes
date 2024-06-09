use std::collections::{HashMap, VecDeque};
include!("stl.rs");
type Num = usize;

fn change(a: &mut Vec<usize>, w: &HashMap<(Num, Num), Num>, n: Num, m: Num) -> bool {
    match w.get(&(n, m)) {
        Some(x) => {
            if *x +a[n] < a[m] {
                a[m] = *x + a[n];
                return true;
            }
        }
        None => {}
    }
    false
}

fn solve(a: &mut Vec<usize>, ls: &HashMap<Num, Vec<Num>>, w: &HashMap<(Num, Num), Num>, mut tmp: Num) {
    let mut c = VecDeque::with_capacity(20);
    c.push_back(tmp);
    while c.len() > 0 {
        tmp = c.pop_front().unwrap();
        match ls.get(&tmp) {
            Some(l) => {
                for i in l {
                    if change(a, w, tmp, *i) { c.push_back(*i); println!("{:?}", a); }
                }
            },
            None => {}
        };
    }
}

fn main() -> Result<(), Error> {
    let mut arr = get_line::<Num>()?;
    while arr[0] != 0 {
        let mut tmp;
        let mut pesi= HashMap::new();
        let mut links: HashMap<Num, Vec<Num>> = HashMap::new();
        for _ in 0..arr[1] {
            tmp = get_line::<Num>()?;
            match pesi.get(&(tmp[0], tmp[1])) {
                Some(x) => {
                    if x > &tmp[2] {
                        pesi.insert((tmp[0], tmp[1]), tmp[2]);
                    }
                },
                None => { pesi.insert((tmp[0], tmp[1]), tmp[2]); }
            };
            match links.remove(&tmp[0]) {
                Some(mut x) => {
                    x.push(tmp[1]);
                    links.insert(tmp[0], x);
                },
                None => {
                    links.insert(tmp[0], vec![tmp[1]]);
                }
            };
        }
        tmp = Vec::new();
        for _ in 0..arr[2] {
            tmp.push(get_type::<Num>()?);
        }
        let mut ans = vec![usize::MAX; arr[0]];
        ans[arr[3]] = 0;
        println!("{:?}", pesi);
        println!("{:?}", links);
        solve(&mut ans, &links, &pesi, arr[3]);
        for i in tmp {
            match ans[i] {
                usize::MAX => { println!("Impossible"); }
                a => { println!("{a}"); },
            }
        }
        arr = get_line()?;
    }
    Ok(())
}

/* 
 * i got a graph
 *
 * I use Djkstra, how?
 *
 * arco -> tupla (nodo minore, nodo maggiore) 
 * hashmap dei pesi: (nodo minore, nodo maggiore) -> peso
 * due array di dimensione n-1: prec e act
 * prec rappresenta i percorsi migliori da s fino a al nodo in questione
 * rappresentato con l'indice in e mosse
 * act-> percorso migliore in e+1 mosse
 */
