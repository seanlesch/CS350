#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

#define SIZE_CHAR (int)(256)

class BoyerMoore 
{
  vector<int> badMatchTable;
  vector<int> goodSuffixTable;
  vector<int> borderPositionTable;
  void generateBadMatchTable(string* pattern);
  void generateGoodSuffixTable(string* pattern);
public:
  BoyerMoore(string* pattern);
  int Search(string* source);
  long FindFirst(string* pSource);
  vector<long> FindAll(string* pSource);
  int GetBadMatch(char letter);
  int GetGoodSuffix(char offset);
};