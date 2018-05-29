def func1(number):
    while(True):
        print(number % 10)
        number = number / 10
        if (number == 0): break;

a = 10203040506070809
func1(a)
