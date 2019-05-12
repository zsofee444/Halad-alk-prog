 #include "pendulum.h"

class doublependulumrk4: public doublependulum
{
    public:
        doublependulumrk4(const pendulum& upper, const pendulum& lower, double dt=0.005, double g=9.81);

        const char *solverMethod();

        void solveODEs(const double *yin, double *yout);

};

rk4::rk44(const pendulum& upper, const pendulum& lower, double dt, double g) :
DoublePendulum(upper, lower, dt, g)
{
}

const char *rk4::solverMethod()
{
        return "Runge Kutta (RK4)";
}

void rk4::solveODEs(const double *yin, double *yout)
{
        double dydx[Num_eq], dydxt[Num_eq], yt[Num_eq];
        double k1[Num_eq], k2[Num_eq], k3[Num_eq], k4[Num_eq];

        // First step
       deriv(yin, dydx);
       for (int i = 0; i < Num_eq; ++i)
       {
            k1[i] = m_dt * dydx[i];
            yt[i] = yin[i] + 0.5 * k1[i];
       }
       // Second step
      deriv(yt, dydxt);
      for (int i = 0; i < Num_eq; ++i)
      {
           k2[i] = m_dt * dydxt[i];
           yt[i] = yin[i] + 0.5 * k2[i];
      }
       // Third step
      deriv(yt, dydxt);
      for (int i = 0; i < Num_eq; ++i)
      {
            k3[i] = m_dt * dydxt[i];
            yt[i] = yin[i] + k3[i];
      }
       // Fourth step
      deriv(yt, dydxt);
      for (int i = 0; i < Num_eq; ++i)
      {
            k4[i] = m_dt * dydxt[i];
            yout[i] = yin[i] + k1[i] / 6.0 + k2[i] / 3.0 + k3[i] / 3.0 + k4[i] / 6.0;
      }
}
