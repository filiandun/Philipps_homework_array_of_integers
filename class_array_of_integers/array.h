#pragma once
#include <iostream>

class Array
{
public:
	Array();
	explicit Array(int* array_of_integers, unsigned long long int array_length);
	Array(const Array& a);

	~Array();

private:
	unsigned long long int array_length = 10;
	int* array_of_integers = nullptr;

public:
	bool comparing_an_integer_with_array(int integer) const; // ������� ��� ��������, ���� �� � ������� �������, ������� �� ����� � ���� ��������

	// ���������� �������� � ���������
	Array operator+(int integer);
	Array operator+=(int integer);

	// ����������� ��������
	Array operator+(Array a) const;
	Array operator+=(Array a);

	// �������� �������� �� ���������
	Array operator-(int integer) const;
	Array operator-=(int integer);

	// �������� ��������
	Array operator/(const Array& a) const;
	Array operator/=(const Array& a);

	// ����������� ��������
	Array operator*(Array& a) const;
	Array operator*=(Array& a);

	// ������������
	Array operator=(const Array& a);

	// ��������� ��������
	bool operator==(Array a) const;

	// ����� � ���� ��������
	friend std::ostream& operator<<(std::ostream& output, const Array& a);
	friend std::istream& operator>>(std::istream& input, Array& a);
};