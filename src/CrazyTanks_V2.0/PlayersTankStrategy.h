#ifndef PLAYER_TANK_STRATEGY
#define PLAYER_TANK_STRATEGY

#include "TankStrategy.h"

class PlayersTankStrategy : public TankStrategy 
{

public:

  typeh::Direction chooseDirection (const Unit& player, const Unit& gold,
                                                const int x, const int y) const;

};

#endif //PLAYER_TANK_STRATEGY