#include "Algorithms.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include "BoyerMoore.h"

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
  TestRunner();
};

