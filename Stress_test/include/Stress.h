#ifndef STRESS_H
#define STRESS_H


class Stress
{
    public:
        virtual void run(int arg_max,int arg_temps,int arg_vitesse);
        virtual void affichage();
        Stress(int);
        virtual ~Stress();
    protected:
    private:
    int Vit;
    int Start;
    int Temps;
    int Max;
};

#endif // STRESS_H
