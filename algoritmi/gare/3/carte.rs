use std::cmp::{max, min};
include!("std.rs");

type Num = u128;

fn fact(n: Num, fine: Num) -> Num {
    if n > fine { n * fact(n-1, fine)%1000000009 }
    else { 1 }
}

fn binomio(up: Num, down: Num) -> Num {
    fact(up, max(up-down, down)) / fact(min(up-down, down), 1)
}

fn main() {
    let mut arr = get_line::<Num>().unwrap();
    arr[2] -= arr[0];
    
    //let up: Num = arr[2] / arr[1];
    // massimo Numero di colonne più alte di k che si riescono a formare

    let mut ans = 1;
    ans *= binomio(arr[0]/2 + arr[0] -1, arr[0]-1);
    ans *= binomio(arr[0]/2 + arr[0] % 2 + arr[0] -1, arr[0]-1);
    println!("{}", ans);
}




/*
 * Come il programma uno esegue cicli for per calcolare le seguenze
 * si crea una funzione ricorsiva che dagli stessi parametri del ciclo
 * for genera la seguenza (n, k, t) e nessun altro!
 * quando viene trovata una sequenza sono calcolate anche le permutazioni possibili
 * ma questo come nell'altro programma (?) 
 *
 *      o da questo momento si ricomincia a contare come il secondo programma
 *
 *      oppure si tenta di generalizzare la formula del primo programma
 *
 *  Da fare in sostanza: rendere ricorsivo il programma iterativo!
 *  E trovare un modo simpatico per contare le sequenze a questo punto.
 */
