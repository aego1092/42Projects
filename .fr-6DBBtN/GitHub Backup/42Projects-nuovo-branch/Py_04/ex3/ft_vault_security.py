#!/usr/bin/env python3


def secure_archive(
        file_name: str,
        action: str = "r",
        arg_content: str = ""
        ) -> tuple[bool, str]:
    success: bool = False
    t: tuple[bool, str]
    try:
        if action == "r":
            with open(file_name, action) as file_object:
                content: str = file_object.read()
                success = True
                t = (success, content)
                return t
        elif action == "w":
            with open(file_name, action) as file_object:
                file_object.write(arg_content)
                success = True
                disclaimer: str = 'Content successfully written to file'
                t = (success, disclaimer)
                return t
        else:
            t = (success, f"Unknown action: '{action}'")
            return t
    except OSError as e:
        t = (success, str(e))
        return t


def ft_vault_security() -> None:
    print("=== Cyber Archives Security ===")
    # Case 1
    print("\nUsing 'secure_archive' to read from a nonexistent file:")
    t = secure_archive("/not/existing/file", "r", "")
    print(t)
    # Case 2
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    t = secure_archive("/etc/shadow", "r", "")
    print(t)
    # secure_archive("/etc/master.passwd", "r", "")
    # Case 3
    print("\nUsing 'secure_archive' to read from a regular file:")
    regular_file_t = secure_archive("ancient_fragment.txt")
    success_extract = regular_file_t[0]
    data = regular_file_t[1]
    print(regular_file_t)
    # Case 4
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    if success_extract:
        print(secure_archive("new_fragment.txt", "w", data))
    else:
        print((False, "Previous read failed"))

    # t = secure_archive("newfile.txt", "w", data)
    # print(t)


if __name__ == "__main__":
    ft_vault_security()
