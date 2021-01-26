#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <GL/freeglut.h>

const float Black[] = { 0.0, 0.0, 0.0 };
const float Red[]   = { 1.0, 0.0, 0.0 };
const float Green[] = { 0.0, 1.0, 0.0 };
const float Blue[]  = { 0.0, 0.0, 1.0 };
const float Magenta[]   = { 1.0, 0.0, 1.0 };
const float Cyan[]  = { 0.0, 1.0, 1.0 };
const float Yellow[]    = { 1.0, 1.0, 0.0 };
const float White[] = { 1.0, 1.0, 1.0 };
const float Orange[] = { 1.0, 0.5, 0.0 };
const float Gray[] = {.55, .55, .55};
const float DarkGray[] = { .32, .32, .32};

void DrawFilledRectangle(float x1, float y1, float x2, float y2,
   const float color[]);
void DrawTextString(std::string str, int x, int y, const float color[]);

#endif
