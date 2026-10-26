#pragma once
#include <iostream>

class Complex
{
private:
	double re;
	double img;
public:
	Complex(double, double);
	Complex(const Complex& c);
	void afficher() const;
	//Operateurs arithmetiques
	Complex operator+(Complex c) const;
	Complex operator+(double) const;
	Complex operator-(Complex c) const;
	Complex operator-(double) const;
	Complex operator*(Complex c) const;
	Complex operator*(double) const;
	Complex operator/(Complex c) const;
	Complex operator/(double) const;
	//Operateurs logiques
	bool operator==(const Complex& c) const;
	bool operator!=(const Complex& c) const;

	~Complex();

};

