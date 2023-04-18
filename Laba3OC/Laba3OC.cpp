#include <iostream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;

void extremeElementsSum(int mas[], size_t size)
{
    this_thread::sleep_for(chrono::milliseconds(1000));

    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i == 0 && j == 0)
            {
                sum += mas[i * size + j];
            }
            else if (i == 0 && j == size - 1)
            {
                sum += mas[i * size + j];
            }
            else if (i == size - 1 && j == 0)
            {
                sum += mas[i * size + j];
            }
            else if (i == size - 1 && j == size - 1)
            {
                sum += mas[i * size + j];
            }
        }
    }

    cout << "Сумма крайних элементов квадратной матрицы = " << sum << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    const int size = 3;
    int arr[size][size];

    //Заполнение матрицы
    cout << "Введите элементы:" << endl;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cin >> arr[i][j];
    cout << endl;

    //Вывод матрицы
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++) std::cout << std::setw(2) << arr[i][j] << ' ';
        std::cout << std::endl;
    }

    cout << "Запуск потока для подсчета" << endl << endl;

    thread th(extremeElementsSum, reinterpret_cast<int*>(arr), size);
    th.join();

    return 0;
}