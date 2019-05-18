#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rungekutta.h"

int main(int argc, char *argv[])
{
    int i = 0, NSTEP;
    float h, TMIN, TMAX, TH10, W10, TH20, W20;
    float yin[N], yout[N];
    float *t, *th1, *th2, *w1, *w2;

    TMIN =0; // starting time
    TMAX =10; // ending time
    TH10 = 90; // angle of upper pendulum
    W10 = 0; // angular velocity of upper pendulum
    TH20 = -10; // angle of lower pendulum
    W20 = 0; // angular velocity of lower pendulum
    NSTEP = 1000;

    /* allocate memory for arrays of values */

    t = (float *) malloc(NSTEP*sizeof(float));
    th1 = (float *) malloc(NSTEP*sizeof(float));
    w1 = (float *) malloc(NSTEP*sizeof(float));
    th2 = (float *) malloc(NSTEP*sizeof(float));
    w2 = (float *) malloc(NSTEP*sizeof(float));

    h = (TMAX - TMIN)/(NSTEP - 1.0); //stepsize for integration

    /* Define array of t values */

    for (i = 0; i < NSTEP; i++)
    {
        t[i] = TMIN + h*i;

        /* convert all angles to radians */

        th1[0] = TH10*PI/180.0;
        w1[0] = W10*PI/180.0;
        th2[0] = TH20*PI/180.0;
        w2[0] = W20*PI/180.0;
        
        printf("%f %f %f %f %f\n", t[0], th1[0], w1[0], th2[0], w2[0]);
    }

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
    }
    return 0;
}
