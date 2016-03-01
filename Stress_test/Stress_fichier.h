#ifndef STRESS_FICHIER_H
#define STRESS_FICHIER_H

#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
class Stress_fichier : public Stress
{
    public:
        Stress_fichier();
        int run(int,int,int);
        void affichage();
    protected:
    void utile();
    private:
    int taille;

};

#endif // STRESS_FICHIER_H

