#include <iostream>
#include "array.h"


//#define ADD_AN_ELEMENT
//#define UNIFICATION
//#define DEL_AN_ELEMENT
//#define DIFFERENCE
//#define INTERSECTION
//#define EQUALITY
//#define ASSIGNMENTLY
#define INPUT_OUTPUT


int main()
{
    setlocale(LC_ALL, "rus");

    unsigned long long int array_length_1 = 5;
    int* array_of_integers_1 = new int[array_length_1 + 1] { 0, 2, 3, 4, 5, '\0' };

    unsigned long long int array_length_2 = 5;
    int* array_of_integers_2 = new int[array_length_2 + 1] { 0, 22, 11, 3, 63, '\0' };


/**************ДОБАВЛЕНИЕ*ЭЛЕМЕНТА*ВО*МНОЖЕСТВО***************/

#ifdef ADD_AN_ELEMENT

// ПЕРЕГРУЗКА ОПЕРАТОРА+
    std::cout << "ДОБАВЛЕНИЕ ЭЛЕМЕНТА ВО МНОЖЕСТВО" << std::endl;
    std::cout << "--------- перегрузка+ ----------" << std::endl << std::endl;

    Array array_for_addition_operator(array_of_integers_1, array_length_1);
    // Array array_for_addition_operator = Array(array_of_integers_1, array_length_1);
    // или я дурак, или ..., но почему explicit перед конструктором без такой записи позволяет работать программе и не выдаёт никаких ошибок?
    std::cout << "Исходный массив: " << array_for_addition_operator << std::endl << std::endl;

    std::cout << "Исходный массив + 2: " << array_for_addition_operator + 2 << std::endl; // 2 - уже есть в массиве, не добавится
    std::cout << "Исходный массив + 6: " << array_for_addition_operator + 6 << std::endl; // 6 - отсутствует, добавится


// ПЕРЕГРУЗКА ОПЕРАТОРА+=
    std::cout << std::endl << std::endl << "--------- перегрузка+= ---------" << std::endl << std::endl;

    Array array_for_addition_and_assignment_operator(array_of_integers_1, array_length_1);

    std::cout << "Исходный массив: " << array_for_addition_and_assignment_operator << std::endl << std::endl;

    array_for_addition_and_assignment_operator += 2; // 2 - уже есть в массиве, не добавится
    std::cout << "Массив: исходный массив += 2: " << array_for_addition_and_assignment_operator << std::endl;

    array_for_addition_and_assignment_operator += 6; // 6 - отсутствует, добавится
    std::cout << "Массив: исходный массив += 6: " << array_for_addition_and_assignment_operator << std::endl << std::endl;

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************ОБЪЕДИНЕНИЕ*МНОЖЕСТВ*********************/

#ifdef UNIFICATION

// ПЕРЕГРУЗКА ОПЕРАТОРА+
    std::cout << std::endl << std::endl << std::endl << "      ОБЪЕДИНЕНИЕ МНОЖЕСТВ      " << std::endl;
    std::cout << "--------- перегрузка+ ----------" << std::endl << std::endl;

    Array array_for_addition_operator_1(array_of_integers_1, array_length_1);
    Array array_for_addition_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_addition_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_addition_operator_2 << std::endl << std::endl;

    std::cout << "Исходный первый массив + исходный второй массив: " << array_for_addition_operator_1 + array_for_addition_operator_2 << std::endl << std::endl;

    std::cout << "Исходный первый массив: " << array_for_addition_operator_1 << std::endl; // не изменился
    std::cout << "Исходный второй массив: " << array_for_addition_operator_2 << std::endl; // не изменился


// ПЕРЕГРУЗКА ОПЕРАТОРА+=
    std::cout << std::endl << std::endl << "--------- перегрузка+= ---------" << std::endl << std::endl;

    Array array_for_addition_and_assignment_operator_1(array_of_integers_1, array_length_1);
    Array array_for_addition_and_assignment_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_addition_and_assignment_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_addition_and_assignment_operator_2 << std::endl << std::endl;

    array_for_addition_and_assignment_operator_1 += array_for_addition_and_assignment_operator_2;
    std::cout << "Первый массив: исходный первый массив += исходный второй массив: " << array_for_addition_and_assignment_operator_1 << std::endl; // изменится
    std::cout << "Исходный второй массив: " << array_for_addition_and_assignment_operator_2 << std::endl << std::endl; // не изменится

    array_for_addition_and_assignment_operator_2 += array_for_addition_and_assignment_operator_1;
    std::cout << "Второй массив: исходный второй массив += исходный первый массив: " << array_for_addition_and_assignment_operator_2 << std::endl; // изменится
    std::cout << "Исходный первый массив: " << array_for_addition_and_assignment_operator_1 << std::endl << std::endl; // не изменится

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/***************УДАЛЕНИЕ*ЭЛЕМЕНТА*ИЗ*МНОЖЕСТВА****************/

#ifdef DEL_AN_ELEMENT

// ПЕРЕГРУЗКА ОПЕРАТОРА-
    std::cout << std::endl << std::endl << std::endl << " УДАЛЕНИЕ ЭЛЕМЕНТА ИЗ МНОЖЕСТВА " << std::endl;
    std::cout << "--------- перегрузка- ----------" << std::endl << std::endl;

    Array array_for_substraction_operator(array_of_integers_1, array_length_1);

    std::cout << "Исходный массив: " << array_for_substraction_operator << std::endl << std::endl;

    std::cout << "Исходный первый массив - 2: " << array_for_substraction_operator - 2 << std::endl; // 2 - присутствует, удалится
    std::cout << "Исходный первый массив - 6: " << array_for_substraction_operator - 6 << std::endl; // 6 - отсутствует в массиве, не удалится


// ПЕРЕГРУЗКА ОПЕРАТОРА-=
    std::cout << std::endl << std::endl << "--------- перегрузка-= ---------" << std::endl << std::endl;

    Array array_for_substraction_and_assignment_operator(array_of_integers_1, array_length_1);

    std::cout << "Исходный массив: " << array_for_substraction_and_assignment_operator << std::endl << std::endl;

    array_for_substraction_and_assignment_operator -= 3; // 3 - присутствует, удалится
    std::cout << "Массив: исходный первый массив -= 3: " << array_for_substraction_and_assignment_operator << std::endl; // изменится

    array_for_substraction_and_assignment_operator -= 1; // 1 - отсутствует в массиве, не удалится
    std::cout << "Массив: исходный массив -= 1: " << array_for_substraction_and_assignment_operator << std::endl << std::endl; // не изменится

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/**********************РАЗНОСТЬ*МНОЖЕСТВ**********************/

#ifdef DIFFERENCE

// ПЕРЕГРУЗКА ОПЕРАТОРА/
    std::cout << std::endl << std::endl << std::endl << "       РАЗНОСТЬ МНОЖЕСТВ       " << std::endl;
    std::cout << "--------- перегрузка/ ---------" << std::endl << std::endl;

    Array array_for_difference_operator_1(array_of_integers_1, array_length_1);
    Array array_for_difference_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_difference_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_difference_operator_2 << std::endl << std::endl;

    std::cout << "Исходный первый массив / исходный второй массив: " << array_for_difference_operator_1 / array_for_difference_operator_2 << std::endl;
    std::cout << "Исходный второй массив / исходный первый массив: " << array_for_difference_operator_2 / array_for_difference_operator_1 << std::endl;


// ПЕРЕГРУЗКА ОПЕРАТОРА/=
    std::cout << std::endl << std::endl << "--------- перегрузка/= ---------" << std::endl << std::endl;

    Array array_for_difference_and_assignment_operator_1(array_of_integers_1, array_length_1);
    Array array_for_difference_and_assignment_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_difference_and_assignment_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_difference_and_assignment_operator_2 << std::endl << std::endl;

    array_for_difference_and_assignment_operator_1 /= array_for_difference_and_assignment_operator_2;
    std::cout << "Первый массив: исходный первый массив /= исходный второй массив: " << array_for_difference_and_assignment_operator_1 << std::endl; // изменится
    std::cout << "Исходный второй массив: " << array_for_difference_and_assignment_operator_2 << std::endl << std::endl; // не изменится


    Array array_for_difference_and_assignment_operator_3(array_of_integers_1, array_length_1);
    array_for_difference_and_assignment_operator_2 /= array_for_difference_and_assignment_operator_3;
    std::cout << "Второй массив: исходный второй массив /= исходный третий массив: " << array_for_difference_and_assignment_operator_2 << std::endl; // изменится
    std::cout << "Исходный третий массив: " << array_for_difference_and_assignment_operator_3 << std::endl << std::endl; // не изменится

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************ПЕРЕСЕЧЕНИЕ*МНОЖЕСТВ*********************/

#ifdef INTERSECTION

// ПЕРЕГРУЗКА ОПЕРАТОРА*
    std::cout << std::endl << std::endl << std::endl << "      ПЕРЕСЕЧЕНИЕ МНОЖЕСТВ     " << std::endl;
    std::cout << "--------- перегрузка* ---------" << std::endl << std::endl;

    Array array_for_intersection_operator_1(array_of_integers_1, array_length_1);
    Array array_for_intersection_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_intersection_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_intersection_operator_2 << std::endl << std::endl;

    std::cout << "Исходный первый массив * исходный второй массив: " << array_for_intersection_operator_1 * array_for_intersection_operator_2 << std::endl;
    std::cout << "Исходный второй массив * исходный первый массив: " << array_for_intersection_operator_2 * array_for_intersection_operator_1 << std::endl;

// ПЕРЕГРУЗКА ОПЕРАТОРА*=
    std::cout << std::endl << std::endl << "--------- перегрузка*= ---------" << std::endl << std::endl;

    Array array_for_intersection_and_assignment_operator_1(array_of_integers_1, array_length_1);
    Array array_for_intersection_and_assignment_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_intersection_and_assignment_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_intersection_and_assignment_operator_2 << std::endl << std::endl;

    array_for_intersection_and_assignment_operator_1 *= array_for_intersection_and_assignment_operator_2;
    std::cout << "Первый массив: исходный первый массив *= исходный второй массив: " << array_for_intersection_and_assignment_operator_1 << std::endl; // изменится
    std::cout << "Исходный второй массив: " << array_for_intersection_and_assignment_operator_2 << std::endl << std::endl; // не изменится


    Array array_for_intersection_and_assignment_operator_3(array_of_integers_1, array_length_1);
    array_for_intersection_and_assignment_operator_2 *= array_for_intersection_and_assignment_operator_3;
    std::cout << "Второй массив: исходный второй массив *= исходный третий массив: " << array_for_intersection_and_assignment_operator_2 << std::endl; // изменится
    std::cout << "Исходный третий массив: " << array_for_intersection_and_assignment_operator_3 << std::endl << std::endl; // не изменится

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/************************ПРИСВАИВАНИЕ*************************/

#ifdef EQUALITY

// ПЕРЕГРУЗКА ОПЕРАТОРА=
    std::cout << std::endl << std::endl << std::endl << "          ПРИСВАИВАНИЕ         " << std::endl;
    std::cout << "--------- перегрузка= ---------" << std::endl << std::endl;

    Array array_for_equal_operator_1(array_of_integers_1, array_length_1);
    Array array_for_equal_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_equal_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_equal_operator_2 << std::endl << std::endl;

    array_for_equal_operator_2 = array_for_equal_operator_1;

    std::cout << "Исходный первый массив: " << array_for_equal_operator_1 << std::endl; // не изменится
    std::cout << "Второй массив: исходный второй массив = исходный первый массив: " << array_for_equal_operator_2 << std::endl << std::endl; // изменится

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************СРАВНЕНИЕ*МНОЖЕСТВ***********************/

#ifdef ASSIGNMENTLY

// ПЕРЕГРУЗКА ОПЕРАТОРА==
// МАССИВЫ НЕ РАВНЫ
    std::cout << std::endl << std::endl << std::endl << "       СРАВНЕНИЕ МНОЖЕСТВ      " << std::endl;
    std::cout << "--------- перегрузка== --------" << std::endl << std::endl;

    Array array_for_assignment_operator_1(array_of_integers_1, array_length_1);
    Array array_for_assignment_operator_2(array_of_integers_2, array_length_2);

    std::cout << "Исходный первый массив: " << array_for_assignment_operator_1 << std::endl;
    std::cout << "Исходный второй массив: " << array_for_assignment_operator_2 << std::endl << std::endl;

    if (array_for_assignment_operator_1 == array_for_assignment_operator_2)
    {
        std::cout << "Массивы равны" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Массивы не равны" << std::endl << std::endl;
    }


// МАССИВЫ РАВНЫ
    Array array_for_assignment_operator_3(array_of_integers_1, array_length_1);
    Array array_for_assignment_operator_4(array_of_integers_1, array_length_1);

    std::cout << "Исходный третий массив: " << array_for_assignment_operator_3 << std::endl;
    std::cout << "Исходный четвёртый массив: " << array_for_assignment_operator_4 << std::endl << std::endl;

    if (array_for_assignment_operator_3 == array_for_assignment_operator_4)
    {
        std::cout << "Массивы равны" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Массивы не равны" << std::endl << std::endl;
    }


// МАССИВЫ РАВНЫ
    unsigned long long int array_length_3 = 5;
    int* array_of_integers_3 = new int[array_length_3 + 1] { 2, 0, 4, 3, 5, '\0' };

    Array array_for_assignment_operator_5(array_of_integers_1, array_length_1);
    Array array_for_assignment_operator_6(array_of_integers_3, array_length_3);

    std::cout << "Исходный пятый массив: " << array_for_assignment_operator_5 << std::endl;
    std::cout << "Исходный шестой массив: " << array_for_assignment_operator_6 << std::endl << std::endl;

    if (array_for_assignment_operator_5 == array_for_assignment_operator_6)
    {
        std::cout << "Массивы равны" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Массивы не равны" << std::endl << std::endl;
    }

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/***********************ВЫВОД*МНОЖЕСТВА***********************/

#ifdef INPUT_OUTPUT

// ПЕРЕГРУЗКА << И >>
    std::cout << std::endl << std::endl << std::endl << "        ВЫВОД МНОЖЕСТВА        " << std::endl;
    std::cout << "------ перегрузка << и >> ------" << std::endl << std::endl;

    Array array;
    std::cin >> array;
    std::cout << array;

#endif

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/*************************************************************/

    return 0;
}
