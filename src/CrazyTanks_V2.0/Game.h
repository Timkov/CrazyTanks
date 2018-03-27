#ifndef GAME_H
#define GAME_H

#include <chrono>

#include "Field.h"
#include "View.h"
#include "UnitsManager.h"


class Game
{

public:

  Game ();

  void start ();

private:

  Field        field_;
  View         view_;
  UnitsManager unitsManager_;

  std::chrono::time_point
           <std::chrono::steady_clock> startTime_;

  const int delay_;

  void play ();

  void processUserInput ();

  void end (const bool result);

};

#endif //GAME_H