use std::io;

fn main() {
    let mut input = String::new();

    loop {
        match io::stdin().read_line(&mut input) {
            Ok(_n) => {
                if input.is_empty() { break; }

                if  input.chars().next().unwrap() == '#' {
                    //This is a status line of text, and
                    //should be passed down the pipeline with
                    //the pound-sign stripped off
                    input.remove(0);
                } else if input.chars().next().unwrap() == '%' {
                    //This is a value to display
                    if input.len() > 1 {
                        let value_type = input.chars().nth(1).unwrap();
                        input = input.replace(|c: char| !c.is_numeric(), "");

                        match value_type {
                            'a' => println!("Altitude: {}", input),
                            'f' => println!("Fuel remaining: {}", input),
                            'v' => println!("Current Velocity: {}", input),
                            't' => println!("Time elapsed: {}", input),
                            _ => {}
                        }
                    }
                }
                input.clear();
            }
            Err(error) => {
                println!("error: {}", error);
                return;
            }
        }
    }
}
