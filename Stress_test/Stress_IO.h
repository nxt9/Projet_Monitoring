#ifndef STRESS_IO_H
#define STRESS_IO_H

#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
class Stress_IO : public Stress
{
    public:
        Stress_IO();
        int run(int,float,int);
        void affichage();
    protected:
    void utile();
    private:
    void io();
    int taille;
};

#endif // STRESS_FICHIER_H

