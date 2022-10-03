//Написать программу разгадки числового ребуса: СССР = Р^Ф

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int_fast64_t powint(int base, int exp)
{
    int_fast64_t result{ 1 };
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

bool Check(int c, int p, int f)
{
    if (1110 * c + p == powint(p, f))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Razm_BP(int n, int m, bool *used, int *result, int pos = 0)
{
    if (pos == m)
    {
        if (Check(result[0], result[1], result[2]))
        {
            cout << result[0] << result[0] << result[0] << result[1] << " = " << result[1] << "^" << result[2] << endl;
        }
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i])
            {
                used[i] = false;
                result[pos] = i + 1;
                Razm_BP(n, m, used, result, pos + 1);
                used[i] = true;
            }
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 9;
    int m = 3;
    bool* used = new bool[n];
    int* result = new int[m];
    Razm_BP(n, m, used, result);
}
