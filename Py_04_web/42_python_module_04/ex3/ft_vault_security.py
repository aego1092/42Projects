#!/usr/bin/python


print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===\n")

print("Initiating secure vault access...")
filename = "classified_data.txt"
error = False
try:
    with open(filename, 'r') as file:
        print("Vault connection established with failsafe protocols\n")
        print("SECURE EXTRACTION:")
        for line in file:
            print(line, end="")
        print("\n")
except Exception as e:
    print(f"\033[0;31m🟥 ERROR: Storage vault not found: {e}\033[0;37m")
    error = True

filename = "security_protocols.txt"
try:
    with open(filename, 'w') as file:
        print("SECURE PRESERVATION:")
        data = "[CLASSIFIED] New security protocols archived"
        file.write(data)
        print(data)
        print("Vault automatically sealed upon completion\n")
except Exception as e:
    print(f"\033[0;31m🟥 ERROR: Storage vault not found: {e}\033[0;37m")
    error = True

if not (error):
    print("All vault operations completed with maximum security.")
