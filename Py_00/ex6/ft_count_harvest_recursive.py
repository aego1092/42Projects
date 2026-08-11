def ft_count_harvest_recursive():
    count_to_harvest = int(input("Days until harvest: "))
    i = 0
    day_by_day = range(1, count_to_harvest + 1, 1)
    ft_count_harvest_recursive_daytrack(day_by_day, i, count_to_harvest)
    print("Day", count_to_harvest)
    print("Harvest time!")


def ft_count_harvest_recursive_daytrack(day_by_day, i, count_to_harvest):
    if day_by_day[i] != count_to_harvest:
        print("Day", day_by_day[i])
        i += 1
        ft_count_harvest_recursive_daytrack(day_by_day, i, count_to_harvest)
