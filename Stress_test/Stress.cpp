#include "Stress.h"

using namespace std;
Stress::Stress(){
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


void Stress::convertion_pourcentage(int arg_pourcentage){
if (arg_pourcentage>=50){
rate=1-arg_pourcentage/100;
}
else{
rate=1+arg_pourcentage/100;
}


}
