#include <iostream>
#include <windows.h>

#include "View.h"

View::View () 
{
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hStdout, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(hStdout, &cursorInfo);
}

void View::printMenu () const
{
  std::cout << "CrazyTanks game \n\n";
  std::cout << "Press any key to start, ESC to exit \n";
}

void View::printEndMessage (const bool& gameResult) const
{
  system("cls");
  if (gameResult)
    std::cout << "Victory!\n";
  else
    std::cout << "Game over\n";
}

void View::printField (const Field& field, const int& lives, const int& score, const int& time) const 
{

  system("cls");

  for (auto i = 0; i < field.getHeight(); i++)
  {

    for (auto j = 0; j < field.getWidth(); j++)
    {

      std::cout<<field.getCell(i,j);

    }

    std::cout<<"\n";

  }

  std::cout << "Lives: " << lives << "\tscore:" << score << "\t time: "
    << time / 60 << ":" << time % 60 << "\n";
}