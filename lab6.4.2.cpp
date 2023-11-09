#include <iostream>
#include <cmath>

int findMaxByAbsoluteValueIndexRecursive(double arr[], int n, int currentIndex = 0, int maxIndex = 0, double maxAbsValue = 0) {
    if (currentIndex >= n) {
        return maxIndex;
    }

    double absValue = std::abs(arr[currentIndex]);
    if (absValue > maxAbsValue) {
        maxAbsValue = absValue;
        maxIndex = currentIndex;
    }

    return findMaxByAbsoluteValueIndexRecursive(arr, n, currentIndex + 1, maxIndex, maxAbsValue);
}

double calculateSumAfterFirstPositiveRecursive(double arr[], int n, int currentIndex = 0, bool foundFirstPositive = false, double sum = 0) {
    if (currentIndex >= n) {
        return sum;
    }

    if (foundFirstPositive) {
        sum += arr[currentIndex];
    } else if (arr[currentIndex] > 0) {
        foundFirstPositive = true;
    }

    return calculateSumAfterFirstPositiveRecursive(arr, n, currentIndex + 1, foundFirstPositive, sum);
}

void rearrangeArrayRecursive(double arr[], int n, double a, double b, int currentIndex = 0) {
    if (currentIndex >= n) {
        return;
    }

    if (arr[currentIndex] < a || arr[currentIndex] > b) {
        int nextIndex = currentIndex + 1;
        while (nextIndex < n && (arr[nextIndex] < a || arr[nextIndex] > b)) {
            nextIndex++;
        }

        if (nextIndex < n) {
            std::swap(arr[currentIndex], arr[nextIndex]);
        }
    }

    rearrangeArrayRecursive(arr, n, a, b, currentIndex + 1);
}

int main() {
    int n;
    double a, b;


    std::cout << " розмір масиву: ";
    std::cin >> n;
    std::cout << " a= ";
    std::cin >> a;
    std::cout << "b= ";
    std::cin >> b;

    double* arr = new double[n];

    
    std::cout << " елементи масиву:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }

    
    int maxIndex = findMaxByAbsoluteValueIndexRecursive(arr, n);
    std::cout << "Номер максимального за модулем елементу: " << maxIndex << std::endl;

    
    double sum = calculateSumAfterFirstPositiveRecursive(arr, n);
    std::cout << "Сума елементів після першого додатного елементу: " << sum << std::endl;

    
    rearrangeArrayRecursive(arr, n, a, b);

    
    std::cout << "" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    delete[] arr;

    return 0;
}

    