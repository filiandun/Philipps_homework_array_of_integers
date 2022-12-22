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
	this->array_of_integers[this->array_length] = '\0'; // ��������� ������� � ������� ��������� ���, ����� ����� ���� ������
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



bool Array::comparing_an_integer_with_array(int integer) const // ������� ��� ��������, ���� �� � ������� �������, ������� �� ����� � ���� ��������
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



/**************����������*��������*��*���������***************/

// ���������� ���������+
Array Array::operator+(int integer)
{
	if (comparing_an_integer_with_array(integer) == false) // ��������, ���� �� � ������� �������, ������� ����� � ���� �������� (�����, ����� ��� �� ����, ����� ����� ������������� ��������)
	{
		Array addition;

		addition.array_length = this->array_length + 1; // �������� ������� ������ ������� � ����������� ����� �� ������� (��� ������ �������)
		addition.array_of_integers = new int[addition.array_length + 1]; // ��������� ������ ��� ����� ������

		for (unsigned long long int i = 0; i < addition.array_length; ++i) // ����������� ������� � ����� ������
		{
			addition.array_of_integers[i] = this->array_of_integers[i];
		}
		addition.array_of_integers[addition.array_length - 1] = integer; // ���������� ������ ���������� � ����� ������ �������

		return addition;
	}
	return *this;
}

// ���������� ���������+=
Array Array::operator+=(int integer)
{
	if (comparing_an_integer_with_array(integer) == false) // ��������, ���� �� � ������� �������, ������� ����� � ���� �������� (�����, ����� ��� �� ����, ����� ����� ������������� ��������)
	{
		Array temp(this->array_of_integers, this->array_length); // ����������� �������� ������� �� ���������

		delete[]this->array_of_integers; // �������� �������� �������

		++this->array_length; // ���������� ����� �������� ������� �� ������� (��� ���������� ������ ��������)
		this->array_of_integers = new int[this->array_length + 1]; // ��������� ������ ��� ������� ������

		for (unsigned long long int i = 0; i < (this->array_length - 1); ++i) // ����������� ���������� ������� � �������
		{
			this->array_of_integers[i] = temp.array_of_integers[i];
		}
		this->array_of_integers[this->array_length - 1] = integer; // ���������� ������ ���������� � ����� ������
	}
	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************�����������*��������*********************/

// ���������� ���������+
Array Array::operator+(Array a) const
{
	a /= *this; // ������������� ���������� ��������� /= ��� ����, ����� ����� �������, ������� ���� �� ������ �������, �� ��� � ������

	Array unification(this->array_of_integers, (this->array_length + a.array_length)); // ������������� ������������ ��� �����������

	for (unsigned long long int i = this->array_length, j = 0; i < (this->array_length + a.array_length); ++i, ++j) // ���������� ������� ������� � ������ ������� unification
	{
		unification.array_of_integers[i] = a.array_of_integers[j];
	}

	return unification;
}

// ���������� ���������+=
Array Array::operator+=(Array a)
{
	a /= *this; // ������������� ���������� ��������� /= ��� ����, ����� ����� �������, ������� ���� �� ������ �������, �� ��� � ������

	Array temp(this->array_of_integers, this->array_length); // ������������� ������������ ��� �����������
	delete[]this->array_of_integers; // �������� �������� �������

	this->array_length = this->array_length + a.array_length; // �������� ����� �������� �������
	this->array_of_integers = new int[this->array_length + 1]; // ��������� ������ ��� ������� ������

	for (unsigned long long int i = 0; i < temp.array_length; i++) // �������� ��������� ������ � �������
	{
		this->array_of_integers[i] = temp.array_of_integers[i];
	}

	for (unsigned long long int i = (this->array_length - a.array_length), j = 0; i < this->array_length; ++i, ++j) // ���������� ������� ������� � ��������
	{
		this->array_of_integers[i] = a.array_of_integers[j];
	}

	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/***************��������*��������*��*���������****************/

// ���������� ���������-
Array Array::operator-(int integer) const
{
	if (comparing_an_integer_with_array(integer) == true) // ��������, ���� �� � ������� �������, ������� ����� ������ (�����, ����� �� ���, ����� ��� �������?)
	{
		Array substraction;

		substraction.array_length = this->array_length - 1; // �������� ������� ������ ������� substraction � ���������� ����� �� �������
		substraction.array_of_integers = new int[substraction.array_length + 1]; // ��������� ������ ��� ����� ������ substraction

		for (unsigned long long int i = 0, j = 0; i < substraction.array_length; ++i, ++j) // ����������� ������� � ����� ������ substraction
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

// ���������� ���������-=
Array Array::operator-=(int integer)
{
	if (comparing_an_integer_with_array(integer) == true) // ��������, ���� �� � ������� �������, ������� ����� � ���� �������� (�����, ����� �� ���, ����� ��� �������?)
	{
		Array temp(this->array_of_integers, this->array_length); // ����������� �������� ������� �� ���������

		delete[]this->array_of_integers; // �������� �������� �������

		--this->array_length; // ���������� ����� �������� ������� �� ������� (��� �������� ��������)
		this->array_of_integers = new int[this->array_length + 1]; // ��������� ������ ��� ������� ������

		for (unsigned long long int i = 0, j = 0; i < this->array_length; ++i, ++j) // ����������� ���������� ������� � ����� ������
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

/**********************��������*��������**********************/

// ���������� ���������/
Array Array::operator/(const Array& a) const
{
	Array difference;
	difference.array_length = 0;
	unsigned long long int n = 0;
	for (unsigned long long int i = 0; i < this->array_length; ++i) // ��� ������������� ������� ������ �������
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

	difference.array_of_integers = new int[difference.array_length + 1]; // ��� ����� ����������� � ����� ������ ��������

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

// ���������� ���������/=
Array Array::operator/=(const Array& a)
{
	Array temp(this->array_of_integers, this->array_length); // ����������� �������� ������� �� ���������

	delete[]this->array_of_integers; // �������� �������
	this->array_length = 0; // ���������� ������� �������

	// ���� ����� ��� ������������, ��� ��� ��� ����� �����-�� ����������: ��������, �� ��� ��� ������� ���������
	unsigned long long int n = 0;
	for (unsigned long long int i = 0; i < temp.array_length; ++i) // ������ ������� �������� �������
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

	this->array_of_integers = new int[temp.array_length + 1]; // ��������� ������ ��� ������

	unsigned long long int l = 0;
	for (unsigned long long int i = 0; i < temp.array_length; ++i) // ���������� ����� � ������
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

/********************�����������*��������*********************/

// ���������� ���������*
Array Array::operator*(Array& a) const
{
	Array intersection;
	intersection.array_length = 0;
	for (unsigned long long int i = 0; i < this->array_length; ++i) // ��� ������������� ������� ������ �������
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
	for (unsigned long long int i = 0; i < this->array_length; ++i) // ��� ����� ����������� � ����� ������ �����������
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

// ���������� ���������*=
Array Array::operator*=(Array& a)
{
	Array temp(this->array_of_integers, this->array_length); // ����������� �������� ������� �� ���������

	delete[]this->array_of_integers; // �������� �������
	this->array_length = 0; // ���������� ������� �������

	for (unsigned long long int i = 0; i < temp.array_length; ++i) // ������ ������� �������� �������
	{
		for (unsigned long long int j = 0; j < a.array_length; ++j)
		{
			if (temp.array_of_integers[i] == a.array_of_integers[j])
			{
				++this->array_length;
			}
		}
	}

	this->array_of_integers = new int[temp.array_length + 1]; // ��������� ������ ��� ������

	unsigned long long int l = 0;
	for (unsigned long long int i = 0; i < temp.array_length; ++i) // ���������� ����� � ������
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

/************************������������*************************/

// ���������� ���������=
Array Array::operator=(const Array& a)
{
	this->array_length = a.array_length;
	this->array_of_integers = new int[this->array_length + 1];
	for (unsigned long long int i = 0; i < this->array_length; ++i)
	{
		this->array_of_integers[i] = a.array_of_integers[i];
	}
	this->array_of_integers[this->array_length] = '\0'; // ��������� ������� � ������� ��������� ���, ����� ����� ���� ������

	return *this;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/********************���������*��������***********************/

// ���������� ���������==
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

/***********************�����*���������***********************/

// ���������� ���������� << � >>
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
	std::cout << "������� ������ �������� �������: ";
	std::cin >> a.array_length;

	delete[]a.array_of_integers;
	a.array_of_integers = new int[a.array_length + 1];

	unsigned long long int temp = 0; // ��� ��������, ���� �� ��� �������� ����� � �������
	for (unsigned long long int i = 0; i < a.array_length;)
	{
		std::cout << "������� ����� ������� ��� ������� " << i + 1 << ": ";
		input >> temp;

		if (a.comparing_an_integer_with_array(temp) == false) // ��� ��������, ���� �� ��� �������� ����� � �������
		{
			a.array_of_integers[i] = temp;
			++i;
		}
	}
	a.array_of_integers[a.array_length] = '\0'; // ��������� �������

	return input;
}

/*************************************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

/*************************************************************/