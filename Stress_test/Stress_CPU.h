#ifndef STRESS_CPU_H
#define STRESS_CPU_H

#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
class Stress_CPU : public Stress
{
    public:
        Stress_CPU();
        int run(int,float,int);
        void affichage();
    protected:
    void utile();
    private:
    void calcul();
    int taille;
};

#endif // STRESS_FICHIER_H

