 #include "pendulum.h"

class doublependulumrk4: public doublependulum
{
    public:
        doublependulumrk4(const pendulum& upper, const pendulum& lower, double dt=0.005, double g=9.81);

        const char *solverMethod();

        void solveODEs(const double *yin, double *yout);

};
