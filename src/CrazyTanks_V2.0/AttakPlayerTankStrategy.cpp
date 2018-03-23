#include "AttakPlayerTankStrategy.h"

typeh::Direction AttakPlayerTankStrategy::chooseDirection(const Unit& player, 
                                                          const Unit& gold, const int x, const int y) const
{


  if (rand() % 7 == 1)
    return static_cast< typeh::Direction>(rand()%4);

  if (rand() % 2) 
  {

    if (x < player.getX())
      return  typeh::DOWN;

    else 
      return  typeh::UP;
  }
  else 
  {

    if (y < player.getY())
      return  typeh::RIGHT;
    else 
        return typeh::LEFT;
  }

  return typeh::DOWN;

}