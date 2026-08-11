def ft_water_reminder():
    time_question = int(input("Days since the last watering: "))
    if time_question > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
