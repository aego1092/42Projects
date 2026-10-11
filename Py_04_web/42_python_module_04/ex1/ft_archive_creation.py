#!/usr/bin/python3

print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n")

print("Analyzing new storage unit: new_discovery.txt")
file = "new_discovery.txt"
try:
    f = open(file, "w")
    print("Storage unit created successfully...")
    data = "[ENTRY 001] New quantum algorithm discovered\n"
    data_two = "[ENTRY 002] Efficiency increased by 347%\n"
    data_three = "[ENTRY 003] Archived by Data Archivist trainee\n"
    f.write(data)
    f.write(data_two)
    f.write(data_three)
    print("Data inscription complete. Storage unit sealed")
    print("Archive 'new_discovery.txt' ready for long-term preservation.")
    f.close()
except Exception as e:
    print("An error occured while writing the archive:", e)
