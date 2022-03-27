#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>

using namespace std;
class Fraction
{
friend ostream & operator<<(ostream & out, const Fraction &f); // affiche la fraction f
friend istream & operator>>(istream &in, Fraction &f); // saisit au clavier la fraction f
public:
Fraction(); // constructeur par defaut
Fraction(int i); // constructeur initialise fraction par un entier
Fraction(int num,int den); // constructeur initialise fraction par un numerateur et un denominateur
Fraction operator+(const Fraction & f); // Faire la somme de deux fractions
Fraction operator-(const Fraction & f); // Faire la soustration de deux fraction
Fraction operator*(const Fraction & f); // Faire la multiplication de deux fractions
Fraction operator/(const Fraction & f); // Faire la division de deux fractions
private:
int num,den;
int pgcd(int x, int y); // calcul le pgcd de 2 entiers
void normalise(); //  Normalise la fraction. Le dénominateur doit être positif et la fraction irreductible
};
#endif
