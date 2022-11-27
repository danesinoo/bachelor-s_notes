use std::ops::{AddAssign, SubAssign, Sub};

fn right(index: usize) -> usize {
    index *2 + 1
}

fn left(index: usize) -> usize {
    index * 2
}

enum Dir {
    N,
    L,
    R
}

// Mi piacerebbe togliere il codice ripetuto, ma dovrei fare unsafe e non lo preferirei
pub fn max_heapify<T>(a: &mut [T], i: usize)
    where T: PartialOrd+Clone+AddAssign+SubAssign+Sub<Output=T>,
{
    let mut f = Dir::N;
    if left(i) < a.len() && a[i] < a[left(i)] {
        a[left(i)]+=a[i].clone();
        a[i]=a[left(i)].clone()-a[i].clone();
        a[left(i)]-=a[i].clone();
        f=Dir::L;
    }
    if right(i) < a.len() && a[i] < a[right(i)] {
        a[right(i)]+=a[i].clone();
        a[i]=a[right(i)].clone()-a[i].clone();
        a[right(i)]-=a[i].clone();
        f=Dir::R;
    }
    match f {
        Dir::N => {},
        Dir::L => { max_heapify(a, left(i)); },
        Dir::R => { max_heapify(a, right(i)); }
    };
}

pub fn build_max_heap<T>(a: &mut [T])
    where T: PartialOrd+Clone+AddAssign+SubAssign+Sub<Output=T>+std::fmt::Debug,
{
    let mut i = a.len()/2+1;
    loop {
        i -= 1;
        max_heapify(a, i);
        if i==0 { break; }
    }
}

pub fn heap_sort<T>(a: &mut [T])
    where T: PartialOrd+Clone+AddAssign+SubAssign+Sub<Output=T>+std::fmt::Debug,
{
    build_max_heap(a);
    let mut i=a.len()-1;
    loop {
        a[i]+=a[0].clone();
        a[0]=a[i].clone()-a[0].clone();
        a[i]-=a[0].clone();
        if i==2 { break; }
        i-=1;
        max_heapify(&mut a[0..i], 0);
    }
}


#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn heap_sort_works() {
        let mut tmp: Vec<_>= Vec::new();
        for i in 0..5 {
            tmp.push(4-i);
        }
        tmp[4] = 79;
        tmp[1] = -1;
        heap_sort(&mut tmp);
        assert_eq!(vec![-1, 1, 2, 4, 79], tmp);
    }
}
