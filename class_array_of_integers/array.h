#pragma once
#include <iostream>

using namespace std;

class Array
{
public:
	Array();
	Array(int* array_of_integers, unsigned long long int array_length);
	Array(const Array& a);

	~Array();

private:
	unsigned long long int array_length = 10;
	int* array_of_integers = nullptr;

public:
	bool comparing_an_integer_with_array(int integer) const; // функция для проверки, есть ли в массиве элемент, который мы хотим к нему добавить

	// ДОБАВЛЕНИЕ ЭЛЕМЕНТА В МНОЖЕСТВО
	Array operator+(unsigned long long int integer); // работает хорошо
	Array operator+=(unsigned long long int integer); // работает хорошо

	// ОБЪЕДИНЕНИЕ МНОЖЕСТВ
	Array operator+(const Array& a); // работает, но добавляет повторяющиеся элементы
	void operator+=(Array& a); // не написал

	// УДАЛЕНИЕ ЭЛЕМЕНТА ИЗ МНОЖЕСТВА
	Array operator-(unsigned long long int integer); // работает хорошо
	Array operator-=(unsigned long long int integer); // работает хорошо

	// РАЗНОСТЬ МНОЖЕСТВ
	Array operator/(Array& a) const; // работает хорошо
	Array operator/=(Array& a); // работает хорошо

	// ПЕРЕСЕЧЕНИЕ МНОЖЕСТВ
	Array operator*(Array& a) const; // работает хорошо
	Array operator*=(Array& a); // работает хорошо

	// ПРИСВАИВАНИЕ
	Array operator=(Array& a); // не работает


	// СРАВНЕНИЕ МНОЖЕСТВ
	bool operator==(const Array& a) const; // работает, но как-то колхозно выглядит, мне не нравится

	// ВЫВОД И ВВОД МНОЖЕСТВ (РАБОТАЕТ)
	friend ostream& operator<<(ostream& output, const Array* a);
	friend istream& operator>>(istream& input, Array* a);

	friend ostream& operator<<(ostream& output, const Array& a);
	friend istream& operator>>(istream& input, Array& a);
};
/* 
1. ВО ВСЕХ FOR ЗАМЕНИТЬ int i, j НА unsigned long long int i, j
2. ПОДОБАВЛЯТЬ CONST К ОПЕРАТОРАМ/ФУНКЦИЯМ
3. ПОИГРАТЬСЯ С * И &
4. ОБЛАГОРОДИТЬ main.cpp
5. ПЕРЕПИСАТЬ operator== и operator=

*/