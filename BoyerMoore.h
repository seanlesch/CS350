#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SIZE_CHAR (int)(256)

class BoyerMoore 
{
  vector<int> badMatchTable;
  vector<int> goodSuffixTable;
  void generateBadMatchTable(string pattern);
  void generateGoodSuffixTable(string pattern);
public:
  BoyerMoore(string pattern);
  int Search(string source);
  int GetBadMatch(char letter);
  int GetGoodSuffix(char letter);
};