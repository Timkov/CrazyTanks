#ifndef UNIT_H
#define UNIT_H

#include "Field.h"
#include "TypeHelper.h"

class Unit 
{

public:

  Unit ();

  Unit (const int& xIn, const int& yIn);

  int getX () const;

  int getY () const;

  void setDestroyed (const bool& newDestroyed);

  bool isDestroyed () const;

  virtual void draw (Field& f) = 0;

  virtual ~Unit () = 0;

protected:

  int  x_;
  int  y_;
  bool destroyed_;

};

#endif //UNIT_H