#include "Stress_mem.h"
using namespace std;
// problème avec %

Stress_mem::Stress_mem()
{
 index=0;
 tab[0]=(int)NULL;
 tab[1]=(int)NULL;
}
Stress_mem::~Stress_mem()
{
if (index>0){
tab[(index-1)%2]=*(int*)tab[index%2];
free((int*)tab[index%2]);
index--;
}
}

void Stress_mem::affichage()
{
//cout << "index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


int Stress_mem::run(int arg_duree,int arg_pourcentage, int arg_taille)
{
duree= arg_duree;
convertion_pourcentage(arg_pourcentage);
taille= arg_taille;
return duration();
}

void Stress_mem::mem(){
tab[index%2] = (int)malloc((size_t)taille*sizeof(int));
//data[3]=(int)(taille*sizeof(int));
if (index>0)
{
*(int*)tab[index%2] =tab[(index-1)%2];
}
index++;
}


void Stress_mem::utile()
{
mem();
//cout<<"lol"<<endl;
}


void Stress_mem::free_mem(){
if (index>0){
tab[(index-1)%2]=*(int*)tab[index%2];
free((int*)tab[index%2]);
index--;
}
}
