#ifndef WALL_H
#define WALL_H

#include "Unit.h"

class Wall : public Unit
{

public:

  Wall (const int& xIn, const int& yIn, const bool p = false);

  typeh::UnitSymbol getSymbol (const Field& field);

  ~Wall ();

private:

  bool perimeter_;

};

#endif WALL_H