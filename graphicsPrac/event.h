#ifndef _EVENT_H_
#define _EVENT_H_
#include <iostream>
#include <GL/freeglut.h>
#include "telemDisplay.h"
#include "graphics.h"

using namespace std;

#define ESCAPE_KEY 27
#define RETURN_KEY 13

class Event
{
public:
   virtual void doAction(TelemDisplay &) = 0;
   virtual ~Event();
};


class DisplayEvent : public Event
{
public:
   void doAction(TelemDisplay &);
};

class KeyboardEvent : public Event
{
   /// The key involved in this event
   unsigned char key;
   /// The x-location of where the event took place
   int xLoc;
   /// The y-location of where the event took place
   int yLoc;

public:
   /// Constructor
   KeyboardEvent(unsigned char, int, int);

   void doAction(TelemDisplay &);
};

class ReshapeEvent : public Event
{
   int width;
   int height;
public:
   ReshapeEvent(int, int);

   void doAction(TelemDisplay &);
};

class ProgStart : public Event
{
public:
   void doAction(TelemDisplay &);
};

#endif
