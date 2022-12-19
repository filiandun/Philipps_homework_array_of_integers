#include "array.h"

Array::Array() 
{
	this->array_of_integers = new int[this->array_length + 1];
}

Array::Array(int* array_of_integers, unsigned long long int array_length)
{
	this->array_length = array_length;
	this->array_of_integers = new int[this->array_length + 1];
	for (int i = 0; i < this->array_length; ++i)
	{
		this->array_of_integers[i] = array_of_integers[i];
	}
	this->array_of_integers[this->array_length] = '\0'; // последний элемент в массиве обозначаем так, иначе могут быть ошибки
}

Array::Array(const Array& a)
{
	this->array_length = a.array_length;
	this->array_of_integers = new int[this->array_length + 1];
	for (int i = 0; i < this->array_length; ++i)
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
	for (int i = 0; i < this->array_length; ++i)
	{
		if (this->array_of_integers[i] == integer)
		{
			return true;
		}
	}
	return false;
}




Array Array::operator+(unsigned long long int integer)
{
	if (comparing_an_integer_with_array(integer) == false) // проверка, есть ли в массиве элемент, который нужно к нему добавить (нужно, чтобы его не было, иначе будут повторяющиеся элементы)
	{
		Array addition;

		addition.array_length = this->array_length + 1; // указание размера нового массива с увеличением длины на единицу (для нового элмента)
		addition.array_of_integers = new int[addition.array_length + 1]; // выделение памяти под новый массив

		for (int i = 0; i < addition.array_length; ++i) // копирование массива в новый массив
		{
			addition.array_of_integers[i] = this->array_of_integers[i];
		}
		addition.array_of_integers[addition.array_length - 1] = integer; // добавление нового элемемента в конец нового массива
		
		return addition;
	}
	return Array (this->array_of_integers, this->array_length);
}

Array Array::operator+=(unsigned long long int integer)
{
	if (comparing_an_integer_with_array(integer) == false) // проверка, есть ли в массиве элемент, который нужно к нему добавить (нужно, чтобы его не было, иначе будут повторяющиеся элементы)
	{
		Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

		delete[]this->array_of_integers; // удаление текущего массива

		++this->array_length; // увеличение длины текущего массива на единицу (для добавления нового элемента)
		this->array_of_integers = new int[this->array_length + 1]; // выделение памяти под текущий массив

		for (int i = 0; i < (this->array_length - 1); ++i) // копирование временного массива в текущий
		{
			this->array_of_integers[i] = temp.array_of_integers[i];
		}
		this->array_of_integers[this->array_length - 1] = integer; // добавление нового элемемента в новый массив
	}
	return *this;
}

///
/// 
/// 
/// 

Array Array::operator+(const Array& a)
{
	int* temp_array = new int[this->array_length + 1]; // копируем текущий массив во временный
	for (int i = 0; i < this->array_length; ++i)
	{
		temp_array[i] = this->array_of_integers[i];
	}

	delete[]this->array_of_integers; // удаляем текущий массив

	this->array_length = this->array_length + a.array_length; // увеличиваем длину текущего массива, прибавляя к нему размер второго массива
	this->array_of_integers = new int[this->array_length + 1]; // выделяем память под текущий массив
	for (int i = 0; i < (this->array_length - a.array_length); ++i) // копируем временный массив в текущий
	{
		this->array_of_integers[i] = temp_array[i];
	}

	for (int i = (this->array_length - a.array_length), j = 0; i < this->array_length; ++i, ++j) // добавление второго массива к текущему
	{
		this->array_of_integers[i] = a.array_of_integers[j];
	}

	delete[]temp_array; // удаление временного массива

	return *this;
}

void Array::operator+=(Array& a)
{

}

///
/// 
/// 
/// 

Array Array::operator-(unsigned long long int integer)
{
	if (comparing_an_integer_with_array(integer) == true) // проверка, есть ли в массиве элемент, который нужно убрать (нужно, чтобы он был, иначе что удалять?)
	{
		Array substraction;

		substraction.array_length = this->array_length - 1; // указание размера нового массива с уменьшение длины на единицу
		substraction.array_of_integers = new int[substraction.array_length + 1]; // выделение памяти под новый массив

		for (int i = 0, j = 0; i < substraction.array_length; ++i, ++j) // копирование массива в новый массив
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


Array Array::operator-=(unsigned long long int integer)
{
	if (comparing_an_integer_with_array(integer) == true) // проверка, есть ли в массиве элемент, который нужно к нему добавить (нужно, чтобы он был, иначе что удалять?)
	{
		Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

		delete[]this->array_of_integers; // удаление текущего массива

		--this->array_length; // уменьшение длины текущего массива на единицу (для удаления элемента)
		this->array_of_integers = new int[this->array_length + 1]; // выделение памяти под текущий массив

		for (int i = 0, j = 0; i < this->array_length; ++i, ++j) // копирование временного массива в новый массив
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

///
/// 
/// 
/// 

Array Array::operator/(Array& a) const
{
	Array difference;
	difference.array_length = 0; 
	unsigned long long int n = 0;
	for (int i = 0; i < this->array_length; ++i) // тут расчитывается будущий размер массива
	{
		n = 0;
		for (int j = 0; j < a.array_length; ++j)
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
	for (int i = 0; i < this->array_length; ++i)
	{
		n = 0;
		for (int j = 0; j < a.array_length; ++j)
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


Array Array::operator/=(Array& a)
{
	Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

	delete[]this->array_of_integers; // удаление массива
	this->array_length = 0; // уменьшение размера массива

	// ниже особо без комментариев, так как тут фигня какая-то получилась: работает, но мне оно кажется колхозным
	unsigned long long int n = 0;
	for (int i = 0; i < temp.array_length; ++i) // расчёт размера будущего массива
	{
		n = 0;
		for (int j = 0; j < a.array_length; ++j)
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
	for (int i = 0; i < temp.array_length; ++i) // добавление чисел в массив
	{
		n = 0;
		for (int j = 0; j < a.array_length; ++j)
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

///
/// 
/// 
/// 

Array Array::operator*(Array& a) const
{
	Array intersection;
	intersection.array_length = 0;
	for (int i = 0; i < this->array_length; ++i) // тут расчитывается будущий размер массива
	{
		for (int j = 0; j < a.array_length; ++j)
		{
			if ((int)this->array_of_integers[i] == (int)a.array_of_integers[j])
			{
				++intersection.array_length;
			}
		}
	}

	intersection.array_of_integers = new int[intersection.array_length + 1]; 

	int l = 0; 
	for (int i = 0; i < this->array_length; ++i) // тут числа добавляются в новый массив пересечений
	{
		for (int j = 0; j < a.array_length; ++j)
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


Array Array::operator*=(Array& a)
{
	Array temp(this->array_of_integers, this->array_length); // копирование текущего массива во временный

	delete[]this->array_of_integers; // удаление массива
	this->array_length = 0; // уменьшение размера массива

	for (int i = 0; i < temp.array_length; ++i) // расчёт размера будущего массива
	{
		for (int j = 0; j < a.array_length; ++j)
		{
			if (temp.array_of_integers[i] == a.array_of_integers[j])
			{
				++this->array_length;
			}
		}
	}

	this->array_of_integers = new int[temp.array_length + 1]; // выделение памяти под массив

	unsigned long long int l = 0;
	for (int i = 0; i < temp.array_length; ++i) // добавление чисел в массив
	{
		for (int j = 0; j < a.array_length; ++j)
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

///
/// 
/// 
/// 

Array Array::operator=(Array& a)
{
	Array equating(a.array_of_integers, a.array_length);
	return *this;
}

///
/// 
/// 
///

bool Array::operator==(const Array& a) const
{
	if (this->array_length == a.array_length)
	{
		Array b(this->array_of_integers, this->array_length);
		Array c = a * b;

		if (c.array_length == this->array_length)
		{
			return true;
		}
	}
	return false;
}

///
/// 
/// 
///

// ПЕРЕГРУЗКА << И >> (РАБОТАЕТ БЕЗ НАРЕКАНИЙ)
// для динамических объектов
ostream& operator<< (ostream& output, const Array* a)
{
	for (int i = 0; i < a->array_length; i++)
	{
		output << a->array_of_integers[i] << " ";
	}
	return output;
}

istream& operator>> (istream& input, Array* a)
{
	cout << "Введите размер массива, который хотите ввести: ";
	int array_length = 0;
	cin >> array_length;

	cout << endl << "Введите массив (каждое число через пробел, например 1 2 3 4):" << endl;
	a->array_length = 0;
	while (a->array_length != array_length)
	{
		input >> a->array_of_integers[a->array_length];
		a->array_length += 1;
	}
	return input;
}

// для статических объектов
ostream& operator<< (ostream& output, const Array& a)
{
	for (int i = 0; i < a.array_length; i++)
	{
		output << a.array_of_integers[i] << " ";
	}
	return output;
}

istream& operator>> (istream& input, Array& a)
{
	cout << "Введите размер массива, который хотите ввести: ";
	int array_length = 0;
	cin >> array_length;

	cout << endl << "Введите массив (каждое число через пробел, например 1 2 3 4):" << endl;
	a.array_length = 0;
	while (a.array_length != array_length)
	{
		input >> a.array_of_integers[a.array_length];
		a.array_length += 1;
	}
	return input;
}
