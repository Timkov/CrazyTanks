#include "Wall.h"

Wall::Wall (const int xIn, const int yIn, const bool p) : Unit (xIn, yIn), perimeter_(p)
{ }

void Wall::draw(Field& field) {
  if(destroyed_)
    return;

  if(perimeter_){
    field.setCell(x_, y_, typeh::PERIMETER_WALL);
    return;
  }

  if(field.getCell(x_, y_) == typeh::DESTROYED){
    destroyed_ = true;
  }
  else
    field.setCell(x_, y_, typeh::WALL);
}