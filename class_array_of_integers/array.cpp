#include "array.h"

Array::Array()
{
	this->array_of_integers = new int[this->array_length + 1];
}

Array::Array(int* array_of_integers, unsigned long long int array_length)
{
	this->array_length = array_length;
	this->array_of_integers = new int[this->array_length + 1];

	for (unsigned long long int i = 0; i < this->array_length; ++i)
	{
		this->array_of_integers[i] = array_of_integers[i];
	}
	this->array_of_integers[this->array_length] = '\0'; // последний элемент в массиве обозначаю так, иначе могут быть ошибки
}



Array::Array(const Array& a)
{
	this->array_length = a.array_length;
	this->array_of_integers = new int[this->array_length + 1];
	for (unsigned long long int i = 0; i < this->array_length; ++i)
	{
		this->array_of_integers[i] = a.array_of_integers[i];
	}
}



Array::~Array()
{
	delete[] this->array_of_integers;
}



bool Array::comparing_an_integer_with_array(int integer) const // функция для проверки, есть ли в массиве элемент, который мы хотим к нему добавить
{
	for (unsigned long long int i = 0; i < this->array_length; ++i)
	{
		if (this->array_of_integers[i] == integer)
		{
			return true;
		}
	}
	return false;
}



/**************ДОБАВЛЕНИЕ*ЭЛЕМЕНТА*ВО*МНОЖЕСТВО***************/

// ПЕРЕГРУЗКА ОПЕРАТОРА+
Array Array::operator+(int integer)
{
	if (comparing_an_integer_with_array(integer) == false) // проверка, есть ли в массиве элемент, который нужно к нему добавить (нужно, чтобы его не было, иначе будут повторяющиеся элементы)
	{
		Array addition;

		addition.array_length = this->array_length + 1; // указание размера нового массива с увеличением длины на единицу (для нового элмента)
		addition.array_of_integers = new int[addition.array_length + 1]; // выделение памяти под новый массив

		for (unsigned long long int i = 0; i < addition.array_length; ++i) // копирование массива в новый массив
		{
			addition.array_of_integers[i] = this->array_of_integers[i];
		}
		addition.array_of_integers[addition.array_length - 1] = integer; // добавление нового элемемента в конец нового массива

		return addition;
	}
	return *this;
}

// ПЕРЕГРУЗКА ОПЕРАТОРА+=
Array Array::operator+=(int integer)
{
	if (comparing_an_integer_with_array(integer) == false) // проверка, есть ли в массиве элемент, который нужно к нему добавить (нужно, чтобы его не было, иначе будут повторяющиеся элементы)
	{
		Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

		delete[]this->array_of_integers; // удаление текущего массива

		++this->array_length; // увеличение длины текущего массива на единицу (для добавления нового элемента)
		this->array_of_integers = new int[this->array_length + 1]; // выделение памяти под текущий массив

		for (unsigned long long int i = 0; i < (this->array_length - 1); ++i) // копирование временного массива в текущий
		{
			this->array_of_integers[i] = temp.array_of_integers[i];
		}
		this->array_of_integers[this->array_length - 1] = integer; // добавление нового элемемента в новый массив
	}
	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************ОБЪЕДИНЕНИЕ*МНОЖЕСТВ*********************/

// ПЕРЕГРУЗКА ОПЕРАТОРА+
Array Array::operator+(Array a) const
{
	a /= *this; // использование перегрузки оператора /= для того, чтобы найти символы, которые есть во втором массиве, но нет в первом

	Array unification(this->array_of_integers, (this->array_length + a.array_length)); // использование конструктора для копирования

	for (unsigned long long int i = this->array_length, j = 0; i < (this->array_length + a.array_length); ++i, ++j) // добавление второго массива к новому массиву unification
	{
		unification.array_of_integers[i] = a.array_of_integers[j];
	}

	return unification;
}

// ПЕРЕГРУЗКА ОПЕРАТОРА+=
Array Array::operator+=(Array a)
{
	a /= *this; // использование перегрузки оператора /= для того, чтобы найти символы, которые есть во втором массиве, но нет в первом

	Array temp(this->array_of_integers, this->array_length); // использование конструктора для копирования
	delete[]this->array_of_integers; // удаление текущего массива

	this->array_length = this->array_length + a.array_length; // указание длины текущего массива
	this->array_of_integers = new int[this->array_length + 1]; // выделение памяти под текущий массив

	for (unsigned long long int i = 0; i < temp.array_length; i++) // копируем временный массив в текущий
	{
		this->array_of_integers[i] = temp.array_of_integers[i];
	}

	for (unsigned long long int i = (this->array_length - a.array_length), j = 0; i < this->array_length; ++i, ++j) // добавление второго массива к текущему
	{
		this->array_of_integers[i] = a.array_of_integers[j];
	}

	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/***************УДАЛЕНИЕ*ЭЛЕМЕНТА*ИЗ*МНОЖЕСТВА****************/

// ПЕРЕГРУЗКА ОПЕРАТОРА-
Array Array::operator-(int integer) const
{
	if (comparing_an_integer_with_array(integer) == true) // проверка, есть ли в массиве элемент, который нужно убрать (нужно, чтобы он был, иначе что удалять?)
	{
		Array substraction;

		substraction.array_length = this->array_length - 1; // указание размера нового массива substraction с уменьшение длины на единицу
		substraction.array_of_integers = new int[substraction.array_length + 1]; // выделение памяти под новый массив substraction

		for (unsigned long long int i = 0, j = 0; i < substraction.array_length; ++i, ++j) // копирование массива в новый массив substraction
		{
			if (this->array_of_integers[i] == integer)
			{
				++j;
			}
			substraction.array_of_integers[i] = this->array_of_integers[j];
		}

		return substraction;
	}
	return Array(this->array_of_integers, this->array_length);
}

// ПЕРЕГРУЗКА ОПЕРАТОРА-=
Array Array::operator-=(int integer)
{
	if (comparing_an_integer_with_array(integer) == true) // проверка, есть ли в массиве элемент, который нужно к нему добавить (нужно, чтобы он был, иначе что удалять?)
	{
		Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

		delete[]this->array_of_integers; // удаление текущего массива

		--this->array_length; // уменьшение длины текущего массива на единицу (для удаления элемента)
		this->array_of_integers = new int[this->array_length + 1]; // выделение памяти под текущий массив

		for (unsigned long long int i = 0, j = 0; i < this->array_length; ++i, ++j) // копирование временного массива в новый массив
		{
			if (temp.array_of_integers[i] == integer)
			{
				++j;
			}
			this->array_of_integers[i] = temp.array_of_integers[j];
		}
	}
	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////// 

/**********************РАЗНОСТЬ*МНОЖЕСТВ**********************/

// ПЕРЕГРУЗКА ОПЕРАТОРА/
Array Array::operator/(const Array& a) const
{
	Array difference;
	difference.array_length = 0;
	unsigned long long int n = 0;
	for (unsigned long long int i = 0; i < this->array_length; ++i) // тут расчитывается будущий размер массива
	{
		n = 0;
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (this->array_of_integers[i] != a.array_of_integers[j])
			{
				++n;
				if (n == a.array_length)
				{
					++difference.array_length;
				}
			}
		}
	}

	difference.array_of_integers = new int[difference.array_length + 1]; // тут числа добавляются в новый массив разности

	unsigned long long int l = 0;
	for (unsigned long long int i = 0; i < this->array_length; ++i)
	{
		n = 0;
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (this->array_of_integers[i] != a.array_of_integers[j])
			{
				++n;
				if (n == a.array_length)
				{
					difference.array_of_integers[l] = this->array_of_integers[i];
					++l;
				}
			}
		}
	}
	return difference;
}

// ПЕРЕГРУЗКА ОПЕРАТОРА/=
Array Array::operator/=(const Array& a)
{
	Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

	delete[]this->array_of_integers; // удаление массива
	this->array_length = 0; // уменьшение размера массива

	// ниже особо без комментариев, так как тут фигня какая-то получилась: работает, но мне оно кажется колхозным
	unsigned long long int n = 0;
	for (unsigned long long int i = 0; i < temp.array_length; ++i) // расчёт размера будущего массива
	{
		n = 0;
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (temp.array_of_integers[i] != a.array_of_integers[j])
			{
				++n;
				if (n == a.array_length)
				{
					++this->array_length;
				}
			}
		}
	}

	this->array_of_integers = new int[temp.array_length + 1]; // выделение памяти под массив

	unsigned long long int l = 0;
	for (unsigned long long int i = 0; i < temp.array_length; ++i) // добавление чисел в массив
	{
		n = 0;
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (temp.array_of_integers[i] != a.array_of_integers[j])
			{
				++n;
				if (n == a.array_length)
				{
					this->array_of_integers[l] = temp.array_of_integers[i];
					++l;
				}
			}
		}
	}
	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************ПЕРЕСЕЧЕНИЕ*МНОЖЕСТВ*********************/

// ПЕРЕГРУЗКА ОПЕРАТОРА*
Array Array::operator*(Array& a) const
{
	Array intersection;
	intersection.array_length = 0;
	for (unsigned long long int i = 0; i < this->array_length; ++i) // тут расчитывается будущий размер массива
	{
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if ((int)this->array_of_integers[i] == (int)a.array_of_integers[j])
			{
				++intersection.array_length;
			}
		}
	}

	intersection.array_of_integers = new int[intersection.array_length + 1];

	int l = 0;
	for (unsigned long long int i = 0; i < this->array_length; ++i) // тут числа добавляются в новый массив пересечений
	{
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (this->array_of_integers[i] == a.array_of_integers[j])
			{
				intersection.array_of_integers[l] = this->array_of_integers[i];
				++l;
			}
		}
	}
	return intersection;
}

// ПЕРЕГРУЗКА ОПЕРАТОРА*=
Array Array::operator*=(Array& a)
{
	Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

	delete[]this->array_of_integers; // удаление массива
	this->array_length = 0; // уменьшение размера массива

	for (unsigned long long int i = 0; i < temp.array_length; ++i) // расчёт размера будущего массива
	{
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (temp.array_of_integers[i] == a.array_of_integers[j])
			{
				++this->array_length;
			}
		}
	}

	this->array_of_integers = new int[temp.array_length + 1]; // выделение памяти под массив

	unsigned long long int l = 0;
	for (unsigned long long int i = 0; i < temp.array_length; ++i) // добавление чисел в массив
	{
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (temp.array_of_integers[i] == a.array_of_integers[j])
			{
				this->array_of_integers[l] = temp.array_of_integers[i];
				++l;
			}
		}
	}
	return *this;
}
/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/************************ПРИСВАИВАНИЕ*************************/

// ПЕРЕГРУЗКА ОПЕРАТОРА=
Array Array::operator=(const Array& a)
{
	this->array_length = a.array_length;
	this->array_of_integers = new int[this->array_length + 1];
	for (unsigned long long int i = 0; i < this->array_length; ++i)
	{
		this->array_of_integers[i] = a.array_of_integers[i];
	}
	this->array_of_integers[this->array_length] = '\0'; // последний элемент в массиве обозначаю так, иначе могут быть ошибки

	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************СРАВНЕНИЕ*МНОЖЕСТВ***********************/

// ПЕРЕГРУЗКА ОПЕРАТОРА==
bool Array::operator==(Array a) const
{
	if (this->array_length == a.array_length)
	{
		a /= *this;

		if (a.array_length == 0)
		{
			return true;
		}
	}
	return false;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/***********************ВЫВОД*МНОЖЕСТВА***********************/

// ПЕРЕГРУЗКА ОПЕРАТОРОВ << И >>
std::ostream& operator<< (std::ostream& output, const Array& a)
{
	for (unsigned long long int i = 0; i < a.array_length; i++)
	{
		output << (int)a.array_of_integers[i] << " ";
	}
	return output;
}

std::istream& operator>> (std::istream& input, Array& a)
{
	std::cout << "Введите размер будущего массива: ";
	std::cin >> a.array_length;

	delete[]a.array_of_integers;
	a.array_of_integers = new int[a.array_length + 1];

	unsigned long long int temp = 0; // для проверки, есть ли уже введённое число в массиве
	for (unsigned long long int i = 0; i < a.array_length;)
	{
		std::cout << "Введите число массива под номером " << i + 1 << ": ";
		input >> temp;

		if (a.comparing_an_integer_with_array(temp) == false) // для проверки, есть ли уже введённое число в массиве
		{
			a.array_of_integers[i] = temp;
			++i;
		}
	}
	a.array_of_integers[a.array_length] = '\0'; // последний элемент

	return input;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/*************************************************************/