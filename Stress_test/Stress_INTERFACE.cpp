#include "Stress_INTERFACE.h"
using namespace std;

/*              mémoire disque  I/O CPU Processus
type de stress  0/1        0/1  0/1  0/1    0/1
duree           int         int int int     int
rate            int         int int int     int
inc             taille     /    /   /       nb processus




*/

// PROBLEME
Stress_interface::Stress_interface()
{
string pid=to_string((int)getpid());
string cmd1="sudo renice -n -20 -p ";
cmd1=cmd1+pid;
char * b =(char *) malloc(cmd1.size());
strcpy(b, cmd1.c_str());
system(b);

for(int i=0;i<NB_STRESS;i++){
for(int j=0;j<NB_PARAM;j++)
{
tab_param[j][i]=0;
}
}
}

void Stress_interface::choix_stress()
{
int choix=0;
while (choix!=6){
cout << "Quel stress voulez-vous appliquer?"<<endl;
cout << "1 : mémoire"<<endl;
cout << "2 : disque"<<endl;
cout << "3 : I/O"<<endl;
cout << "4 : CPU"<<endl;
cout << "5 : Processus"<<endl;
cout << "6 : Fin choix"<<endl;
cin >> choix;
if((choix==1)||(choix==2)||(choix==3)||(choix==4)||(choix==5)){
tab_param[0][choix-1]=1;
choix_param(choix-1,choix-1);
}
else if (choix==6)
{
cout << "Fin du choix de stress"<<endl;
}
else
{
cout << "Erreur choix stress"<<endl;
}
}
}
void Stress_interface::choix_param(int colonne,int inc)
{
int j;
cout << "De quelle durée est le stress? (nb seconde entière)"<<endl;
cin >> tab_param[1][colonne];

cout << "Quel doit être le pourcentage de stress? (50-100%)"<<endl;
cin >> tab_param[2][colonne];

switch(inc)
{
case 0:
cout << "Quel doit être l'incrément? (taille en Mo)"<<endl;
cin >> j;
tab_param[3][colonne]=j*1000;
break;

case 4:
cout << "Quel doit être l'incrément? (nb_processus)"<<endl;
cin >> tab_param[3][colonne];
break;

default:
break;
}
cout << "Fin du choix des paramètres associés à ce stress"<<endl;
}

void Stress_interface::start()
{
Stress_mem stress_0;
Stress_fichier stress_1;

Stress_IO stress_2;
cout<<" "<<endl;
Stress_proc stress_3(NB_CPU);
Stress_processus stress_4;
pid_t pid[NB_STRESS];
for(int i=0;i<NB_STRESS;i++){
if(tab_param[0][i]==1)
{
switch (pid[i]= fork ())
            {
            case 0:   /* child */

  switch(i)
  {
  case 0:
      cout << "Stress mémoire lancé"<<endl;
      stress_0.run(tab_param[1][i],tab_param[2][i],tab_param[3][i]);
      cout << "Stress mémoire fini"<<endl;
  break;
  case 1:
      cout << "Stress disque lancé"<<endl;
      stress_1.run(tab_param[1][i],tab_param[2][i],tab_param[3][i]);
      cout << "Stress disque fini"<<endl;
  break;
  case 2:
      cout << "Stress IO lancé"<<endl;
      stress_2.run(tab_param[1][i],tab_param[2][i],tab_param[3][i]);
      cout << "Stress IO fini"<<endl;
  break;
  case 3:
      cout << "Stress CPU lancé"<<endl;
      stress_3.run(tab_param[1][i],tab_param[2][i],tab_param[3][i]);
      cout << "Stress CPU fini"<<endl;
  break;
  case 4:
      cout << "Stress processus lancé"<<endl;
      stress_4.run(tab_param[1][i],tab_param[2][i],tab_param[3][i]);
      cout << "Stress processus fini"<<endl;
  break;
  default:
  break;
  }
  exit(1);
  break;
            case -1: /* error */

cout << "ERREUR FORK"<<endl;
                break;
            default:
            break;          /* parent */
            }
}

}
int max=tab_param[1][0];
int index=0;
for (int i=1;i<NB_STRESS;i++)
{
if (tab_param[1][i]>=max)
{
max=tab_param[1][i];
index=i;
}
}
int lol;
waitpid(pid[index],&lol,0);
cout << "Fin du dernier stress"<<endl;
}

void Stress_interface::run()
{
int simu=1;
while (simu!=0)
{
cout<<"1 - Nouvelle simulation"<<endl;
cout<<"2 - Quitter"<<endl;
cin>>simu;
if (simu==2){
exit(1);
}
else
{
for(int i=0;i<NB_STRESS;i++){
for(int j=0;j<NB_PARAM;j++)
{
tab_param[j][i]=0;
}
}
cout<<"1 - Nouvelle configuration"<<endl;
cout<<"2 - Configuration existante"<<endl;
cin>>simu;
if(simu==2)
{
cout<<"Début de la récupération des paramètres"<<endl;
recuperation();
cout<<"Fin de la récupération des paramètres"<<endl;
}
else
{
choix_stress();
sauvegarde();
cout<<"Paramètres de simulation sauvegardés"<<endl;
}
cout<<"Lancement de la simulation"<<endl;
start();
}
}
}



void Stress_interface::sauvegarde()
{
ofstream fichier("config.txt", ios::trunc);

for(int j=0;j<NB_PARAM;j++)
{
for(int i=0;i<NB_STRESS;i++){
fichier <<tab_param[j][i]<<"\t";
}
fichier << "\n";
}
fichier.close();
}

void Stress_interface::recuperation()
{
 ifstream fichier("config.txt", ios::in);

for(int j=0;j<NB_PARAM;j++)
{
for(int i=0;i<NB_STRESS;i++){
fichier >>tab_param[j][i];
//cout <<tab_param[j][i]<<endl;
}
}
fichier.close();
}
