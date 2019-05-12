struct pendulum
{
    pendulum():
        teta(0.0), omega(0.0), l(0.0), m (0.0)
    {
    }

    pendulum(double _teta, double _omega, double _l, double _m):
        teta(_teta), omega(_omega), l(_l), m(_m)
    {
    }

    double teta; // A kitérsítés szöge.

    double omega;  //szögsebesség

    double l; //a az inga hossza

    double m; // az ingatest tömege.

};

class doublependulum
{
    public:
    doublependulum(const pendulum& upper, const  pendulum& lower, double dt=0.005, double g=9.81);

    virtual ~doublependulum();

    void update(double newtime);

    double teta1()
    {
        return m_teta1;
    }

    double omega1()
    {
        return m_omega1;
    }

    double m1()
    {
        return m_m1;
    }

    double l1()
    {
        return m_l1;
    }

     double teta2()
    {
        return m_teta2;
    }

    double omega2()
    {
        return m_omega2;
    }

    double m2()
    {
        return m_m2;
    }

    double l2()
    {
        return m_l2;
    }

    double time()
    {
        return m_time;
    }

    virtual const char *solverMethod() =0;

    protected:
    enum
    {
        Teta_1,
        Omega_1,
        Teta_2,
        Omega_2,
        Num_eq
    };

    void deriv(const double *yin, double *dydx);

    virtual void solveODEs(const double *yin, double *yout)=0;

    double m_teta1;
    double m_omega1;
    const double m_l1;
    const double m_m1;
    double m_teta2;
    double m_omega2;
    const double m_l2;
    const double m_m2;
    const double m_dt;
    const double m_g;
    double m_time;

};
