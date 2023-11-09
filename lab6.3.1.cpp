#include <iostream>

template <typename T>
int countOddElementsIterative(T arr[], int n) {
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            oddCount++;
        }
    }

    return oddCount;
}

int main() {
    int n;

    std::cout << "розмір масиву: ";
    std::cin >> n;

    
    int* intArray = new int[n];

    
    std::cout << "елементи масиву:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> intArray[i];
    }

    
    int oddCount = countOddElementsIterative(intArray, n);

    
    std::cout << "Кількість непарних елементів у масиві : " << oddCount << std::endl;

    
    delete[] intArray;

    return 0;
}

