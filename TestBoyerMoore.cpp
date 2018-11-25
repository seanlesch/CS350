#include "Algorithms.h"

TestBoyerMoore::TestBoyerMoore()
{
  int result = 0;
  string pattern = "ANPANMAN";
  string text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  BoyerMoore *bm = new BoyerMoore(pattern);
  
  ConfirmBadMatch(bm, 'A', 1);
  ConfirmBadMatch(bm, 'B', 8);
  ConfirmBadMatch(bm, 'M', 2);
  ConfirmBadMatch(bm, 'N', 3);
  ConfirmBadMatch(bm, 'P', 5);
  ConfirmBadMatch(bm, 'Z', 8);

  ConfirmGoodSuffix(bm, 1, 1);
  ConfirmGoodSuffix(bm, 2, 8);
  ConfirmGoodSuffix(bm, 3, 3);
  ConfirmGoodSuffix(bm, 4, 6);
  ConfirmGoodSuffix(bm, 5, 6);
  ConfirmGoodSuffix(bm, 6, 6);
  ConfirmGoodSuffix(bm, 7, 6);
  ConfirmGoodSuffix(bm, 8, 6);

  result = bm->Search(text);
  delete bm;

  pattern = "babac";
  text = "abbababacba";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;

  bm = new BoyerMoore(pattern);

  ConfirmBadMatch(bm, 'a', 1);
  ConfirmBadMatch(bm, 'b', 2);
  ConfirmBadMatch(bm, 'c', 5);
  ConfirmBadMatch(bm, 'd', 5);

  ConfirmGoodSuffix(bm, 1, 5);
  ConfirmGoodSuffix(bm, 2, 5);
  ConfirmGoodSuffix(bm, 3, 5);
  ConfirmGoodSuffix(bm, 4, 5);
  ConfirmGoodSuffix(bm, 5, 5);

  result = bm->Search(text);
  delete bm;

  pattern = "BARBER";
  text = "JIM_SAW_ME_IN_A_BARBERSHOP";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(pattern);

  ConfirmBadMatch(bm, 'A', 4);
  ConfirmBadMatch(bm, 'B', 2);
  ConfirmBadMatch(bm, 'C', 6);
  ConfirmBadMatch(bm, 'D', 6);
  ConfirmBadMatch(bm, 'E', 1);
  ConfirmBadMatch(bm, 'F', 6);
  ConfirmBadMatch(bm, 'R', 3);
  ConfirmBadMatch(bm, 'Z', 6);

  ConfirmGoodSuffix(bm, 1, 3);
  ConfirmGoodSuffix(bm, 2, 6);
  ConfirmGoodSuffix(bm, 3, 6);
  ConfirmGoodSuffix(bm, 4, 6);
  ConfirmGoodSuffix(bm, 5, 6);
  ConfirmGoodSuffix(bm, 6, 6);

  result = bm->Search(text);
  delete bm;

  pattern = "TCCTAGAGCTT";
  text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(pattern);

  ConfirmBadMatch(bm, 'A', 4);
  ConfirmBadMatch(bm, 'B', 11);
  ConfirmBadMatch(bm, 'C', 2);
  ConfirmBadMatch(bm, 'D', 11);
  ConfirmBadMatch(bm, 'G', 3);
  ConfirmBadMatch(bm, 'T', 1);
  ConfirmBadMatch(bm, 'R', 11);
  ConfirmBadMatch(bm, 'Z', 11);

  ConfirmGoodSuffix(bm, 1, 7);
  ConfirmGoodSuffix(bm, 2, 11);
  ConfirmGoodSuffix(bm, 3, 11);
  ConfirmGoodSuffix(bm, 4, 11);
  ConfirmGoodSuffix(bm, 5, 11);
  ConfirmGoodSuffix(bm, 6, 11);
  ConfirmGoodSuffix(bm, 7, 11);
  ConfirmGoodSuffix(bm, 8, 11);
  ConfirmGoodSuffix(bm, 9, 11);
  ConfirmGoodSuffix(bm, 10, 11);
  ConfirmGoodSuffix(bm, 11, 11);

  result = bm->Search(text);
  delete bm;
}

void TestBoyerMoore::ConfirmBadMatch(BoyerMoore * bm, char testChar, int expected)
{
  int temp = bm->GetBadMatch(testChar);
  string success = (temp == expected) ? " Pass" : " Fail";
  cout << "t(" << testChar << "): Expected=" << expected << ", Actual=" << temp << success << endl;
}

void TestBoyerMoore::ConfirmGoodSuffix(BoyerMoore * bm, char k, int expected)
{
  int temp = bm->GetGoodSuffix(k);
  string success = (temp == expected) ? " Pass" : " Fail";
  cout << "d2: Expected=" << expected << ", Actual=" << temp << success << endl;
}