#ifndef MONITORING_SAUVEGARDE_H
#define STRESS_INTERFACE_H


#define TAILLE_TAMPON 500



#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


using namespace std;



class Monitoring_sauvegarde
{
    public:
        Monitoring_sauvegarde(int);
        ~Monitoring_sauvegarde();
        int sauvegarde(float*);
    private:
        int index;
        int nb_mesure;
        float** tab_param;
int recuperation();
int enregistrement();
int buffer(float*);
};

#endif // MONITORING_SAUVEGARDE_H
