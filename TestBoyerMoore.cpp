#include "TestBoyerMoore.h"


void TestBoyerMoore::RunTests()
{
  long result = 0;

  string pattern = "GCAGAGAG";
  string text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  BoyerMoore *bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 1);
  ConfirmBadMatch(bm, 'B', 8);
  ConfirmBadMatch(bm, 'C', 6);
  ConfirmBadMatch(bm, 'D', 8);
  ConfirmBadMatch(bm, 'G', 2);
  ConfirmBadMatch(bm, 'T', 8);
  ConfirmBadMatch(bm, 'Z', 8);

  ConfirmGoodSuffix(bm, 1, 1);
  ConfirmGoodSuffix(bm, 2, 7);
  ConfirmGoodSuffix(bm, 3, 4);
  ConfirmGoodSuffix(bm, 4, 7);
  ConfirmGoodSuffix(bm, 5, 2);
  ConfirmGoodSuffix(bm, 6, 7);
  ConfirmGoodSuffix(bm, 7, 7);
  ConfirmGoodSuffix(bm, 8, 7);

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "ANPANMAN";
  text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);
  
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

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "babac";
  text = "abbababacba";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;

  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'a', 1);
  ConfirmBadMatch(bm, 'b', 2);
  ConfirmBadMatch(bm, 'c', 5);
  ConfirmBadMatch(bm, 'd', 5);

  ConfirmGoodSuffix(bm, 1, 1);
  ConfirmGoodSuffix(bm, 2, 5);
  ConfirmGoodSuffix(bm, 3, 5);
  ConfirmGoodSuffix(bm, 4, 5);
  ConfirmGoodSuffix(bm, 5, 5);

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "BARBER";
  text = "JIM_SAW_ME_IN_A_BARBERSHOP";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 4);
  ConfirmBadMatch(bm, 'B', 2);
  ConfirmBadMatch(bm, 'C', 6);
  ConfirmBadMatch(bm, 'D', 6);
  ConfirmBadMatch(bm, 'E', 1);
  ConfirmBadMatch(bm, 'F', 6);
  ConfirmBadMatch(bm, 'R', 3);
  ConfirmBadMatch(bm, 'Z', 6);

  ConfirmGoodSuffix(bm, 1, 1);
  ConfirmGoodSuffix(bm, 2, 3);
  ConfirmGoodSuffix(bm, 3, 6);
  ConfirmGoodSuffix(bm, 4, 6);
  ConfirmGoodSuffix(bm, 5, 6);
  ConfirmGoodSuffix(bm, 6, 6);

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "ABCBAB";
  text = "JIM_SAW_ME_IN_A_BARBERSHOP";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 1);
  ConfirmBadMatch(bm, 'B', 2);
  ConfirmBadMatch(bm, 'C', 3);
  ConfirmBadMatch(bm, 'D', 6);
  ConfirmBadMatch(bm, 'E', 6);
  ConfirmBadMatch(bm, 'F', 6);
  ConfirmBadMatch(bm, 'R', 6);
  ConfirmBadMatch(bm, 'Z', 6);

  ConfirmGoodSuffix(bm, 1, 1);
  ConfirmGoodSuffix(bm, 2, 2);
  ConfirmGoodSuffix(bm, 3, 4);
  ConfirmGoodSuffix(bm, 4, 4);
  ConfirmGoodSuffix(bm, 5, 4);
  ConfirmGoodSuffix(bm, 6, 4);

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "BAOBAB";
  text = "JIM_SAW_ME_IN_A_BARBERSHOP";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 1);
  ConfirmBadMatch(bm, 'B', 2);
  ConfirmBadMatch(bm, 'C', 6);
  ConfirmBadMatch(bm, 'D', 6);
  ConfirmBadMatch(bm, 'E', 6);
  ConfirmBadMatch(bm, 'F', 6);
  ConfirmBadMatch(bm, 'R', 6);
  ConfirmBadMatch(bm, 'Z', 6);

  ConfirmGoodSuffix(bm, 1, 1);
  ConfirmGoodSuffix(bm, 2, 2);
  ConfirmGoodSuffix(bm, 3, 5);
  ConfirmGoodSuffix(bm, 4, 5);
  ConfirmGoodSuffix(bm, 5, 5);
  ConfirmGoodSuffix(bm, 6, 5);

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "TCCTAGAGCTT";
  text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 4);
  ConfirmBadMatch(bm, 'B', 11);
  ConfirmBadMatch(bm, 'C', 2);
  ConfirmBadMatch(bm, 'D', 11);
  ConfirmBadMatch(bm, 'G', 3);
  ConfirmBadMatch(bm, 'T', 1);
  ConfirmBadMatch(bm, 'R', 11);
  ConfirmBadMatch(bm, 'Z', 11);

  ConfirmGoodSuffix(bm, 1, 2);
  ConfirmGoodSuffix(bm, 2, 1);
  ConfirmGoodSuffix(bm, 3, 10);
  ConfirmGoodSuffix(bm, 4, 10);
  ConfirmGoodSuffix(bm, 5, 10);
  ConfirmGoodSuffix(bm, 6, 10);
  ConfirmGoodSuffix(bm, 7, 10);
  ConfirmGoodSuffix(bm, 8, 10);
  ConfirmGoodSuffix(bm, 9, 10);
  ConfirmGoodSuffix(bm, 10, 10);
  ConfirmGoodSuffix(bm, 11, 10);

  result = bm->FindFirst(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "TCCTAGAGCTT";
  text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 4);
  ConfirmBadMatch(bm, 'B', 11);
  ConfirmBadMatch(bm, 'C', 2);
  ConfirmBadMatch(bm, 'D', 11);
  ConfirmBadMatch(bm, 'G', 3);
  ConfirmBadMatch(bm, 'T', 1);
  ConfirmBadMatch(bm, 'R', 11);
  ConfirmBadMatch(bm, 'Z', 11);

  ConfirmGoodSuffix(bm, 1, 2);
  ConfirmGoodSuffix(bm, 2, 1);
  ConfirmGoodSuffix(bm, 3, 10);
  ConfirmGoodSuffix(bm, 4, 10);
  ConfirmGoodSuffix(bm, 5, 10);
  ConfirmGoodSuffix(bm, 6, 10);
  ConfirmGoodSuffix(bm, 7, 10);
  ConfirmGoodSuffix(bm, 8, 10);
  ConfirmGoodSuffix(bm, 9, 10);
  ConfirmGoodSuffix(bm, 10, 10);
  ConfirmGoodSuffix(bm, 11, 10);

  vector<long> vresult = bm->FindAll(&text);
  cout << "Result: " << result << endl;
  delete bm;

  pattern = "TC";
  text = "GAGATAGATCTCGTAGAGCTTGAGATAGATCTCCTAGAGCTT";
  cout << "Pattern: " << pattern << endl;
  cout << "Text: " << text << endl;
  bm = new BoyerMoore(&pattern);

  ConfirmBadMatch(bm, 'A', 4);
  ConfirmBadMatch(bm, 'B', 11);
  ConfirmBadMatch(bm, 'C', 2);
  ConfirmBadMatch(bm, 'D', 11);
  ConfirmBadMatch(bm, 'G', 3);
  ConfirmBadMatch(bm, 'T', 1);
  ConfirmBadMatch(bm, 'R', 11);
  ConfirmBadMatch(bm, 'Z', 11);

  ConfirmGoodSuffix(bm, 1, 2);
  ConfirmGoodSuffix(bm, 2, 1);
  ConfirmGoodSuffix(bm, 3, 10);
  ConfirmGoodSuffix(bm, 4, 10);
  ConfirmGoodSuffix(bm, 5, 10);
  ConfirmGoodSuffix(bm, 6, 10);
  ConfirmGoodSuffix(bm, 7, 10);
  ConfirmGoodSuffix(bm, 8, 10);
  ConfirmGoodSuffix(bm, 9, 10);
  ConfirmGoodSuffix(bm, 10, 10);
  ConfirmGoodSuffix(bm, 11, 10);

  vresult = bm->FindAll(&text);
  cout << "Result: " << result << endl;
  delete bm;
}

void TestBoyerMoore::ConfirmBadMatch(BoyerMoore * pBm, char testChar, int expected)
{
  int temp = pBm->GetBadMatch(testChar);
  string success = (temp == expected) ? " Pass" : " Fail";
  cout << "t(" << testChar << "): Expected=" << expected << ", Actual=" << temp << success << endl;
}

void TestBoyerMoore::ConfirmGoodSuffix(BoyerMoore *pBm, char k, int expected)
{
  int temp = pBm->GetGoodSuffix(k);
  string success = (temp == expected) ? " Pass" : " Fail";
  cout << "d2: Expected=" << expected << ", Actual=" << temp << success << endl;
}
