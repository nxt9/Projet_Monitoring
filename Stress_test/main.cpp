#include "Stress_mem.h"
#include "Stress_processus.h"
#include "Stress_fichier.h"
#include "Stress_proc.h"
#include "Stress_CPU.h"
#include "Stress_IO.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main()
{
Stress_CPU mem;
mem.run(10,0,10000);
return 0;
}
