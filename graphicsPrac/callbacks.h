/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <iostream>
#include "event.h"
#include "util.h"

using namespace std;

/// Callback for the display event
void display();
/// Callback for the keyboard event
void keyboard(unsigned char key, int x, int y);
/// Callback for the reshape event
void reshape(const int x, const int y);
/// Common function for collecting event information
void utilityCentral(Event *);
#endif

