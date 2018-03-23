#include <chrono>
#include<windows.h>
#include<conio.h>

#include "Game.h"

using Clock = std::chrono::steady_clock;

Game::Game () : unitsManager_ (field_){
  srand(time(0));
  startTime_ = Clock::now();
}

void Game::start () {

  const int ESC_KEY_ASCII = 27;
  view_.printMenu();
  char input = _getch();
  int inputAscii = static_cast<int>(input);

  if (inputAscii == ESC_KEY_ASCII)
    return;
  else
    play();

}

void Game::play () {
  int score = 0;
  long long time = 0;

  while (true) {

    time = std::chrono::duration_cast<std::chrono::seconds>
      (Clock::now() - startTime_).count();

    score = unitsManager_.getTanksCount() - unitsManager_.getTanksLeftCount();

    unitsManager_.unitsDoAction(field_);

    unitsManager_.drawUnits(field_);

    view_.printField(field_, unitsManager_.getPlayerLives(), score, time);

    processUserInput ();

    if (unitsManager_.getPlayerLives() <= 0) {
      end(false);
      return;
    }
    if (unitsManager_.getTanksLeftCount() == 0) {
      end(true);
      return;
    }

  }

}

void Game::processUserInput () {

  const int KEY_PRESSED_BIT = 0x8000;
  bool wasInput=false;

  auto startWaitingTime = std::chrono::time_point<Clock>(Clock::now());
  auto wait = std::chrono::duration_cast<std::chrono::milliseconds>
    (Clock::now() - startWaitingTime).count();

  while(wait < delay_){
    
    if(!wasInput){
      wasInput = true;
      if (GetKeyState(VK_UP) & KEY_PRESSED_BIT) {
        unitsManager_.movePlayer(typeh::UP,field_);
      }
      else if (GetKeyState(VK_DOWN) & KEY_PRESSED_BIT) {
        unitsManager_.movePlayer(typeh::DOWN, field_);
      }
      else if (GetKeyState(VK_LEFT) & KEY_PRESSED_BIT) {
        unitsManager_.movePlayer(typeh::LEFT, field_);
      }
      else if (GetKeyState(VK_RIGHT) & KEY_PRESSED_BIT) {
        unitsManager_.movePlayer(typeh::RIGHT, field_);
      }
      else if (GetKeyState(VK_SPACE) & KEY_PRESSED_BIT) {
        unitsManager_.doPlayerShot();
      }
      else if (GetKeyState(VK_ESCAPE) & KEY_PRESSED_BIT) {
        system("pause");
      } else wasInput = false;
    }


    wait = std::chrono::duration_cast<std::chrono::milliseconds>
      (Clock::now() - startWaitingTime).count();
  }
}

void Game::end(bool result) {
  view_.printEndMessage(result);
}