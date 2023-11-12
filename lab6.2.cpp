#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
int* create(int n, const int Low, const int High, int* a = 0, int i = 0)
{
    if (a == 0)
    {
        a = new int[n];
    }

    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        create(n, Low, High, a, i + 1);
    }

    return a;
}

int Max(int* a, const int size, int i, int max)
{
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}

int Min(int* a, const int size, int i, int min)
{
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}
int MaxIndex(int* a, const int size, int i, int maxIndex)
{
    if (a[i] > a[maxIndex])
        maxIndex = i;
    if (i < size - 1)
        return MaxIndex(a, size, i + 1, maxIndex);
    else
        return maxIndex;
}

int MinIndex(int* a, const int size, int i, int minIndex)
{
    if (a[i] < a[minIndex])
        minIndex = i;
    if (i < size - 1)
        return MinIndex(a, size, i + 1, minIndex);
    else
        return minIndex;
}

void print(int* a, int n, int i = 0) {
    if (i < n) {
        cout << setw(5) << a[i];
        print(a, n, i + 1);
    }
    else {
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    srand(static_cast<unsigned>(time(NULL)));
    int Low = 1;
    int High = 100;

    int* a = create(n, Low, High);
    print(a, n);

    cout << "MaxIndex = " << MaxIndex(a, n, 0, 0) << endl;
    cout << "MinIndex = " << MinIndex(a, n, 0, 0) << endl;
    cout << "Max = " << Max(a, n, 0, a[0]) << endl;
    cout << "Min = " << Min(a, n, 0, a[0]) << endl;

    delete[] a; // Звільнення пам'яті

    return 0;
}
