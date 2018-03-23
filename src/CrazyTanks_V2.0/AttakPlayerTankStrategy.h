#ifndef ATTAK_PLAYER_TANK_STRATEGY_H
#define ATTAK_PLAYER_TANK_STRATEGY_H

#include "TankStrategy.h"

class AttakPlayerTankStrategy : public TankStrategy
{

public:

  typeh::Direction chooseDirection (const Unit& player, const Unit& gold, 
                                                const int x, const int y) const;

};

#endif //ATTAK_PLAYER_TANK_STRATEGY_H