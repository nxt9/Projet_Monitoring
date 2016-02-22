#include "Stress_proc.h"
using namespace std;

Stress_proc::Stress_proc()
{
 a=1;
 b=1;
}

void Stress_proc::affichage()
{
//cout << "index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


void Stress_proc::run(int arg_duree,float arg_pourcentage, int arg_taille)
{
duree= arg_duree;
rate= arg_pourcentage;
taille= arg_taille;
duration();
}




void Stress_proc::utile()
{
calcul();
cout<<"lol"<<endl;
}

void Stress_proc::calcul()
{
b=b*a;
a++;
}
