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
	bool comparing_an_integer_with_array(int integer) const; // ôóíêöèÿ äëÿ ïğîâåğêè, åñòü ëè â ìàññèâå ıëåìåíò, êîòîğûé ìû õîòèì ê íåìó äîáàâèòü

	// ÄÎÁÀÂËÅÍÈÅ İËÅÌÅÍÒÀ Â ÌÍÎÆÅÑÒÂÎ
	Array operator+(int integer);
	Array operator+=(int integer);

	// ÎÁÚÅÄÈÍÅÍÈÅ ÌÍÎÆÅÑÒÂ
	Array operator+(Array a) const;
	Array operator+=(Array a);

	// ÓÄÀËÅÍÈÅ İËÅÌÅÍÒÀ ÈÇ ÌÍÎÆÅÑÒÂÀ
	Array operator-(int integer) const;
	Array operator-=(int integer);

	// ĞÀÇÍÎÑÒÜ ÌÍÎÆÅÑÒÂ
	Array operator/(const Array& a) const;
	Array operator/=(const Array& a);

	// ÏÅĞÅÑÅ×ÅÍÈÅ ÌÍÎÆÅÑÒÂ
	Array operator*(Array& a) const;
	Array operator*=(Array& a);

	// ÏĞÈÑÂÀÈÂÀÍÈÅ
	Array operator=(const Array& a);

	// ÑĞÀÂÍÅÍÈÅ ÌÍÎÆÅÑÒÂ
	bool operator==(Array a) const;

	// ÂÛÂÎÄ È ÂÂÎÄ ÌÍÎÆÅÑÒÂ
	friend std::ostream& operator<<(std::ostream& output, const Array& a);
	friend std::istream& operator>>(std::istream& input, Array& a);
};