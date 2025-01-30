use std::io;

fn read_line() -> String
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main()
{
    let line = read_line();
    let st : Vec<&str> = line.split_whitespace().collect();
    let m : i32 = st[0].parse().unwrap();
    let n : i32 = st[1].parse().unwrap();
    println!("{}", m * n / 2);
}