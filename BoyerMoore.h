#include "Algorithms.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#define SIZE_CHAR (int)(256)

class BoyerMoore 
{
  vector<int> badMatchTable;
  vector<int> goodSuffixTable;
  vector<int> borderPositionTable;
  void generateBadMatchTable(string* pPattern);
  void generateGoodSuffixTable(string* pPattern);
public:
  BoyerMoore(string* pPattern);
  long Search(string* pSource);
  long FindFirst(string* pSource);
  vector<long> FindAll(string* pSource);
  int GetBadMatch(char letter);
  int GetGoodSuffix(char offset);
};
