use std::collections::HashMap;
include!("std.rs");

fn max_rep(nums: &Vec<usize>) -> usize {
    if nums.len()==0 { return 0; }
    let mut index = HashMap::new();
    let mut l: usize = 0;
    let mut count: usize = 0;
    for r in 0..nums.len() {
        if !index.contains_key(&nums[r]) || index.get(&nums[r]).unwrap() < &l {
            index.insert(&nums[r], r+1);
            count = if count < r-l { r-l } else { count };
        }
        else {
            l = if index[&nums[r]] > l { index[&nums[r]] } else { l };
            index.insert(&nums[r], r+1);
        }
    }
    count+1
}


fn main() {
    let samples= get_type::<isize>().unwrap();
    for _j in 0..samples {
        let size = get_type::<usize>().unwrap();
        let mut nums = vec![0 as usize; size];
        for i in 0..size {
            nums[i] = get_type().unwrap();
        }
        println!("{}", max_rep(&nums));
    }

}    
