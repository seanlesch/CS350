#include "Algorithms.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include "BoyerMoore.h"

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

class TestRunner
{
  public:
    void RunTests();
    void RunTestCase(ofstream &resultsFile, string sourceFile, string pattern, int iterations);
};

#endif
