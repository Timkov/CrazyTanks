#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>

#include "TypeHelper.h"


class Field 
{

public:

  Field();

  char getCell ( const int& x, const int& y) const;

  void setCell ( const int& x, const int& y, const typeh::UnitSymbol symbol);

  void clear ();

  int getWidth () const;

  int getHeight () const;

private:

  const int width_;
  const int height_;

  std::vector<std::string> field_;

};

#endif //FIELD_H