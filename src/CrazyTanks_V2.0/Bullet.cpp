#include "Bullet.h"


Bullet::Bullet (const int& xIn, const int& yIn, const typeh::Direction& dir, const bool& ownerIn):
                      ActiveUnit (xIn, yIn, dir), playerOwns_ (ownerIn), isActivated_ (false)
{ } 
                                                  
                                             
void Bullet::move (Field& field) 
{

  if(!destroyed_)
  {
    ActiveUnit::move(field);
    isActivated_ = true;
  }

  if (field.getCell(x_, y_) != typeh::EMPTY && isActivated_)
    destroyed_ = true;

}

void Bullet::draw (Field& field)
{

  if (isActivated_) 
  {
    field.setCell(x_, y_, typeh::BULLET);

    if (destroyed_) 
    {
      isActivated_ = false;
    }

  }
    
}

bool Bullet::isPlayerOwner () const { return playerOwns_; }

Bullet::~Bullet () = default;