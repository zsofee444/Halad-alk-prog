#include <cmath>
#include <cassert>

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

doublependulum::doublependulum(const pendulum& upper, const pendulum& lower,double dt, double g) :
    m_theta1(upper.teta),
    m_omega1(upper.omega),
    m_l1(upper.l), m_m1(upper.m),
    m_theta2(lower.teta),
    m_omega2(lower.omega),
    m_l2(lower.l), m_m2(lower.m),
    m_dt(dt), m_g(g), m_time(0.0)
{
}

doublependulum::~doublependulum()
{
}

void doublependulum::update(double newtime)
{
    assert(newtime >= m_time);
    do
    {
        const double yin[Num_eq] = { m_teta1, m_omega1, m_theta2, m_omega2 };
        double yout[Num_eq];

        solveODEs(yin, yout);

        m_teta1 = yout[Teta_1];
        m_omega1 = yout[Omega_1];
        m_theta2 = yout[Teta_2];
        m_omega2 = yout[Omega_2];
    } 
    while ((m_time += m_dt) < newtime);
}

void doublependulum::derivs(const double *yin, double *dydx)
{

    const double delta = yin[Teta_2] - yin[Teta_1];

    // ‘M’ is the total mass of the system, m1 + m2;
    const double M = m_m1 + m_m2;
    
    // Denominator expression for omega1
    double den = M*m_l1 - m_m2*m_l1*cos(delta)*cos(delta);

    // d teta / dt = omega, by definition
    dydx[Teta_1] = yin[Omega_1];
    dydx[Omega_1] = (m_m2*m_l1*yin[Omega_1]*yin[Omega_1]*sin(delta)*cos(delta) + m_m2*m_g*sin(yin[Teta_2])*cos(delta) + m_m2*m_l2*yin[Omega_2]*yin[Omega_2]*sin(delta) - M*m_g*sin(yin[Teta_1])) / den;
    dydx[Teta_2] = yin[Omega_2];

    // Multiply den by the length ratio of the two bobs
    den *= m_l2 / m_l1;

    dydx[Omega_2] = (-m_m2*m_l2*yin[Omega_2]*yin[Omega_2]*sin(delta)*cos(delta)+ M*m_g*sin(yin[Teta_1])*cos(delta) - M*m_l1*yin[Omega_1]*yin[Omega_1]*sin(delta) - M*m_g*sin(yin[Teta_2])) / den;
}
