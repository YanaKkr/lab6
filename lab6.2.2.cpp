#include <iostream>

void findMinMaxIndicesRecursive(int arr[], int n, int currentIndex, int& minIndex, int& maxIndex) {
    if (currentIndex == n) {
        return;
    }

    if (arr[currentIndex] < arr[minIndex]) {
        minIndex = currentIndex;
    }

    if (arr[currentIndex] > arr[maxIndex]) {
        maxIndex = currentIndex;
    }

    findMinMaxIndicesRecursive(arr, n, currentIndex + 1, minIndex, maxIndex);
}

int main() {
    int n;

    
    std::cout << "розмір масиву: ";
    std::cin >> n;

    int* arr = new int[n];

    
    std::cout << "елементи масиву:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }

    
    int minIndex = 0;
    int maxIndex = 0;

    
    findMinMaxIndicesRecursive(arr, n, 0, minIndex, maxIndex);

    
    std::cout << "Індекс найменшого елементу: " << minIndex << std::endl;
    std::cout << "Індекс найбільшого елементу: " << maxIndex << std::endl;

    
    delete[] arr;

    return 0;
}
