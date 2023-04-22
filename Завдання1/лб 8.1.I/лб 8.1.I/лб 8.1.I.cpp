#include <iostream>
#include <Windows.h>
#include <string>
#include <cassert>

using namespace std;

template <typename T>
double average(T arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum / size;
}

template <>
double average<char*>(char* arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += strlen(arr[i]);
    }
    return sum / size;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_SIZE = 100;
    char** charArr = new char* [MAX_SIZE]; // оголошення динамічного масиву
    int charArrSize = 0;

    // введення рядків з клавіатури та збереження їх у масиві charArr
    cout << "Натисніть 2 рази Enter для завершення вводу: ";
    while (charArrSize < MAX_SIZE)
    {
        char input[MAX_SIZE];
        cin.getline(input, MAX_SIZE);
        if (strcmp(input, "") == 0)
        {
            break;
        }
        charArr[charArrSize] = new char[strlen(input) + 1];
        strcpy_s(charArr[charArrSize], strlen(input) + 1, input);
        charArrSize++;
    }

    double charArrAvg = average(const_cast<char**>(charArr), charArrSize);
    cout << "Середня довжина рядка: " << charArrAvg << endl;

    // звільнення пам'яті, яку було виділено для динамічного масиву та його елементів
    for (int i = 0; i < charArrSize; i++)
    {
        delete[] charArr[i];
    }
    delete[] charArr;
}