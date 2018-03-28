#ifndef BULLET_H
#define BULLET_H

#include "ActiveUnit.h"


class Bullet : public ActiveUnit 
{

public:

  Bullet(const int& xIn, const int& yIn, const typeh::Direction& dir, const bool& ownerIn);

  typeh::UnitSymbol getSymbol(const Field& field);

  void move(Field& field) override;

  bool isPlayerOwner() const;
  
  ~Bullet ();

private:

  bool playerOwns_;

  bool isActivated_;

};

#endif BULLET_H
