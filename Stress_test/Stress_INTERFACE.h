#ifndef STRESS_INTERFACE_H
#define STRESS_INTERFACE_H


#define NB_STRESS 5
#define NB_PARAM 4
#define NB_CPU 4


#include "Stress_mem.h"
#include "Stress_processus.h"
#include "Stress_fichier.h"
#include "Stress_proc.h"
#include "Stress_IO.h"




#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;



class Stress_interface
{
    public:
        Stress_interface();
        void run();

    private:
int tab_param[NB_PARAM][NB_STRESS];
void recuperation();
void sauvegarde();
void start();
void choix_param(int ,int);
void choix_stress();

};

#endif // STRESS_INTERFACE_H
