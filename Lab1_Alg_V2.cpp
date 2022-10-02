//Написать программу разгадки числового ребуса: СССР = Р^Ф

#include <iostream>
#include <Windows.h>

int Razm_BP(int test, int p)
{
    int a;
    int i;
    if (p == 1)
    {
        return 1;
    }
    else
    {
        a = p;
        i = 1;
        while (a < test)
        {
            a *= p;
            i++;
        }
        if (a == test)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int test;
    int r;

    for (int c = 1; c <= 9; c++)
    {
        for (int p = 1; p <= 9; p++)
        {
            if (p != c)
            {
                test = 1110 * c + p;
                r = Razm_BP(test, p);
                if (r >= 2 && r <= 9)
                {
                    std::cout << test << " = " << p << "^" << r << std::endl;
                }
            }
        }
    }
}
