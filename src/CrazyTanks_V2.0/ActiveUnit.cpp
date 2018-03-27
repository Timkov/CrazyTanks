#include "ActiveUnit.h"


ActiveUnit::ActiveUnit (const int& xIn, const int& yIn,  
                        const typeh::Direction& dir) : Unit (xIn, yIn), direction_ (dir)
{ }

 typeh::Direction ActiveUnit::getDirection () const 
{
  return direction_;
}

void ActiveUnit::setDirection (const typeh::Direction& newDirection) 
{
  direction_ = newDirection;
}


void ActiveUnit::move (Field& field)
{

  switch(direction_)
  {

    case  typeh::UP:
      x_--;
      break;

    case  typeh::DOWN:
      x_++;
      break;

    case  typeh::LEFT:
      y_--;
      break;

    case  typeh::RIGHT:
      y_++;

  }
}

ActiveUnit::~ActiveUnit () { }