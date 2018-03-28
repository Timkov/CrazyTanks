#include <cmath>

#include "Tank.h"
#include "TankStrategy.h"
#include "PlayersTankStrategy.h"
#include "AttakFortTankStrategy.h"
#include "AttakPlayerTankStrategy.h"



Tank::Tank (const int& xIn, const int& yIn, const typeh::Direction& dir) : ActiveUnit (xIn, yIn, dir)
{

  strategy_ = std::unique_ptr<TankStrategy>(new PlayersTankStrategy());

}

Tank::Tank (const Tank& tank) : ActiveUnit(tank.getX(), tank.getY(), typeh::DOWN){

  strategy_ = std::unique_ptr<TankStrategy>(new PlayersTankStrategy());

}

bool Tank::doShot (const Unit& gold, const Unit& player) 
{

  direction_ = strategy_->chooseDirection(player, gold,x_,y_);

  return ((rand()%6) == 1);
} 

void Tank::move (Field& field)
{

  if(destroyed_)
    return;

  auto oldX=x_;
  auto oldY=y_;

  ActiveUnit::move(field);

  if (field.getCell(x_, y_) != typeh::EMPTY && field.getCell(x_, y_) != typeh::BULLET) 
  {
    x_ = oldX;
    y_ = oldY;
  } 

  field.setCell(x_, y_, typeh::TANK);

}

void Tank::move (Field& field,const typeh::Direction& newDirection) 
{

  direction_ = newDirection;

  auto oldX = x_;
  auto oldY = y_;

  ActiveUnit::move(field);

  if (field.getCell(x_, y_) != typeh::EMPTY && field.getCell(x_, y_) != typeh::BULLET) 
  {
    x_ = oldX;
    y_ = oldY;
  }
}

typeh::UnitSymbol Tank::getSymbol(const Field& field)
{

  if(!destroyed_)
    return typeh::TANK;
  else
    return typeh::DESTROYED;

}

void Tank::changeStrategy (std::unique_ptr<TankStrategy> newStrategy) 
{
    strategy_ = std::move(newStrategy);
}

Tank::~Tank () { }