#include <iostream>
#include <cmath>

int findMaxByAbsoluteValueIndex(double arr[], int n) {
    int maxIndex = 0;
    double maxAbsValue = std::abs(arr[0]);

    for (int i = 1; i < n; i++) {
        double absValue = std::abs(arr[i]);
        if (absValue > maxAbsValue) {
            maxAbsValue = absValue;
            maxIndex = i;
        }
    }

    return maxIndex;
}

double calculateSumAfterFirstPositive(double arr[], int n) {
    bool foundFirstPositive = false;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        if (foundFirstPositive) {
            sum += arr[i];
        } else if (arr[i] > 0) {
            foundFirstPositive = true;
        }
    }

    return sum;
}

void rearrangeArray(double arr[], int n, double a, double b) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        while (left < n && (arr[left] >= a && arr[left] <= b)) {
            left++;
        }
        while (right >= 0 && (arr[right] < a || arr[right] > b)) {
            right--;
        }

        if (left < right) {
            std::swap(arr[left], arr[right]);
        }
    }
}

int main() {
    int n;
    double a, b;

    std::cout << "розмір масиву: ";
    std::cin >> n;
    std::cout << " a= ";
    std::cin >> a;
    std::cout << " b=  ";
    std::cin >> b;

    double* arr = new double[n];

    std::cout << "Елементи масиву:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Елемент " << i << ": ";
        std::cin >> arr[i];
    }

    int maxIndex = findMaxByAbsoluteValueIndex(arr, n);
    std::cout << "Номер максимального елементу: " << maxIndex << std::endl;

    
    double sum = calculateSumAfterFirstPositive(arr, n);
    std::cout << "Сума елементів після першого додатного елементу: " << sum << std::endl;


    rearrangeArray(arr, n, a, b);

    std::cout << " " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
