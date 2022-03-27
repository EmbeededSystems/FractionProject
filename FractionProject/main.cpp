#include <iostream>
using namespace std;
#include "Fraction.h"

int main()
{
    //Écrire un programme principal qui saisit au clavier 2 fractions f1 et f2 et qui affiche E=(f1+3/4-f2)/(f1*f2-5/8)+4.

    Fraction f1,f2; //
    cout << "Tapez f1 : "<<endl;
    cin >> f1;
    cout << "Tapez f2 : "<<endl;
    cin >> f2;
    // f(a,b) / f(c,0) is 0
    //E :
    Fraction f(3,4), g(5,8), h(4);
    cout << "Solution  de  E = (f1+3/4-f2)/(f1*f2-5/8)+4  est : "  << endl;
    cout << (f1+f-f2) / (f1*f2-g) + h << endl;

    return 1;
}
