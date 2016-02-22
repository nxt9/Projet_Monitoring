#ifndef STRESS_PROC_H
#define STRESS_PROC_H
#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>


class Stress_proc : public Stress
{
    public:
        Stress_proc();
        void run(int,float,int);
        void affichage();
    protected:
    void utile();
    private:
    void calcul();
    int taille;
    unsigned long int a;
    unsigned long int b;
};

#endif // STRESS_PROC_H
