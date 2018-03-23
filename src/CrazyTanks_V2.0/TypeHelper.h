#pragma once

namespace typeh {

  enum Direction {

    UP,LEFT,DOWN,RIGHT

  };

  enum UnitSymbol {

    TANK = '#', PLAYER_TANK = '@', WALL = '=',
    GOLD = '$', PERIMETER_WALL = '-', BULLET = '.',
    EMPTY = ' ', DESTROYED = 'x'

  };

};