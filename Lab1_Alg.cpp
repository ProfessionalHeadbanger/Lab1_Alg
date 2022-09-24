//Написать программу разгадки числового ребуса: СССР = Р^Ф

#include <iostream>
#include <Windows.h>

std::int_fast64_t powint(int base, int exp)
{
    std::int_fast64_t result{ 1 };
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int a[3];
    for (int c = 1; c <= 9; c++)
    {
        for (int p = 1; p <= 9; p++)
        {
            for (int f = 1; f <= 9; f++)
            {
                a[0] = c;
                a[1] = p;
                a[2] = f;
                if (a[0] * 1000 + a[0] * 100 + a[0] * 10 + a[1] == powint(a[1], a[2]))
                {
                    std::cout << "C = " << a[0] << std::endl << "P = " << a[1] << std::endl << "Ф = " << a[2] << std::endl;
                    std::cout << a[0] << a[0] << a[0] << a[1] << " = " << a[1] << "^" << a[2] << std::endl;
                }
            }
        }
    }
}