use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n : i32 = input.trim().parse().unwrap();
    while n > 0
    {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let s = input.trim();
        let len = s.len();
        if len <= 10
        {
            println!("{}", s);
        }
        else
        {
            println!("{}{}{}", s.chars().nth(0).unwrap(), len - 2, s.chars().nth(len-1).unwrap());
        }
        n -= 1;
    }
}