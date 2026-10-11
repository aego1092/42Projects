import sys

"""
This program reads the list of recived
command-line parameters
"""


def main() -> None:
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    n = len(sys.argv)
    if n == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {n-1}")
        i = 1
        while i < n:
            print(f"Argument {i}: {sys.argv[i]}")
            i += 1
    print(f"Total arguments: {n}")


if __name__ == "__main__":
    main()
