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
  cout << "Testing Binary Data:\n";


  testBinary100mil(resultsFile);
  resultsFile.flush();

  testBinary1mil(resultsFile);
  resultsFile.flush();
  
  testBinary10mil(resultsFile);
  resultsFile.flush();

  cout << "Testing Random Character Data:\n";

  
  testAlphanum100mil(resultsFile);
  resultsFile.flush();

  testAlphanum1mil(resultsFile);
  resultsFile.flush();

  testAlphanum10mil(resultsFile);
  resultsFile.flush();

  cout << "Testing single character data\n";

    testSingle100mil(resultsFile);
  resultsFile.flush();

    testSingle1mil(resultsFile);
  resultsFile.flush();

    testSingle10mil(resultsFile);
  resultsFile.flush();

  cout << "Testing DNA Data:\n";
  
  testDNA100mil(resultsFile);
  resultsFile.flush();

    testDNA1mil(resultsFile);
  resultsFile.flush();
  testDNA10mil(resultsFile);
  resultsFile.flush();
 

    cout << "Testing Spoken English\n";
  testLargeBook(resultsFile);
  resultsFile.close();

  cout << "All tests completed.\n";
}


void TestRunner::testBinary100mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = generateSingleChar(100);
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary 100mil, ";

  // Search using Brute-Force:
  cout << "brute\n";
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done\n";

  // Search using Rabin-Karp:
  cout << "rk\n";
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  cout << "kmp\n";
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  cout << "bm\n";
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testBinary100milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "0010101101010111011011001110010011101101000111111101011011010011101111001010001011011100011100111011";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary 100mil, ";

  // Search using Brute-Force:
  cout << "brute\n";
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done\n";

  // Search using Rabin-Karp:
  cout << "rk\n";
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  cout << "kmp\n";
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  cout << "bm\n";
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testBinary1mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = generateSingleChar(100);
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testBinary1milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "110101111001111100101001100011111100101010010110010001000111101101100010110111010111100101010101111001101011111110001";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testBinary10mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = generateSingleChar(100);
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_10mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary 10mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testBinary10milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "11111100100000001010111010000111011110111111000110001001111000010100111111001001010011101110110100100111000101";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_10mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary 10mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}
void TestRunner::testBinaryConsecutive(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "00000000000000000000000000000000000000001111111111111111111111111111111111111111";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_consecutive_data.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary Consecutive Set, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testBinaryAlternating(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "110101010101010101010101010101010101010101010101";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_alternating_data.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary Alternating Set, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}


void TestRunner::testAlphanum100mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Alphanum_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Alphanum 100mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 64);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testAlphanum100milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "vtpkkzgFty80GILAtQOPRNM24LyZI7N07XIxPE0V5Bf8hNg0LY22sbCObU1yHzlS16jUsogGnKxzJExrwubldCXlQzX6F9Jmgeb8";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Alphanum_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Alphanum 100mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 64);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testAlphanum1mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Alphanum_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Alphanum 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 64);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testAlphanum1milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "JQ9WGmFTjYxhPnKuvKDMWWCzSva58kqOgBkfeTiSMqiKDFFiJOrURRQshup7XA41rUDzVlPEhocJumaEV4y6J6JKdA9KY3yesww0Mfv9onpQCTkwJ";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Alphanum_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Alphanum 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 64);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testAlphanum10mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Alphanum_10mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Alphanum 10mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 64);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testAlphanum10milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "29Z2F8XqGjg8GGaYUnDBBVzA0YmnJNq20Jr8Ncc0AeoQ7P39d8LE5ge0BkAEHXaPlFh8UYttN7BynTWaecgCI48HPJG8GNmQRqzDhLIry1RvOZ9Vm";
  string source;
  long offset = -1;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Alphanum_10mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Alphanum 10mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 64);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
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

  resultsFile << "Large Book Set, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 256);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}



void TestRunner::testSingle100mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Single_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Single 100mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}


void TestRunner::testSingle1mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Single_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Single 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testSingle10mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Single_10mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Single 10mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}



void TestRunner::testDNA100mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA 100mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 4);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testDNA100milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "CACTTTCTGATCGGAGATTACAAGTTGAAATATCGTGACGAACCAGTCGGTTACCTTTAGAGTAAACCCCCACGCTCATCTCAGAATGCGCTAGACGAGT";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_100mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA 100mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 4);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testDNA1mil(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 4);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testDNA1milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "CCCGACTGATGTAAAAAGTTAAGATGTTTGGATGGATAAATGACTAGGCGCTATACCGTAGAGGAATCTGAGGCCTGTCCTTTGTAAGCACTGCGGGGTAACTGTTACATAAAGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_1mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA 1mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 4);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

void TestRunner::testDNA10milFound(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "CAGTTTCGCATGACATTACAATCTGCCATCAACCAGTCCCGCTTCTGTAGCATAGTATTATCAGGCTACTCTCAAATGATGGCCGTGACAATTATTCTTTCATGGACAATCCGTC";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_10mil.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA 10mil, ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using Rabin-Karp:
  start = std::chrono::high_resolution_clock::now();
  long locRK = rabinKarp(&pattern, &source, 101, 4);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  start = std::chrono::high_resolution_clock::now();
  //boyerMoore(&source, &pattern);
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&source);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}


