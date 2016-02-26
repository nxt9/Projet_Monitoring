#ifndef STRESS_PROCESSUS_H
#define STRESS_PROCESSUS_H
#include "Stress.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <signal.h>

class Stress_processus : public Stress
{
    public:
        Stress_processus(int);
        int run(int,float,int);
        void affichage();
    protected:
    void utile();
    private:
    void kill_processus();
    void calcul();
    int nb_processus,nb_processus_cree;
    pid_t *pid;
};

#endif // STRESS_PROCESSUS_H
