#include "Algorithms.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include "BoyerMoore.h"

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

class TestRunner
{
  private:
    void testBinarySmallSet(ofstream &resultsFile);
    void testBinaryMediumSet(ofstream &resultsFile);
    void testBinaryLargeSet(ofstream &resultsFile);
    void testCharSmallSet(ofstream &resultsFile);
    void testCharMediumSet(ofstream &resultsFile);
    void testCharLargeSet(ofstream &resultsFile);
    void testLargeBook(ofstream &resultsFile);
    void testSingleChar(ofstream &resultsFile);
    void testDNAMedium(ofstream &resultsFile);
    void testDNALarge(ofstream &resultsFile);
    void testDNALarge2(ofstream &resultsFile);
    void testDNALarge3(ofstream &resultsFile);
public:
  void RunTests();
};

#endif
