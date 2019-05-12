#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define N 4 // number of equations to solve
#define G 9.81 // acc'n due to gravity, in m/s^2
#define L1 1.0 // length of upper pendulum  in m
#define L2 1.0 // length of lower pendulum in m
#define M1 1.0 // mass of upper pendulum  in kg
#define M2 1.0 // mass of lower pendulum  in kg

void runge_kutta(float xin, float yin[], float yout[], float h);
void derivs(float xin, float yin[], float dydx[]);

void derivs(float xin, float yin[], float dydx[])
{

  /* function to fill array of derivatives dydx at xin */

  float den1, den2, del;

  dydx[0] = yin[1];

  del = yin[2]-yin[0];
  den1 = (M1+M2)*L1 - M2*L1*cos(del)*cos(del);
  dydx[1] = (M2*L1*yin[1]*yin[1]*sin(del)*cos(del)
    + M2*G*sin(yin[2])*cos(del) + M2*L2*yin[3]*yin[3]*sin(del)
    - (M1+M2)*G*sin(yin[0]))/den1;

  dydx[2] = yin[3];

  den2 = (L2/L1)*den1;
  dydx[3] = (-M2*L2*yin[3]*yin[3]*sin(del)*cos(del)
    + (M1+M2)*G*sin(yin[0])*cos(del)
    - (M1+M2)*L1*yin[1]*yin[1]*sin(del)
    - (M1+M2)*G*sin(yin[2]))/den2;

  return;

}

void runge_kutta(float xin, float yin[], float yout[], float h)
{
  /* fourth order Runge-Kutta - see e.g. Numerical Recipes */

  int i;
  float hh, xh, dydx[N], dydxt[N], yt[N], k1[N], k2[N], k3[N], k4[N];

  hh = 0.5*h;
  xh = xin + hh;

  derivs(xin, yin, dydx); // first step
  for (i = 0; i < N; i++)
  {
    k1[i] = h*dydx[i];
    yt[i] = yin[i] + 0.5*k1[i];
  }

  derivs(xh, yt, dydxt); //second step
  for (i = 0; i < N; i++)
  {
    k2[i] = h*dydxt[i];
    yt[i] = yin[i] + 0.5*k2[i];
  }

  derivs(xh, yt, dydxt); // third step
  for (i = 0; i < N; i++)
  {
    k3[i] = h*dydxt[i];
    yt[i] = yin[i] + k3[i];
  }

  derivs(xin + h, yt, dydxt); //fourth step
  for (i = 0; i < N; i++)
  {
    k4[i] = h*dydxt[i];
    yout[i] = yin[i] + k1[i]/6. + k2[i]/3. + k3[i]/3. + k4[i]/6.;
  }

  return;

}
