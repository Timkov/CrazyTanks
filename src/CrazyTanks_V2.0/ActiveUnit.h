#ifndef ACTIVE_UNIT_H
#define ACTIVE_UNIT_H

#include "Unit.h"


class ActiveUnit : public Unit
{

public:
  
  ActiveUnit (const int xIn, const int yIn, const typeh::Direction dir);

  virtual void move (Field& field);

  typeh::Direction getDirection () const;

  void setDirection (const typeh::Direction newDirection);

  virtual ~ActiveUnit ();

protected:

  typeh::Direction direction_;

};

#endif //ACTIVE_UNIT_H