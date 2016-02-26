#include "Stress.h"

using namespace std;
Stress::Stress(){
string pid=to_string((int)getpid());
string cmd1="sudo renice -n -20 -p "+pid;
char * b =(char *) malloc(cmd1.size());
strcpy(b, cmd1.c_str());
system(b);

pause.tv_sec=0;        /* seconds */

}
// CONSTRUCTEUR
int Stress::duration(){
clock_gettime(CLOCK_REALTIME, &start_d);
do{
occupation_rate();
clock_gettime(CLOCK_REALTIME, &stop_d);
T_d=(double)((stop_d.tv_nsec * 1e-9 + stop_d.tv_sec) - (start_d.tv_nsec * 1e-9 + start_d.tv_sec));
}while(T_d<=duree);
return(1);
}


void Stress::occupation_rate(){
clock_gettime(CLOCK_REALTIME, &start_o);
utile();
clock_gettime(CLOCK_REALTIME, &stop_o);
T_o=(double)((stop_o.tv_nsec * 1e-9 + stop_o.tv_sec) - (start_o.tv_nsec * 1e-9 + start_o.tv_sec));

pause.tv_nsec=(T_o*(double)rate)/1e-9;
nanosleep(&pause,0); // problème !!!
}

void Stress::utile(){

}
