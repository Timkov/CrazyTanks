#include "Field.h"


Field::Field() :width_(50),height_(25) {
  for(auto i = 0; i < height_; i++){
    field_.push_back(std::string(width_, typeh::EMPTY));
  }
}

char Field::getCell (const int x, const int y) const {
  return  field_[x][y];
}

void Field::clear () {
  for (auto i = 0; i < height_; i++) {
    field_[i]=std::string(width_, typeh::EMPTY);
  }
}

void Field::setCell (const int x, const int y, const typeh::UnitSymbol symbol) {
  field_[x][y] = symbol;
}

int Field::getWidth () const {
  return width_;
}

int Field::getHeight () const {
  return height_;
}