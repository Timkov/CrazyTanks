#include "Unit.h"

Unit::Unit (const int xIn, const int yIn):x_(xIn),y_(yIn),destroyed_(false)
{}

int Unit::getX () const { return x_; }

int Unit::getY () const { return y_; }

void Unit::setDestroyed (const bool newDestroyed) {
 destroyed_ = newDestroyed;
}

bool Unit::isDestroyed () const { return destroyed_; }

Unit::~Unit () = default;