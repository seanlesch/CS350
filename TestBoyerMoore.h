#include <iostream>

class TestBoyerMoore
{
public:
  TestBoyerMoore();
  void ConfirmBadMatch(BoyerMoore * bm, char testChar, int expected);
  void ConfirmGoodSuffix(BoyerMoore *bm, char testChar, int expected);
};
