#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

struct Array
{
    int length;

    int* array;

    void create(int size, int min, int max);
    void create(Array array);//копия созданной структуры
    void insertionSort(int* arrayPtr);
    void bubbleSort();
    void choicesSort();
    void print();
    void print1();

};

void Array::create(int size, int min, int max)
{
    length = size;

    array =(int *)malloc(size*sizeof(int));

    for (int counter = 0; counter < length; counter++)
    {
        array[counter] = rand() % max + min; // заполняем массив случайными числами
    }
}

void Array::print()
{
    for (int counter = 0; counter < length; counter++)
    {
        printf("%d\n", array[counter] );
    }
}

void Array::print1()
{
    printf("%s\n","----------");

    for (int counter = 0; counter < length; counter++)
    {
        printf("%d\n", array[counter] );
    }
}

int main(int argc, char* argv[])
{
    Array arr;

    srand(time(NULL));

    int arrSize = 0;
    scanf("%d",&arrSize);

    arr.create(arrSize, -100, 100);

    setlocale(LC_ALL, "rus");

    clock_t time;
    time = clock();
    arr.print();
    arr.bubbleSort(); // вызов функции сортировки пузырьком

    time = clock() - time;
    printf("Время выполнения сортировки пузырьком : %f\n", (double)time/CLOCKS_PER_SEC); //время выполнения "каких-то действий


    time = clock();
    arr.choicesSort();

    time = clock() - time;
    printf("Время выполнения сортировки выбором : %f\n", (double)time/CLOCKS_PER_SEC);

    time = clock();
    arr.insertionSort(arr.array);
    for (int counter = 0; counter < arr.length; counter++)
    {
        arr.array[counter] = rand() % 100; // заполняем массив случайными числами
    }
    arr.insertionSort(arr.array);

    time = clock() - time;
    printf("Время выполнения сортировки вставками : %f\n", (double)time/CLOCKS_PER_SEC);
    arr.print1();
    free(arr.array);

    return 0;
}

void Array::insertionSort(int* arrayPtr) // сортировка вставками
{
    int temp, // временная переменная для хранения значения элемента сортируемого массива
        item; // индекс предыдущего элемента
    for (int counter = 1; counter < length; counter++)
    {
        temp = array[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter-1; // запоминаем индекс предыдущего элемента массива
        while(item >= 0 && array[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            array[item + 1] = arrayPtr[item]; // перестановка элементов массива
            array[item] = temp;
            item--;
        }
    }
}

void Array::bubbleSort() // сортировка пузырьком
{
    int temp = 0; // временная переменная для хранения элемента массива
    bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован

    while (!exit) // пока массив не отсортирован
    {
        exit = true;
        for (int int_counter = 0; int_counter < (length - 1); int_counter++) // внутренний цикл
        //сортировка пузырьком по возрастанию - знак >
        //сортировка пузырьком по убыванию - знак <
        if (array[int_counter] > array[int_counter + 1]) // сравниваем два соседних элемента
        {
        // выполняем перестановку элементов массива
        temp = array[int_counter];
        array[int_counter] = array[int_counter + 1];
        array[int_counter + 1] = temp;
        exit = false;
        }
    }
}

void Array::choicesSort() // сортировка выбором
{
    for (int repeat_counter = 0; repeat_counter < length; repeat_counter++)
    {
        int temp = array[0]; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length; element_counter++)
        {
            if (array[repeat_counter] > array[element_counter])
            {
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                array[element_counter] = temp;
            }
        }
    }
}
