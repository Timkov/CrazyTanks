#include<ctime>

#include "UnitsManager.h"
#include "AttakPlayerTankStrategy.h"
#include "AttakFortTankStrategy.h"



UnitsManager::UnitsManager (const Field& field) : tanks_(),bullets_(),walls_(),
                              player_(field.getHeight() - 2, field.getWidth()/2 + 5,typeh::UP),
                                gold_(field.getHeight() - 2, field.getWidth() / 2), lives_(3) 
{
  
  srand(time(0));

  auto walls_Length = rand()%(field.getWidth()+field.getHeight())/2+20;

  while(walls_Length > 0)
  {

    auto wx = rand() % (field.getHeight() - 5) + 1;
    auto wy = rand() % (field.getWidth() - 5) + 1;

    if (field.getCell(wx, wy) == typeh::EMPTY)
    {
      walls_.push_back(Wall(wx,wy));
      --walls_Length;
    }
  }

  walls_.push_back(Wall(field.getHeight() - 2, field.getWidth() / 2 + 1));
  walls_.push_back(Wall(field.getHeight() - 2, field.getWidth() / 2 + 2));
  walls_.push_back(Wall(field.getHeight() - 2, field.getWidth() / 2 - 1));
  walls_.push_back(Wall(field.getHeight() - 2, field.getWidth() / 2 - 2));
  walls_.push_back(Wall(field.getHeight() - 3, field.getWidth() / 2 + 1));
  walls_.push_back(Wall(field.getHeight() - 3, field.getWidth() / 2 + 2));
  walls_.push_back(Wall(field.getHeight() - 3, field.getWidth() / 2 - 2));
  walls_.push_back(Wall(field.getHeight() - 3, field.getWidth() / 2 - 1));
  walls_.push_back(Wall(field.getHeight() - 3, field.getWidth() / 2));
  walls_.push_back(Wall(field.getHeight() - 4, field.getWidth() / 2));

  for (auto i = 0; i < field.getHeight(); i++)
  {

    walls_.push_back(Wall(i, 0, true));
    walls_.push_back(Wall(i, field.getWidth()-1, true));

  }

  for (auto i = 0; i < field.getWidth(); i++) 
  {

    walls_.push_back(Wall(0, i,true));
    walls_.push_back(Wall(field.getHeight() - 1, i, true));

  }

  auto tanksCount = rand() % 7 + 2;
  
  tanksLeft_ = tanksCount;

  while (tanksCount > 0) 
  {
    auto wx = rand() % (field.getHeight() - 12) + 1;
    auto wy = rand() % (field.getWidth() - 5) + 1;

    if (field.getCell(wx, wy) == typeh::EMPTY)
    {
      tanks_.push_back(Tank(wx, wy, typeh::DOWN));
      --tanksCount;
    }
  }
}

void UnitsManager::drawUnits (Field& field) 
{

  for (auto& wall : walls_)
    field.setCell(wall.getX(),wall.getY(),wall.getSymbol(field));
  
  field.clear();

  for (auto& bullet : bullets_)
    field.setCell(bullet.getX(), bullet.getY(), bullet.getSymbol(field));

  for (auto& wall : walls_)
    field.setCell(wall.getX(), wall.getY(), wall.getSymbol(field));

  for(auto& tank: tanks_)
    field.setCell(tank.getX(), tank.getY(), tank.getSymbol(field));

  field.setCell(player_.getX(), player_.getY(), typeh::PLAYER_TANK);
  field.setCell(gold_.getX(), gold_.getY(), typeh::GOLD);

}

void UnitsManager::unitsDoAction (Field& field)
{

  moveBullets(field);

  for (auto& tank : tanks_)
  {

    if (!tank.isDestroyed())
    {

      tank.move(field);

      if (tank.isDestroyed())
        --tanksLeft_;
    }
  }
  
  for (auto& tank : tanks_)
  {

    if (!tank.isDestroyed()) 
    {

      if(tank.doShot(gold_, player_))
        bullets_.push_back(Bullet(tank.getX(),tank.getY(),tank.getDirection(),false));

      changeTankStrategy(tank, field);
    }

  }

}

void UnitsManager::movePlayer (const typeh::Direction& dir, Field& field) 
{
  
  player_.move(field,dir);
  field.setCell(player_.getX(), player_.getY(), typeh::PLAYER_TANK);

}

void UnitsManager::doPlayerShot ()
{
  bullets_.push_back(Bullet(player_.getX(), player_.getY(), player_.getDirection(), true));
}

int UnitsManager::getTanksLeftCount () const 
{
  return tanksLeft_;
};

int UnitsManager::getTanksCount () const 
{
  return tanks_.size();
}

int UnitsManager::getPlayerLives () const
{
  return lives_;
}

void UnitsManager::moveBullets (Field& field)
{

  for(int i = 0; i < 2; i++) 
  {

    for (auto iter = bullets_.begin(); iter != bullets_.end(); )
    {
      Bullet& bullet = *iter;
      bullet.move(field);

      if(!bullet.isPlayerOwner() && field.getCell(bullet.getX(), bullet.getY()) == typeh::PLAYER_TANK)
        --lives_;

      if (field.getCell(bullet.getX(),bullet.getY())== typeh::TANK) 
      {

        if (bullet.isPlayerOwner())
        {

          for(auto& tank:tanks_)
          {

            if(tank.getX()==bullet.getX() && tank.getY()==bullet.getY())
            {

              if(!tank.isDestroyed())
                --tanksLeft_;
              tank.setDestroyed(true);
              break;  

            }
          }
        } 
      }

      if (field.getCell(bullet.getX(), bullet.getY()) == typeh::GOLD) 
      {
        lives_ = 0;
        return;
      }

      if(field.getCell(bullet.getX(), bullet.getY()) == typeh::WALL)
        field.setCell(bullet.getX(), bullet.getY(), typeh::DESTROYED);

      if(bullet.isDestroyed())
        iter = bullets_.erase(iter);
      else 
        ++iter;
    }
  }
}

void UnitsManager::changeTankStrategy (Tank& tank, const Field& field)
{

  auto x = tank.getX();
  auto y = tank.getY();
  auto xToPlayer = abs(player_.getX() - x);
  auto yToPlayer = abs(player_.getY() - y);

  auto xToFort = abs(field.getWidth() / 2 - x);
  auto yToFort = abs(field.getHeight() - 1 - x);

  if (sqrt( xToPlayer * xToPlayer + yToPlayer * yToPlayer) > sqrt(xToFort * xToFort + yToFort * yToFort))
    tank.changeStrategy(std::unique_ptr<TankStrategy>(new AttakFortTankStrategy()));
  else
    tank.changeStrategy(std::unique_ptr<TankStrategy>(new AttakPlayerTankStrategy()));

}