#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Generate(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() %201 - 100;
    }
}

void Print(int a[], int n) {
    for (int i = 0; i < n ; i++) {
        cout << setw(4) << a[i] << " ";
    }
}

void findMinMaxIndices(int a[], int n, int& minIndex, int& maxIndex) {
    if (n <= 0) {
        minIndex = -1;
        maxIndex = -1;
    }
    int minElement = a[0];
    int maxElement = a[0];
    minIndex = 0;
    maxIndex = 0;
        

        for (int i = 1; i < n; i++) {
            if (a[i] < minElement) {
                minElement = a[i];
                minIndex = i;
            }
            if (a[i] > maxElement) {
                maxElement = a[i];
                maxIndex = i;
            }
        }
    }
int main() {
    int a[] = {12, 3, 5, 78, 34, 54, 65 };
    int n = sizeof(a) / sizeof(a[0]);

    int minIndex, maxIndex;
    findMinMaxIndices(a, n, minIndex, maxIndex);

    if (minIndex != -1 && maxIndex != -1) {
        std::cout << "MinIndex =  " << minIndex << std::endl;
        std::cout << "MaxIndex =  " << maxIndex << std::endl;
    }
}
