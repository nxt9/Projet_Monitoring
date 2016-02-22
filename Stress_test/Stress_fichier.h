#ifndef STRESS_FICHIER_H
#define STRESS_FICHIER_H

#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
class Stress_fichier : public Stress
{
    public:
        Stress_fichier();
        void run(int,float,int);
        void affichage();
    protected:
    void utile();
    private:
    int taille;

};

#endif // STRESS_FICHIER_H

