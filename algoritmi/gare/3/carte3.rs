use std::collections::HashMap;
include!("std.rs");

/*
fn fact(n: usize) -> usize {
    if n<2 { return 1; }
    n * fact(n-1)
}

fn init_hash(arr: &Vec<usize>) -> HashMap<&usize, usize> {
    let mut freq = HashMap::new();
    arr.into_iter().map(|elm| {
        if let Some(x) = freq.get_mut(&elm) {
            *x += 1;
        }
        else { freq.insert(elm, 1); }
    }).count();
    freq
}
*/

fn livella(tmp: &mut Vec<usize>, i: usize) -> bool {
    tmp[i] -=1;
    let mut aux = 1;
    let mut j = i+1;
    while (j < tmp.len() && tmp[j] > tmp[i]) {
        tmp[j] -= 1;
        aux += 1;
        j+=1
    }
    while (j < tmp.len() && aux!=0) {
        while aux!=0 && tmp[j] < tmp[i] {
            tmp[j] +=1;
            aux -= 1;
        }
        j+=1
    }
    aux == 0
}

/*
fn conta_init(f: &HashMap<&usize, usize>) {
    let mut prod= 1;
    let n = f.iter().map(|(_key, val)| {
        prod *= fact(*val);
        val
    }).count();
    fact(n)/prod
}
*/

fn metodo(mut tmp: Vec<usize>, i: usize) {
//    let mut ans = 0;
//    if 1==tmp.len()-i { ans += conta(&tmp); }
    if 1==tmp.len()-i { println!("{:?}", tmp); }
    else {
        metodo(tmp.clone(), i+1);
        while livella(&mut tmp, i) {
            metodo(tmp.clone(), i+1);
        }
    }
//    ans
}

/*
fn conta1(arr: &Vec<usize>) -> usize {
    if arr[2] == 0 { return 1; }
    else if arr[2] < arr[1] { 
        return binomio(arr); 
    }
    else if arr[0] == 0 || (arr[1]-1) * arr[0] < arr[2] { return 0; }
    let mut ans = 0;
    for i in 0..arr[1] {
        if arr[2] >= i {
            ans += conta(&vec![arr[0] -1, arr[1], arr[2] - i]);
        }
    }
    return ans;
}
*/

fn main() {
    let mut arr= get_line::<usize>().unwrap();
    let f = arr[2];
    {
        arr[2] -= arr[0];
        arr[1] -= 1;
        //let flag: u8 = arr[2] % arr[0] == 0;

        let mut tmp = vec![1; arr[0]];
        for i in &mut tmp {
            if arr[2] > arr[1] {
                *i += arr[1];
                arr[2] -= arr[1];
            }
            else if arr[2] > 0 {
                *i += arr[2];
                arr[2] = 0;
            }
        }
        metodo(tmp, 0);
    }
    println!("n: {} k:{} t:{}", arr[0], arr[1]+1, f);
}
