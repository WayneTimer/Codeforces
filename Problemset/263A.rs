use std::io;
use std::convert::TryInto;

fn read_line() -> String
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main()
{
    for i in 0..5
    {
        let line = read_line();
        let row : Vec<&str> = line.split_whitespace().collect();
        for j in 0..5
        {
            let num : i32 = row[j].parse().unwrap();
            if num == 1
            {
                println!("{}", 2i32.abs_diff(j.try_into().unwrap()) + 2i32.abs_diff(i.try_into().unwrap()));
                break;
            }
        }
    }
}
