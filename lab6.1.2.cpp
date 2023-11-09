#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


void Generate(int c[], int i = 0) {
    if (i == 25) {
        return;
    }
    c[i] = rand() % (90 - 5 + 1) + (5);
    Generate(c, i + 1);
}

void Print(int c[], int i = 0) {
    if (i == 0) {
        cout << " c(25) = { ";
    }
    if (i == 25) {
        cout << " }" << endl;
        return;
    }
    cout << setw(4) << c[i] << " ";
    Print(c, i + 1);
}

int Count(int c[], int i = 0) {
    if (i >= 25) {
        return 0;
    }
    int count = Count(c, i + 1);
    if (c[i] % 2 == 0 || i % 8 == 0) {
        count++;
    }
    return count;
}

int Sum(int c[], int i = 0) {
    if (i >= 24) {
        return 0;
    }
    int sum = Sum(c, i + 1);
    if (c[i] % 2 == 0 || i % 8 == 0) {
        sum += c[i];
        c[i] = 0;
    }
    return sum;
}

int main() {
    srand(time(0));
    int c[24];
    Generate(c);
    Print(c);

    int count = Count(c);
    int sum = Sum(c);

    cout << "count = " << count << ", sum = " << sum << endl;
    Print(c);

    return 0;
}