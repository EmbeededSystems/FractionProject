#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Fraction.h"



Fraction::Fraction()
{
    num=0;
    den=1;
}
Fraction::Fraction(int i)
{ num=i;
  den=1;
}
Fraction::Fraction(int num, int den)
{
    this->num=num;
    this->den=den;


}

ostream &operator<< (ostream &out, const Fraction &f) // cout<<f1;
{
    out <<"Le numérateur de cette fraction est : "<< f.num<< endl;
    out <<"Le denumerateur de cette fraction est : "<< f.den<< endl;
    return out;
}

istream &operator>> (istream &in, Fraction &f)
{
     cout << "Tapez le numérateur de cette fraction : "; in>>f.num;
     cout << "Tapez le denumerateur de cette fraction :"; in>>f.den;
     if(f.den == 0) { cout<< "undefined den egal 0"; exit(0);}
     return in;
}

Fraction Fraction::operator+(const Fraction &f) //f1+f2
{
    Fraction x;
    x.num= this->num * f.den + this->den * f.num;
    x.den= this->den * f.den;
    x.normalise();
    return x;
}

Fraction Fraction::operator-(const Fraction &f) //f1+f2
{
    Fraction x;
    x.num= this->num * f.den - this->den * f.num;
    x.den= this->den* f.den;
    x.normalise();
    return x;
}

Fraction Fraction::operator*(const Fraction &f) //f1+f2
{
    Fraction x;
    x.num= this->num * f.num ;
    x.den= this->den* f.den;
    x.normalise();
    return x;
}

Fraction  Fraction::operator/(const Fraction &f) //f1+f2
{
    Fraction x;
    x.num= this->num * f.den;
    x.den= this->den * f.num;
    x.normalise();
    if(f.num == 0) { cout<< "undefined : devided by 0, Check your f2 numerator"; exit(0);}

    return x;
}


int Fraction::pgcd(int x,int y)
{
     int i=0,j=0;
// rendre le nombre x,y positif
    if(x<0){x=-1*x;}
    if(y<0){y=-1*y;}
//déclarer deux tableaux t et d des diviseurs simultanément de x et y
    int t[x],d[y];// ex:  T[20],d[50]
// pour x
    for(i=0;i<x;i++){ t[i]=i+1;} // un tableau d'elements de 1 vers x
    for(i=0 ; i<x ; i++) {if (x%t[i]==0 && t[i] != 0) { t[j] = t[i]; j++; }}
    for(i=j ; i<x ; i++) t[i] = 0;
    /*cout<<"Le tableau t"<<endl;
    for(i=0 ; i<x ; i++) cout << "La valeur numéro " << i << " est " << t[i] << endl; */
//pour y
    i=0;j=0;
    for(i=0;i<y;i++){ d[i]=i+1;} // un tableau de 1 vers y
    for(i=0 ; i<y ; i++) {if (y%d[i]==0 && d[i]!=0) { d[j] = d[i] ; j++; }}
    for(i=j ; i<y ; i++) d[i] = 0;
    /*cout<<"Le tableau d"<<endl;
    for(i=0 ; i<y ; i++) cout << "La valeur numéro " << i << " est " << d[i] << endl;*/

// traitement pgcd
    // pour obtenir le nombre de caractère entre 1 est 20 dans chaque tableau resultant
    i=0,j=0;
    int k, pgcd=1;
    while(t[i]!=0) {i++;} // la taille du tableau t sans les zeros
    while(d[j]!=0) {j++;} // la taille du tableau d sans les zeros
    i=i-1; j=j-1;
    // 2 boucle for pour obtenir le pgcd
    int p;
    for(p=i;p>=0;p--)
    {for(k=0;k<=j;k++)
     {if(d[k] == t[p]){pgcd=t[p]; goto here;}}
    }
    here:
        //cout<< "le pgcd est : " <<pgcd;
        return pgcd;
}
void Fraction::normalise()
 {int a;
  a=pgcd(this->num , this->den);
  this->num = this->num/a;
  this->den = this->den/a;

  if (this->den < 0)
  {this->num = -1 * this->num;
   this->den = -1 * this->den;}
 }



