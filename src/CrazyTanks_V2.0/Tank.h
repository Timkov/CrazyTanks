#ifndef TANK_H
#define TANK_H

#include <memory>

#include "ActiveUnit.h"
#include "TankStrategy.h"


class Tank : public ActiveUnit
{

public:

 

  Tank (const int& xIn, const int& yIn, const typeh::Direction& dir);

  Tank (const Tank&);

  bool doShot( const Unit& gold, const Unit& player);

  void move (Field& field) override;

  void move (Field& field, const typeh::Direction& newDirection);

  void draw (Field& field);

  void changeStrategy (std::unique_ptr<TankStrategy> newStrategy);

  ~Tank ();

private:

  std::unique_ptr<TankStrategy> strategy_;

};

#endif //TANK_H