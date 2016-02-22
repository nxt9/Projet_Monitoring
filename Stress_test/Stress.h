#ifndef STRESS_H
#define STRESS_H
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

class Stress
{
    public:
        virtual void run(int,float,int)=0;
        virtual void affichage()=0;
        Stress();
    protected:
    virtual void utile();
    void occupation_rate();
    void duration();
    int duree;
    float rate;
    int data[5];
    private:
    struct timespec start_d, stop_d,start_o,stop_o,pause;
    double T_d,T_o;
};
#endif // STRESS_H