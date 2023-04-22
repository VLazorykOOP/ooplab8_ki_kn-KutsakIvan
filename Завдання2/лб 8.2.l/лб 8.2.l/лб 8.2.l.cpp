#include <iostream>
#include <Windows.h>
#include <string>
#include <cassert>

using namespace std;

template <typename T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

template <>
void selectionSort<char*>(char* arr[], int size)
{
    const int MAX_STRING_LENGTH = 100;
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (strlen(arr[j]) < strlen(arr[minIndex]) /*strcmp(arr[j], arr[minIndex]) < 0*/)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_SIZE = 100;
    char** charArr = new char* [MAX_SIZE]; // оголошення динамічного масиву
    int charArrSize = 0;

    // введення рядків з клавіатури та збереження їх у масиві charArr
    cout << "Натисніть 2 рази Enter для завершення вводу\n";
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

    selectionSort(const_cast<char**>(charArr), charArrSize);
    for (int i = 0; i < charArrSize; i++)cout << charArr[i] << "\n";


    // звільнення пам'яті, яку було виділено для динамічного масиву та його елементів
    for (int i = 0; i < charArrSize; i++)
    {
        delete[] charArr[i];
    }
    delete[] charArr;
}