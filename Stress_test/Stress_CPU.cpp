#include "Stress_CPU.h"

using namespace std;
// problème avec %

Stress_CPU::Stress_CPU()
{
a=1;
b=1;
c=1;
}


void Stress_CPU::affichage()
{
cout << "a"<<a<<"\t"<<"b"<<b<< endl;//"index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


void Stress_CPU::run(int arg_duree,float arg_pourcentage, int arg_taille)
{
duree= arg_duree;
rate= arg_pourcentage;
taille= arg_taille;
duration();
}


void Stress_CPU::utile()
{
calcul();
affichage();
}

void Stress_CPU::calcul()
{
c=a;
b=c*a;
a++;
}

