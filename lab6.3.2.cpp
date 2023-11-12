#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* Create(int n, const int Low, const int High, int* a = nullptr, int i = 0) {
    if (a == nullptr)
    {
        a = new int[n];
    }

    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(n, Low, High, a, i + 1);
    }

    return a;
}

template<typename T>
T* CreateU(int n, const T Low, const T High, T* a = nullptr, int i = 0)
{
    if (a == nullptr)
    {
        a = new T[n];
    }

    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        CreateU(n, Low, High, a, i + 1);
    }

    return a;
}

void Print(int* a, int n, int i = 0)
{
    if (i < n)
    {
        if (i == n - 1) cout << setw(5) << a[i];
        else cout << a[i] << "," << setw(5);
        Print(a, n, i + 1);
    }
    else
    {
        cout << endl;
    }
}

template<typename T>
void PrintU(T* a, T n, int i = 0)
{
    if (i < n)
    {
        if (i == n - 1) cout << setw(5) << a[i];
        else cout << a[i] << "," << setw(5);
        PrintU(a, n, i + 1);
    }
    else
    {
        cout << endl;
    }
}

int count_odd_elements_r(int* array, int size, int index = 0) {
    if (index == size) {
        return 0;
    }
    int count = (array[index] % 2 != 0) + count_odd_elements_r(array, size, index + 1);

    return count;
}

template<typename T>
T count_odd_elements_rU(T* array, T size, int index = 0) {
    if (index == size) {
        return 0;
    }

    T count = (array[index] % 2 != 0) + count_odd_elements_rU(array, size, index + 1);

    return count;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    const int n = 10;
    int High = 15;
    int Low = -15;
    int* a = Create(n, Low, High);
    int* b = CreateU(n, Low, High);
    Print(a, n);
    PrintU(b, n);

    int oddCountA = count_odd_elements_r(a, n);
    int oddCountB = count_odd_elements_rU(b, n);

    cout << "Number of odd elements in array a: " << oddCountA << endl;
    cout << "Number of odd elements in array b: " << oddCountB << endl;

    delete[] a;
    delete[] b;
    return 0;
}
