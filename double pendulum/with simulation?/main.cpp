#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "miniwindow.h"
#include "rungekutta.h"


int main(int argc, char *argv[])
{
    MainWindow wnd;
    wnd.mouseHandler([&](Mouse const& m)
    {
        m.x = x; m.y = y;
        m.event == Mouse::Move
        if y=L1, x=0:
                TH10=arcsin(x/l);
                TH20=90
        if y=L2, x=0:
                TH10=arcsin(x/l1);
                TH20=arcsin(x/l2);
        else:
                std::cout<<"Use the mouse and move one of the masses" <<endl
    }

    wnd.resizeHandler([&](int w, int h, StateChange sc){ } );

    wnd.idleHandler([&]
    {
        int i = 0, NSTEP;
        float h, TMIN, TMAX, TH10, W10, TH20, W20;
        float yin[N], yout[N];
        float *t, *th1, *th2, *w1, *w2,

        TMIN =0; //starting time
        TMAX =10;//ending time
        W10 = 0; // angular velocity of upper pendulum
        W20 = 0;// angular velocity of lower pendulum
        NSTEP = 1000;

        /* allocate memory for arrays of values */

        t = (float *) malloc(NSTEP*sizeof(float));
        th1 = (float *) malloc(NSTEP*sizeof(float));
        w1 = (float *) malloc(NSTEP*sizeof(float));
        th2 = (float *) malloc(NSTEP*sizeof(float));
        w2 = (float *) malloc(NSTEP*sizeof(float));

        h = (TMAX - TMIN)/(NSTEP - 1.0);  // stepsize for integration

        /* Define array of t values */

        for (i = 0; i < NSTEP; i++)
        {
            t[i] = TMIN + h*i;

            /* convert all angles to radians */

            th1[0] = TH10*PI/180.0;
            w1[0] = W10*PI/180.0;
            th2[0] = TH20*PI/180.0;
            w2[0] = W20*PI/180.0;

            /* The Runge Kutta Algorythm definition */

            yin[0] = th1[i];
            yin[1] = w1[i];
            yin[2] = th2[i];
            yin[3] = w2[i];
            runge_kutta(t[i], yin, yout, h);
            th1[i+1] = yout[0];
            w1[i+1] = yout[1];
            th2[i+1] = yout[2];
            w2[i+1] = yout[3];
        }

    });

    wnd.exitHandler([&]{ });
    wnd.renderHandler( [&](SoftwareRenderer& r)
    {
        void setpixel(int x0=0, int y0=0, Color red);
        void line1(int x0=0, int y0=0, int x1=0, int y1=L1, F&& f);
        void setpixel(int x1=0, int y1=L1, Color red);
        void line2(int x1=0, int y1=L1, int x2=0, int y2=L1+L2, F&& f);
        void setpixel(int x2=0, int y2=L1+L2, Color red);
        r.forall_pixels([](auto, auto, auto){ return color(255, 255, 255); });
    });

    bool res1 = wnd.open(L"Double Pendulum Simulation", {64, 64}, {640, 640},true, [&]{ return true; });
    return res1 ? 0 : -1;

    for (i = 0; i < NSTEP - 1; i++)
    {
        yin[0] = th1[i];
        yin[1] = w1[i];
        yin[2] = th2[i];
        yin[3] = w2[i];
        runge_kutta(t[i], yin, yout, h);
        th1[i+1] = yout[0];
        w1[i+1] = yout[1];
        th2[i+1] = yout[2];
        w2[i+1] = yout[3];

        printf("%f %f %f %f %f\n", t[i+1], th1[i+1], w1[i+1], th2[i+1], w2[i+1]);

        plt::plot(th1[i],w1[i],const std::Mass1&, r--);
        plt::plot(th2[i],w[i], const std::Mass2&, g--);
        plt.show()

    }

  return 0;

}
