#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Input(int** a, const int n);
void Print(int** a, const int n);
void Part1_FindK(int** a, const int n);
int Part2_SumNegativeRows(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Input(a, n);
    Print(a, n);

    Part1_FindK(a, n);

    int sum = Part2_SumNegativeRows(a, n);
    cout << "Sum of rows with negative elements: " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Part1_FindK(int** a, const int n)
{
    cout << "k values where row k equals column k:" << endl;
    bool found = false;

    for (int k = 0; k < n; k++)
    {
        bool equal = true;
        for (int i = 0; i < n; i++)
        {
            if (a[k][i] != a[i][k])
            {
                equal = false;
                break;
            }
        }
        if (equal)
        {
            cout << k << " ";
            found = true;
        }
    }

    if (!found)
        cout << "No such k found";
    cout << endl;
}

int Part2_SumNegativeRows(int** a, const int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        bool hasNegative = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }

        if (hasNegative)
        {
            for (int j = 0; j < n; j++)
                sum += a[i][j];
        }
    }

    return sum;
}
