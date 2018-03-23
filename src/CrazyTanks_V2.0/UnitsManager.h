#ifndef UNITS_MANAGER_H
#define UNITS_MANAGER_H

#include <vector>
#include <list>

#include "Tank.h"
#include "Bullet.h"
#include "Wall.h"

class UnitsManager 
{

public:

  UnitsManager (const Field& field);

  void unitsDoAction (Field& field);

  void drawUnits (Field& field);

  void movePlayer (const typeh::Direction dir, Field& field);

  void doPlayerShot ();

  int  getTanksLeftCount () const;

  int  getTanksCount () const;

  int  getPlayerLives () const;

private:

  std::vector <Tank>    tanks_;
  std::list   <Bullet>  bullets_;
  std::list   <Wall>    walls_;

  Tank player_;
  Wall gold_;

  int lives_;
  int tanksLeft_;

  void moveBullets (Field& field);

  void changeTankStrategy (Tank& tank, const Field& field);

};

#endif //UNITS_MANAGER_H