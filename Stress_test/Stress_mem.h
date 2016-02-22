#ifndef STRESS_MEM_H
#define STRESS_MEM_H

#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>




class Stress_mem : public Stress
{
    public:
        Stress_mem();
        void run(int,float,int);
        void affichage();
    protected:
    void utile();
    private:
    void free_mem();
    void mem();

    unsigned long int index;
    int tab[2];
    int taille;

};

#endif // STRESS_MEM_H
