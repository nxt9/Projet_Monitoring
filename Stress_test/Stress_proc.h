#ifndef STRESS_PROC_H
#define STRESS_PROC_H
#include "Stress.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Stress_CPU.h"

class Stress_proc
{
    public:
        Stress_proc(int);
        int run(int,int,int);
        void affichage();
    private:
    void kill_stress_cpu();
    void creation_stress();
    int nb_cpu;
    pid_t pid[10];
    int duree;
    int rate;
};

#endif // STRESS_PROC_H
