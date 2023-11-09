#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void Generate(int c[]) 
{
    for (int i = 0; i < 25; i++) 
    {
        c[i] = rand() % (90 - 5 + 1) + 5;
    }
}

void Print(int c[]) 
{
    for (int i = 0; i < 25; i++) 
    {
        cout << setw(4)<< c[i] << " ";
    }
    cout << endl;
}

int Count(int c[]) 
{
    int count = 0;
    for (int i = 0; i < 25; i++) 
    {
        if (c[i] % 2 == 0 || !i % 8 == 0) 
        {
            count++;
        }
    }
    return count;
}

int Sum(int c[])
 {
    int sum = 0;
    for (int i = 0; i < 25; i++) 
    {
        if (c[i] % 2 == 0 || !i % 8 == 0) 
        {
            sum += c[i];
            c[i] = 0;
        }
    }
    return sum;
}

int main() 
{
    srand(time(0));
    int c[25];
    Generate(c);
    Print(c);
    int count = Count(c);
    int sum = Sum(c);
    cout << "count = " << count << " sum = " << sum << endl;
    Print(c);
    return 0;
}