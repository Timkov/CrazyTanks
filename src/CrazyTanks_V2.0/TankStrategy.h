#ifndef TANK_STRATEGY_H
#define TANK_STRATEGY_H

#include <ctime>
#include "Unit.h"
#include "Field.h"


class TankStrategy
{

public:

  virtual typeh::Direction chooseDirection (const Unit& player, const Unit& gold, 
                                                         const int& x, const int& y) const = 0;
};

#endif //TANK_STRATEGY_H