#include "Wall.h"

Wall::Wall (const int& xIn, const int& yIn, const bool p) : Unit (xIn, yIn), perimeter_(p)
{ }

typeh::UnitSymbol Wall::getSymbol(const Field& field)
{

  if(destroyed_)
    return typeh::EMPTY;

  if(perimeter_)
  {
    return typeh::PERIMETER_WALL;
  }

  if(field.getCell(x_, y_) == typeh::DESTROYED)
  {
    destroyed_ = true;
  }
  else
    return typeh::WALL;
}

Wall::~Wall () = default;