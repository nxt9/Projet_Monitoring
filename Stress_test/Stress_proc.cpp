#include "Stress_proc.h"
using namespace std;

Stress_proc::Stress_proc(int arg_nb_cpu)
{
nb_cpu=arg_nb_cpu;
for(int i;i<=nb_cpu-1;i++)
{
pid[i]=0;
}
}

void Stress_proc::kill_stress_cpu()
{
for(int i=0;i<=nb_cpu-1;i++)
{
if (pid[i]!=0){
kill(pid[i],SIGKILL);
}
}
}

void Stress_proc::affichage()
{
//cout << "index:"<<data[0]<<"\t"<< "Ton:"<<data[1]<<"\t"<< "Toff:"<<data[2]<<"\t" << "Mem:"<<data[3]<<"\t"<<endl;
}


void Stress_proc::creation_stress()
{
Stress_CPU cpu;
for(int i=0;i<=nb_cpu-1;i++)
{
switch (pid[i]= fork ())
            {
            case 0:   /* child */
  //cout << "FILS"<<i<<endl;

  exit(cpu.run(duree,rate,0));
                break;
            case -1: /* error */

cout << "ERREUR FORK"<<endl;
                break;
            default:           /* parent */
//cout << "Stress" <<pid[i]<<endl;
            break;
            }

}
int lol;
waitpid(pid[nb_cpu-1],&lol,0);
}

int Stress_proc::run(int arg_duree, int arg_rate, int taille)
{
rate=arg_rate;
duree=arg_duree;
creation_stress();
return(1);
}

