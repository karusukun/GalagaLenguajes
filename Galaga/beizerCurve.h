#ifndef BEIZERCURVE_H
#define BEIZERCURVE_H


float cubicBeizer(float t, float start, float control1, float control2, float end);

float intermidiatePointY(float y1, float y2);

float intermidiatePointX(float x);

float cuadraticBeizer(float t, float start, float control1, float end);

float linearBeizer(float t, float start, float end);


#endif // BEIZERCURVE_H
