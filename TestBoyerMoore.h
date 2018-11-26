#include "Algorithms.h"
#include "BoyerMoore.h"

class TestBoyerMoore
{
public:
  TestBoyerMoore();
  void ConfirmBadMatch(BoyerMoore * pBm, char testChar, int expected);
  void ConfirmGoodSuffix(BoyerMoore *pBm, char testChar, int expected);
};

