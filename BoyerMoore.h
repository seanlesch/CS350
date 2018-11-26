#include "Algorithms.h"
#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#define SIZE_CHAR (int)(256)

class BoyerMoore 
{
  int * badMatchTable;
  int * goodSuffixTable;
  int * suffixTable;
  string * pattern;
  void generateBadMatchTable(string * pPattern);
  void generateGoodSuffixTable(string * pPattern);
public:
  BoyerMoore(string * pPattern);
  ~BoyerMoore();
  long Search(string * pSource);
  long Search(string * pSource, int offset);
  long FindFirst(string * pSource);
  vector<long> FindAll(string * pSource);
  int GetBadMatch(char letter);
  int GetGoodSuffix(char offset);
};

#endif
