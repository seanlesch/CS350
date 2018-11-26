#include "Algorithms.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include "BoyerMoore.h"

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

class TestRunner
{
  void testBinarySmallSet(ofstream &resultsFile);
  void testBinaryMediumSet(ofstream &resultsFile);
  void testBinaryLargeSet(ofstream &resultsFile);
  void testCharSmallSet(ofstream &resultsFile);
  void testCharMediumSet(ofstream &resultsFile);
  void testCharLargeSet(ofstream &resultsFile);
  void testLargeBook(ofstream &resultsFile);
public:
  void RunTests();
};

#endif
