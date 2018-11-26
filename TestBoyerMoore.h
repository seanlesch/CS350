#include "Algorithms.h"
#include "BoyerMoore.h"

#ifndef TESTBOYERMOORE_H
#define TESTBOYERMOORE_H

class TestBoyerMoore
{
public:
  void RunTests();
  void ConfirmBadMatch(BoyerMoore * pBm, char testChar, int expected);
  void ConfirmGoodSuffix(BoyerMoore *pBm, char testChar, int expected);
};

#endif
