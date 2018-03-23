#include "AttakFortTankStrategy.h"

 typeh::Direction AttakFortTankStrategy::chooseDirection(const Unit& player, 
                                                         const Unit& gold, const int x, const int y) const
{

  if (rand() % 5 == 1)
    return static_cast< typeh::Direction>(rand() % 4);

  if(y >= gold.getY() - 3 && y <= gold.getX()+3 && x!=gold.getX())
    return  typeh::DOWN;

  if (y < gold.getY()) 
    return  typeh::RIGHT;
  
  if (y > gold.getX())
    return  typeh::LEFT;
  else 
    return typeh::UP;

}