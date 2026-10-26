#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double re, double im)
	:re(re), img(im)
{
}

Complex::Complex(const Complex& c)
	:re(c.re), img(c.img)
{
	//this->re = c.re;
	//this->img = c.img;
}

void Complex::afficher() const
{
	//idee pour supprimer les termes nulles
	//le problleme ici j'obtenu les deux expresions 2-0i,2 et 0-3i,-3i
	//if (this->img == 0) {cout << this->re << endl;}
	//if (this->re == 0) {cout << "i" << this->img << endl;} 
	if (this->img < 0) {
		cout << this->re << "-" << (-1) * this->img << "i" << endl;
	}
	else {
		cout << this->re << "+" << this->img << "i" << endl;
	}
}


Complex Complex::operator+(Complex c) const
{
	//Complex* res = new Complex(0.0, 0.0);
	//res->re = this->re + c.re;
	//res->img = this->img + c.img;
	//return *res;
	//pour eviter la fuite memoire (new san delete) on doit utiliser allocation statique ou le retour du complex lui meme sans passer au copie
	Complex res(0.0, 0.0);
	res.re = this->re + c.re;
	res.img = this->img + c.img;
	return res;
}


Complex Complex::operator+(double a) const
{
	return Complex(re + a, img + 0);
}


Complex Complex::operator-(Complex c) const
{
	//Complex* res = new Complex(0.0, 0.0);
	//res->re = this->re - c.re;
	//res->img = this->img - c.img;
	//return *res;
	Complex res(0.0, 0.0);
	res.re = this->re - c.re;
	res.img = this->img - c.img;
	return res;
}

Complex Complex::operator-(double a) const
{
	return Complex(re - a, img - 0);
}

Complex Complex::operator*(Complex c) const
{
	/*Complex* res = new Complex(0.0, 0.0);
	res->re = (this->re * c.re) - (this->img * c.img);
	res->img = (this->re * c.img) + (this->img * c.re);
	return *res;*/
	Complex res(0.0, 0.0);
	res.re = (this->re * c.re) - (this->img * c.img);
	res.img = (this->re * c.img) + (this->img * c.re);
	return res;

}

Complex Complex::operator*(double a) const
{
	return Complex(a * re, a * img);
}
/*Complex* res = new Complex(0.0, 0.0);
	res->re = a * (this->re);
	res->img = a * (this->img);
	return *res;*/
	//Utilisation de [new] sans [delete] => violation de la memoire

Complex Complex::operator/(Complex c) const {
	double d = (c.re * c.re) + (c.img * c.img);
	Complex res(0.0, 0.0);
	res.re = (((this->re) * (c.re)) + ((this->img) * (c.img))) / d;
	res.img = (((this->img) * (c.re)) - ((this->re) * (c.img))) / d;
	return res;
}
/*Complex* res = new Complex(0.0, 0.0);
res->re = (((this->re) * (c.re)) + ((this->img) * (c.img))) / (((c.re) * (c.re)) + ((c.img)*(c.img)));
res->img = (((this->img) * (c.re)) - ((this->re) * (c.img))) / (((c.re)*(c.re)) + ((c.img)*(c.img)));
return *res ;*/
// Passage par reff :Complex Complex :: operator/(const Complex& c)const {
// on donne l'acces a l'objet sans le copier et sans permettre de le modifier



Complex Complex::operator/(double a) const
{
	return Complex(re / a, img / a);
}



bool Complex::operator==(const Complex& c) const
{
	return this->re == c.re && this->img == c.img;
}

bool Complex::operator!=(const Complex& c) const
{
	return this->re != c.re || this->img != c.img;
}


Complex::~Complex()
{
}
