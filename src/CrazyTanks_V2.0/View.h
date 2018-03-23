#ifndef VIEW_H
#define VIEW_H

#include "Field.h"

class View {

public:

  View ();

  void printField (const Field& field, const int lives, 
                  const int score, const int time)  const;

  void printMenu () const;

  void printEndMessage (const bool gameResult) const;

};

#endif //VIEW_H