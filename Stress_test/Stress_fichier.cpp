#include "Stress_fichier.h"

using namespace std;
// problème avec %

Stress_fichier::Stress_fichier()
{

}


void Stress_fichier::affichage()
{
//cout << "lol"<< endl;//"index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


int Stress_fichier::run(int arg_duree,int arg_pourcentage, int arg_taille)
{
duree= arg_duree;
convertion_pourcentage(arg_pourcentage);
taille= arg_taille;
duration();
}


void Stress_fichier::utile()
{
ofstream fichier("test.txt", ios::out | ios::app);
fichier <<"o";
fichier.close();  //déclaration du flux et ouverture du fichier
}

