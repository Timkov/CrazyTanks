#ifndef ATTAK_FORT_TANK_STRATEGY_H
#define ATTAK_FORT_TANK_STRATEGY_H

#include "TankStrategy.h"


class AttakFortTankStrategy : public TankStrategy
{

public:

  typeh::Direction chooseDirection (const Unit& player, const Unit& gold, 
                                                const int& x, const int& y) const;

};

#endif //ATTAK_FORT_TANK_STRATEGY_H