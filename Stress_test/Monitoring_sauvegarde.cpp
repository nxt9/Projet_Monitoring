#include "Monitoring_sauvegarde.h"
using namespace std;

Monitoring_sauvegarde::Monitoring_sauvegarde(int arg_nb_mesure)
{
    nb_mesure=arg_nb_mesure;
    index=0;
    tab_param =(int**) malloc(TAILLE_TAMPON* sizeof(*tab_param));

    for(int i=0 ; i < TAILLE_TAMPON ; i++){
        tab_param[i] = (int*)malloc((nb_mesure+1) * sizeof(*(tab_param[i])));

        for(int j=0;j<(nb_mesure+1);j++){
            tab_mesure[i][j]=0;
        }
    }
}

Monitoring_sauvegarde::~Monitoring_sauvegarde()
{
  for(int i=0 ; i < TAILLE_TAMPON ; i++){
        free (tab_param[i]);
    }
  free(tab_param);
}

int Monitoring_sauvegarde::enregistrement()
{
ofstream fichier("Resulats.txt", ios::trunc);
if (fichier){
   for(int i=0;i<index;i++){
        for(int j=0;j<(nb_mesure+1));j++){
        fichier <<tab_mesure[i][j]<<"\t";
    }
    fichier << "\n";
}
fichier.close();
return(1);
}
else{
    return(0);
}
}

int Monitoring_sauvegarde::buffer(float* tab_mes)
{
        for(int j=0;j<(nb_mesure+1);j++){
            tab_param[index][j]=tab_mesure[j];
        }
        return(1);
}

int Monitoring_sauvegarde::sauvegarde(float* tab_mes)
{
buffer(tab_mes);
index++;
if (index==TAILLE_BUFFER)
{
    if(enregistrement()){
        index=0;
        return(1);
    }
    else{
        return(0);
    }
}
}
