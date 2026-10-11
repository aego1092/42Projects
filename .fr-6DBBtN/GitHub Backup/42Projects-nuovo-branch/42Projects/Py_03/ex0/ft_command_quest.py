import sys


def ft_command_quest() -> None:
    """Iterate and print the argv"""
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")

    if len(sys.argv) == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {len(sys.argv)-1}")
        # # C-style
        # for i in range(1, len(sys.argv)):
        #     print(f"Argument {i}: {sys.argv[i]}")

        # i: int = 1
        # while i < len(sys.argv):
        #     print(f"Argument {i}: {sys.argv[i]}")
        #     i += 1

        # P-style
        # i: int = 0
        # for arg in sys.argv[1:]:
        #     i += 1
        #     print(f"Argument {i}: {arg}")
        for i, arg in enumerate(sys.argv):  # unpack tuple at call
            if i > 0:
                print(f"Argument {i}: {arg}")
                print(type(i))
                print(type(arg))

    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    ft_command_quest()
