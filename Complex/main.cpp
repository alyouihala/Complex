#include <iostream>
#include"Complex.h"
using namespace std;
int main()
{
    Complex* c1 = new Complex(8, 4);
    cout << "Le premier complexe est : ";
    c1->afficher();
    
    Complex* c2 = new Complex(4, 2);
    cout << "Le deuxieme complexe est : ";
    c2->afficher();
    
    Complex* c3 = new Complex(*c1 + *c2);
    cout << "La somme C = C1 + C2 = ";
    c3->afficher();
    
    double a = 2;
    Complex c4 = *c3 + a;
    cout << "L'addition de (a="<<a<<") :" << endl;
    cout << " -> a + (C1 + C2) = a + C = ";
    c4.afficher();

    Complex* c5 = new Complex(*c2 - *c1);
    cout << "La difference est : C = C2 - C1 = ";
    c5->afficher();
    
    Complex c4 = *c3 - a;
    cout << "La soustraction de (a=" << a << ") :" << endl;
    cout << " -> (C1 + C2) - a = C - a = ";
    c4.afficher();

    Complex* c6 = new Complex((*c1) * (*c2));
    cout << "Le produit est : C = C1 * C2 = ";
    c6->afficher();

    Complex c7 = (*c6) * a;
    cout << "La multiplication par (a="<<a<<") :" << endl;
    cout << " -> a * (C1 * C2) = a * C = ";
    c7.afficher();

    Complex* c8 = new Complex((*c1) / (*c2));
    cout << "Le quotient est : C = C1 / C2 = ";
    c8->afficher();

    Complex c9 = (*c3) / a;
    cout << "La division par (a=" << a << ") : ";
    c9.afficher();

    if (*c1 == *c2) 
    { cout << "c1 et c2 sont egaux" << endl;
      }else {
      cout << "c1 et c2 ne sont pas egaux" << endl;
    }

    if (*c1 != *c2)
    { cout << "c1 et c2 sont differents" << endl;
      }else {
       cout << "c1 et c2 ne sont pas differents" << endl;
    }
    
    delete c2;
    c2 = nullptr;
    
    delete c1;
    c1 = nullptr;
    
    delete c3;
    c3 = nullptr;
    
    delete c5;
    c5 = nullptr;
    
    delete c6;
    c6 = nullptr;

    delete c8;
    c8 = nullptr;
    
}