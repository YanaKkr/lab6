#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* Create(int n, const int Low, const int High)
{
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
    return a;
}

template<typename T>
T* CreateU(int n, const T Low, const T High)
{
    T* a = new T[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
    return a;
}

void Print(int* a, int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) cout << setw(5) << a[i];
        else cout << a[i] << "," << setw(5);
    }
    cout << endl;
}

template<typename T>
void PrintU(T* a, int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) cout << setw(5) << a[i];
        else cout << a[i] << "," << setw(5);
    }
    cout << endl;
}

int count_odd_elements(int* array, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

template<typename T>
T count_odd_elementsU(T* array, T size) {
    T count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 10;
    int High = 15;
    int Low = -15;
    int* a = Create(n, Low, High);
    int* b = CreateU(n, Low, High);
    Print(a, n);
    PrintU(b, n);

    int odd_elements = count_odd_elements(a, n);
    int odd_elementsU = count_odd_elementsU(b, n);

    cout << "Count of odd elements (a): " << odd_elements << endl;
    cout << "Count of odd elements (b): " << odd_elementsU << endl;

    delete[] a;
    delete[] b;
    return 0;
}
