impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut out: Vec<String> = Vec::with_capacity(n as usize);
        for i in 1usize..(n+1) as usize {
            if (i % 15) == 0 {
                out.push(String::from("FizzBuzz"));
            } else if (i % 5) == 0 {
                out.push(String::from("Buzz"));
            } else if (i % 3) == 0 {
                out.push(String::from("Fizz"));
            } else {
                out.push(i.to_string());
            }
        }
        return out;
    }
}

