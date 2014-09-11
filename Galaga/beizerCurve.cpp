#include "beizerCurve.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float cubicBeizer(float t, float start, float control1, float control2, float end)
{
    float omt = (1.0 - t);
    float omt2 = pow(omt,2.0);
    float omt3 = pow(omt,3.0);

    float t2 = pow(t,2.0);
    float t3 = pow(t,3.0);

    return start*omt3 + 3.0*control1*t*omt2 + 3.0*control2*t2*omt + end*t3;
}


float intermidiatePointY(float y1, float y2)
{
    return y1+((y2-y1)/2);
}

float intermidiatePointX(float x)
{
    return x + 100;
}


float cuadraticBeizer(float t, float start, float control1, float end)
{
    float omt = 1-t;
    float omt2 = pow(omt,2.0);
    float t2 = pow(t,2.0);

    return omt2*start + 2.0*t*omt*control1 + t2*end;
}

float linearBeizer(float t, float start, float end)
{
    float omt = 1-t;

    return omt*start + t*end;
}
