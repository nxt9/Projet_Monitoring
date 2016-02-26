#include "Stress_IO.h"

using namespace std;
// problème avec %

Stress_IO::Stress_IO()
{
}


void Stress_IO::affichage()
{
//cout << "a"<<a<<"\t"<<"b"<<b<< endl;//"index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


int Stress_IO::run(int arg_duree,float arg_pourcentage, int arg_taille)
{
duree= arg_duree;
rate= arg_pourcentage;
taille= arg_taille;
return duration();
}


void Stress_IO::utile()
{
io();
affichage();
}

void Stress_IO::io()
{
sync ();
}

