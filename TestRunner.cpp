#include "TestRunner.h"


void TestRunner::RunTests()
{
  // Get current time stamp to append to filename.
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  // Open file for output.
  ofstream resultsFile;
  resultsFile.open("results.txt", ofstream::out);

  resultsFile << "Test Case | Brute-Force | Rabin-Karp | Knuth-Morris-Pratt | Boyer-Moore\n";

  testBinarySmallSet(resultsFile);
  resultsFile.flush();
  testBinaryMediumSet(resultsFile);
  resultsFile.flush();
  testBinaryLargeSet(resultsFile);
  resultsFile.flush();

  testCharSmallSet(resultsFile);
  resultsFile.flush();
  testCharMediumSet(resultsFile);
  resultsFile.flush();
  testCharLargeSet(resultsFile);
  resultsFile.flush();

  testLargeBook(resultsFile);

  resultsFile.close();
}

void TestRunner::testBinarySmallSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "100110010101011101001101101";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_small.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary Small Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestRunner::testBinaryMediumSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "100110010101011101001101101";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_medium.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary Medium Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestRunner::testBinaryLargeSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "100110010101011101001101101";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_large.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary Large Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestRunner::testCharSmallSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "FKTACXmTu";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("random_data_small.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Random Small Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestRunner::testCharMediumSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "FKTACXmTu";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("random_data_medium.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Random Medium Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestRunner::testCharLargeSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "FKTACXmTu";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("random_data_large.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Random Large Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestRunner::testLargeBook(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "Storm Petrel";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("birds_of_guernsey.txt");
  if (f_in.is_open())
  {
    //f_in.unsetf(ios_base::skipws);
    //f_in >> source;
    //f_in.ignore(1000, '\n');
    char ch;
    while(!f_in.eof())
    {
      f_in.get(ch);
      source += ch;
    };    
  }
  f_in.close();

  resultsFile << "Large Book Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  rabinKarp(&pattern, &source, 101);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore bm(&pattern);
  offset = bm.FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}
