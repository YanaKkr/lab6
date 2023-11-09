#include <iostream>


template <typename T>
int countOddElementsRecursive(T arr[], int n, int currentIndex = 0) {
    if (currentIndex == n) {
        return 0;
    }

    int count = 0;
    if (arr[currentIndex] % 2 != 0) {
        count = 1;
    }

    return count + countOddElementsRecursive(arr, n, currentIndex + 1);
}

int main() {
    int n;

    
    std::cout << "розмір масиву: ";
    std::cin >> n;

    
    int* intArray = new int[n];

    
    std::cout << "елементи масиву цілих чисел:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> intArray[i];
    }

    
    int oddCount = countOddElementsRecursive(intArray, n);

    
    std::cout << "Кількість непарних елементів у масиві цілих чисел: " << oddCount << std::endl;

    
    delete[] intArray;

    return 0;
}
