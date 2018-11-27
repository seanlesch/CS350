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
    void testBinary1mil(ofstream &resultsFile);
    void testBinary10mil(ofstream &resultsFile);
    void testBinary100mil(ofstream &resultsFile);

    void testAlphanum1mil(ofstream &resultsFile);
    void testAlphanum10mil(ofstream &resultsFile);
    void testAlphanum100mil(ofstream &resultsFile);

    void testSingle1mil(ofstream &resultsFile);
    void testSingle10mil(ofstream &resultsFile);
    void testSingle100mil(ofstream &resultsFile);

    void testDNA1mil(ofstream &resultsFile);
    void testDNA10mil(ofstream &resultsFile);
    void testDNA100mil(ofstream &resultsFile);

    void testLargeBook(ofstream &resultsFile);
    void testBinaryAlternating(ofstream &resultsFile);
    void testBinaryConsecutive(ofstream &resultsFile);

  public:
    void RunTests();
};

#endif
