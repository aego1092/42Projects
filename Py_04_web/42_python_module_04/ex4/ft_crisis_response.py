#!/usr/bin/python3

files = [
    'lost_archive.txt',
    'classified_vault.txt',
    'standard_archive.txt'
    ]

print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===\n")

for file_name in files:
    try:
        print(f"CRISIS ALERT: Attempting access to '{file_name}'...")
        with open(file_name, 'r') as file:
            content = file.read()
            print(f"SUCCESS: Archive recovered - ''{content}''")
            status = "Normal operations resumed"
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
        status = "Crisis handled, system stable"
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
        status = "Crisis handled, security maintained"
    except Exception as e:
        print(f"RESPONSE: Error {e}")
        status = "Crisis handled, aborting"
    finally:
        print(f"STATUS: {status}\n")

print("All crisis scenarios handled successfully. Archives secure.")
