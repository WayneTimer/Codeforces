use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let weight : i32 = input.trim().parse().unwrap();
    if (weight % 2 == 0) && (weight > 3)
    {
        println!("YES");
    }
    else
    {
        println!("NO");
    }
}