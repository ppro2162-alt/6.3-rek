#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ---------- Виведення масиву ----------
void PrintArray(const int* a, const int size, int i);
template <typename T>
void PrintArray(const T* a, const int size, int i);

// ---------- Обмін двох елементів ----------
void SwapElements(int& x, int& y);
template <typename T>
void SwapElements(T& x, T& y);

// ---------- Пошук індексу максимального елемента ----------
int FindMaxIndex(const int* a, const int size, int i, int maxIndex);
template <typename T>
int FindMaxIndex(const T* a, const int size, int i, int maxIndex);

// ---------- Впорядкування за незростанням ----------
void SortNonIncreasing(int* a, const int size, int i);
template <typename T>
void SortNonIncreasing(T* a, const int size, int i);

int main()
{
    const int n = 10;

    int a[n] = { 3, 9, 1, 7, 5, 10, 2, 8, 4, 6 };
    cout << "Before (int):    ";
    PrintArray(a, n, 0);
    cout << endl;
    SortNonIncreasing(a, n, 0);
    cout << "After  (int):    ";
    PrintArray(a, n, 0);
    cout << endl << endl;

    int a2[n] = { 3, 9, 1, 7, 5, 10, 2, 8, 4, 6 };
    cout << "Before (T=int):  ";
    PrintArray<int>(a2, n, 0);
    cout << endl;
    SortNonIncreasing<int>(a2, n, 0);
    cout << "After  (T=int):  ";
    PrintArray<int>(a2, n, 0);
    cout << endl << endl;

    double b[n] = { 3.3, 9.9, 1.1, 7.7, 5.5, 10.0, 2.2, 8.8, 4.4, 6.6 };
    cout << "Before (double): ";
    PrintArray<double>(b, n, 0);
    cout << endl;
    SortNonIncreasing<double>(b, n, 0);
    cout << "After  (double): ";
    PrintArray<double>(b, n, 0);
    cout << endl << endl;

    string c[n] = { "3", "9", "1", "7", "5", "10", "2", "8", "4", "6" };
    cout << "Before (string): ";
    PrintArray<string>(c, n, 0);
    cout << endl;
    SortNonIncreasing<string>(c, n, 0);
    cout << "After  (string): ";
    PrintArray<string>(c, n, 0);
    cout << endl;

    return 0;
}

// ---------- PrintArray ----------
void PrintArray(const int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        PrintArray(a, size, i + 1);
    }
}

template <typename T>
void PrintArray(const T* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        PrintArray<T>(a, size, i + 1);
    }
}

// ---------- SwapElements ----------
void SwapElements(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

template <typename T>
void SwapElements(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}

// ---------- FindMaxIndex ----------
int FindMaxIndex(const int* a, const int size, int i, int maxIndex)
{
    if (i >= size)
        return maxIndex;
    if (a[i] > a[maxIndex])
        maxIndex = i;
    return FindMaxIndex(a, size, i + 1, maxIndex);
}

template <typename T>
int FindMaxIndex(const T* a, const int size, int i, int maxIndex)
{
    if (i >= size)
        return maxIndex;
    if (a[i] > a[maxIndex])
        maxIndex = i;
    return FindMaxIndex<T>(a, size, i + 1, maxIndex);
}

// ---------- SortNonIncreasing ----------
void SortNonIncreasing(int* a, const int size, int i)
{
    if (i < size - 1)
    {
        int m = FindMaxIndex(a, size, i, i);
        SwapElements(a[i], a[m]);
        SortNonIncreasing(a, size, i + 1);
    }
}

template <typename T>
void SortNonIncreasing(T* a, const int size, int i)
{
    if (i < size - 1)
    {
        int m = FindMaxIndex<T>(a, size, i, i);
        SwapElements<T>(a[i], a[m]);
        SortNonIncreasing<T>(a, size, i + 1);
    }
}