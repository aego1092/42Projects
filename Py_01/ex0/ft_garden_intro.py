#!/usr/bin/env python3
def ft_garden_intro(name: str, height: int, age: int) -> None:
    print(f"=== Welcome to My Garden ===\nPlant: {name}\nHeight: {height}cm")
    print(f"Age: {age} days\n\n=== End of Program ===")


if __name__ == "__main__":
    ft_garden_intro(name="Rose", height=25, age=30)
