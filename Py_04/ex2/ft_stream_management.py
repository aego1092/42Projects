#!/usr/bin/env python3

import sys
import typing


def ft_ancient_text() -> None:
    if len(sys.argv) == 1:
        print(f"Usage {sys.argv[0]} <filename>")
    elif len(sys.argv) == 2:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{sys.argv[1]}'")
        file_object: typing.Optional[typing.IO[str]] = None
        success: bool = False
        try:
            file_object = open(sys.argv[1], "r")
            try:
                content: str = file_object.read()
                success = True
                print("---\n")
                print(content)
                print("\n---")
            except Exception as e:
                sys.stdout.write(f"[STDERR] Error reading file '{sys.argv[1]}': {e}\n")
        except OSError as e:
            sys.stdout.write(f"[STDERR] Error opening file '{sys.argv[1]}': {e}\n")

        finally:
            if file_object is not None:
                try:
                    file_object.close()
                    print(f"File '{sys.argv[1]}' closed\n")
                except Exception as e:
                    sys.stdout.write(f"[STDERR] Error closing file '{sys.argv[1]}': {e}\n")
        if success:
            ft_archieve_creation(content)

    else:

        print("Retry getting the name of ONE file at a time")


def ft_archieve_creation(content: str) -> None:
    file_object: typing.Optional[typing.IO[str]] = None
    temp_content: str = content
    if temp_content and not temp_content.endswith("\n"):
        temp_content += "\n"
    new_content: str = temp_content.replace("\n", "#\n")

    print("Tranform data:\n---\n")
    print(new_content)
    print("---")

    save_filename: str = input("Enter new file name (or empty): ").strip()
    print("Enter new file name (or empty): ", end="", flush=True)
    save_filename: str = sys.stdin.readline().strip()
    
    save_filename: str = input("Enter new file name (or empty): ").strip()
    if save_filename:
        try:
            file_object = open(save_filename, "w")
            print(f"Saving data to '{save_filename}'")
            try:
                file_object.write(new_content)
                print(f"Data saved in file '{save_filename}'.")
            except Exception as e:
                sys.stdout.write(f"[STDERR] Error writing file '{save_filename}': {e}\n")
        except OSError as e:
            sys.stdout.write(f"[STDERR] Error opening file '{save_filename}': {e}\n")

        finally:
            if file_object is not None:
                try:
                    file_object.close()
                except Exception as e:
                    sys.stdout.write(f"[STDERR] Error closing file '{save_filename}': {e}\n")
    else:
        print("Not saving data.")


if __name__ == "__main__":
    ft_ancient_text()



# import sys, sys.argv, sys.stdin, sys.stdout, sys.stderr, len(),
# open(), import typing, typing.IO, io.read(), io.readline(), io.write(),
# io.flush(), io.close(), print()

# sys.stdin, sys.stdout, sys.stderr,