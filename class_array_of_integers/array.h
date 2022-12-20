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
	bool comparing_an_integer_with_array(int integer) const; // ������� ��� ��������, ���� �� � ������� �������, ������� �� ����� � ���� ��������

	// ���������� �������� � ���������
	Array operator+(int integer); // �������� ������
	Array operator+=(int integer); // �������� ������

	// ����������� ��������
	Array operator+(Array a) const; // �������� ������
	Array operator+=(Array a); // �������� ������

	// �������� �������� �� ���������
	Array operator-(int integer); // �������� ������
	Array operator-=(int integer); // �������� ������

	// �������� ��������
	Array operator/(Array& a) const; // �������� ������
	Array& operator/=(const Array a); // �������� ������

	// ����������� ��������
	Array operator*(Array& a) const; // �������� ������
	Array operator*=(Array& a); // �������� ������

	// ������������
	Array operator=(const Array& a); // �������� ������

	// ��������� ��������
	bool operator==(Array a) const; // �������� ������

	// ����� � ���� �������� (�������� ��������)
	friend ostream& operator<<(ostream& output, const Array& a);
	friend istream& operator>>(istream& input, Array& a);
};
/*

1. �� ���� FOR �������� int i, j �� unsigned long long int i, j - �������
2. ����������� CONST � ����������/�������� 
3. ���������� � * � &
4. ������������ main.cpp
5. ���������� operator== � operator= - �������
6. �������� operator>>, ��� ��� ������������� �������� ����� �������

*/