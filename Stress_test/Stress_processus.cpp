#include "Stress_processus.h"
using namespace std;

Stress_processus::Stress_processus(int arg_nb_processus)
{
nb_processus_cree=0;
nb_processus=arg_nb_processus;
pid=(pid_t*)malloc(nb_processus*sizeof(pid_t));
for(int i=0;i<=nb_processus;i++)
{
pid[i]=0;
}
}

void Stress_processus::affichage()
{
cout << "lol"<< endl;//"index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


int Stress_processus::run(int arg_duree,float arg_pourcentage, int arg_taille)
{
duree= arg_duree;
rate= arg_pourcentage;
nb_processus= arg_taille;
duration();
kill_processus();
}


void Stress_processus::utile()
{
if(nb_processus_cree<nb_processus){
switch (pid[nb_processus_cree]= fork ())
            {
            case 0:   /* child */
while(1){
}
                break;
            case -1:           /* error */

cout << "ERREUR FORK"<<endl;
                break;
            default:           /* parent */
cout << "Stress" <<pid[nb_processus_cree]<<endl;
nb_processus_cree++;
            }
}
}




void Stress_processus::kill_processus()
{
for(int i=0;i<=nb_processus;i++)
{
if (pid[i]!=0){
kill(pid[i],SIGKILL);

}
}
free(pid);
}
