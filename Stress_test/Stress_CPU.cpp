#include "Stress_CPU.h"

using namespace std;
// problème avec %

Stress_CPU::Stress_CPU()
{
}


void Stress_CPU::affichage()
{
//cout << "a"<<a<<"\t"<<"b"<<b<< endl;//"index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


int Stress_CPU::run(int arg_duree,int arg_pourcentage, int arg_taille)
{
duree= arg_duree;

convertion_pourcentage(arg_pourcentage);
taille= arg_taille;
 return duration();
}


void Stress_CPU::utile()
{
calcul();
affichage();
}

void Stress_CPU::calcul()
{
for(int i=0;i<=10000;i++){
    sqrt (rand ());
}
}

