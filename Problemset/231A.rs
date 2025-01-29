use std::io;

fn read_line() -> String
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main()
{
    let mut ans : i32 = 0;
    let n : i32 = read_line().parse().unwrap();
    for _i in 0..n
    {
        let t = read_line();
        let v = t.split(' ');
        let mut tmp : i32 = 0;
        for s in v
        {
            let val : i32 = s.parse().unwrap();
            if val == 1
            {
                tmp += 1;
            }
        }
        if tmp >= 2
        {
            ans += 1;
        }
    }
    println!("{}", ans);
}