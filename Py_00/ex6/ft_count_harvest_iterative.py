def ft_count_harvest_iterative():
    count_to_harvest = int(input("Days until harvest: "))
    day_count = 1
    for i in range(day_count, count_to_harvest + 1, 1):
        print("Day", i)
    print("Harvest time!")
