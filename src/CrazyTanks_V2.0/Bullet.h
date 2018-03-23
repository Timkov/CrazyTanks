#ifndef BULLET_H
#define BULLET_H

#include "ActiveUnit.h"


class Bullet : public ActiveUnit {

public:

  Bullet(const int xIn, const int yIn, const typeh::Direction dir, const bool ownerIn);

  void draw(Field& field);

  void move(Field& field) override;

  bool isPlayerOwner() const;

private:

  bool playerOwns_;

  bool isActivated_;

};

#endif BULLET_H