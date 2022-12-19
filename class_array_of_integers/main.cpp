#include <iostream>
#include "array.h"

int main()
{
    setlocale(LC_ALL, "rus");

    unsigned long long int array_length_1 = 5;
    int* array_of_integers_1 = new int[array_length_1 + 1] { 0, 2, 3, 4, 5, '\0' };

    unsigned long long int array_length_2 = 5;
    int* array_of_integers_2 = new int[array_length_2 + 1] { 0, 22, 11, 3, 63, '\0' };

// ДОБАВЛЕНИЕ ЭЛЕМЕНТА ВО МНОЖЕСТВО (РАБОТАЕТ)
    // ПЕРЕГРУЗКА + (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);

    //std::cout << array_1 + 2 << std::endl; // 2 - уже есть в массиве, не добавится
    //std::cout << array_1 + 6 << std::endl; // 6 - отсутствует, добавится

    // ПЕРЕГРУЗКА += (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);

    //array_1 += 2; // 2 - уже есть в массиве, не добавится
    //std::cout << array_1 << std::endl;
    //array_1 += 6; // 6 - отсутствует, добавится
    //std::cout << array_1 << std::endl;

// ОБЪЕДИНЕНИЕ МНОЖЕСТВ (РАБОТАЕТ ЧАСТИЧНО)
    // ПЕРЕГРУЗКА + (РАБОТАЕТ ЧАСТИЧНО)
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);

    //array_1 + array_2;
    //std::cout << array_1 << std::endl;


    //std::cout << array_1 + array_2 << std::endl;
   
    // ПЕРЕГРУЗКА += (НЕ ДЕЛАЛ)


// ОБЪЕДИНЕНИЕ МНОЖЕСТВ

// УДАЛЕНИЕ ЭЛЕМЕНТА ИЗ МНОЖЕСТВА (РАБОТАЕТ)
    // ПЕРЕГРУЗКА - (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);

    //std::cout << array_1 - 2 << std::endl;
    //std::cout << array_2 - 3 << std::endl;

    // ПЕРЕГРУЗКА -= (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);

    //array_1 -= 1; // 1 - отсутствует в массиве, не удалится
    //std::cout << array_1 << std::endl;
    //array_1 -= 3; // 5 - присутствует, удалится
    //std::cout << array_1 << std::endl;

    //std::cout << std::endl;

// РАЗНОСТЬ МНОЖЕСТВ (РАБОТАЕТ)
    // ПЕРЕГРУЗКА / (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);

    //std::cout << array_1 / array_2 << std::endl;
    //std::cout << array_2 / array_1 << std::endl;

    // ПЕРЕГРУЗКА /= (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);

    //array_1 /= array_2;
    //std::cout << array_1 << std::endl;


    //Array array_3(array_of_integers_1, array_length_1);

    //array_2 /= array_3;
    //std::cout << array_2 << std::endl;



// ПЕРЕСЕЧЕНИЕ МНОЖЕСТВ (РАБОТАЕТ)
    // ПЕРЕГРУЗКА * (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);

    //std::cout << array_1 * array_2 << std::endl;

    // ПЕРЕГРУЗКА *= (РАБОТАЕТ)
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);

    //array_1 *= array_2;
    //std::cout << array_1 << std::endl;

// ПРИСВАИВАНИЕ
    Array array_1(array_of_integers_1, array_length_1);
    Array array_2;
    array_2 = array_1;

    std::cout << array_2 << std::endl;

// СРАВНЕНИЕ МНОЖЕСТВ
    //Array array_1(array_of_integers_1, array_length_1);
    //Array array_2(array_of_integers_2, array_length_2);
    //if (array_1 == array_2)
    //{
    //    std::cout << "Массивы равны" << std::endl;
    //}
    //else
    //{
    //    std::cout << "Массивы не равны" << std::endl;
    //}

    //std::cout << std::endl;

    //Array array_3(array_of_integers_1, array_length_1);
    //Array array_4(array_of_integers_1, array_length_1);
    //if (array_3 == array_4)
    //{
    //    std::cout << "Массивы равны" << std::endl;
    //}
    //else
    //{
    //    std::cout << "Массивы не равны" << std::endl;
    //}

// ПЕРЕГРУЗКА << И >> (РАБОТАЕТ)
    //Array* a = new Array;
    //cin >> a;
    //std::cout << a << std::endl;

    //Array a2;
    //cin >> a2;
    //std::cout << a2 << std::endl;


    return 0;
}
