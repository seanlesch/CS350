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
  testBinaryMediumSet(resultsFile);
  resultsFile.flush();
  cout << "Medium test complete.\n";
  testBinaryLargeSet(resultsFile);
  resultsFile.flush();
  cout << "Large test complete.\n";

  testBinaryAlternating(resultsFile);
  resultsFile.flush();
  cout << "Alternating test complete.\n";
  testBinaryConsecutive(resultsFile);
  resultsFile.flush();
  cout << "Consecutive test complete.\n";

  cout << "Test Random Character Data:\n";
  testCharMediumSet(resultsFile);
  resultsFile.flush();
  cout << "Medium test complete.\n";
  testCharLargeSet(resultsFile);
  resultsFile.flush();
  cout << "Large test complete.\n";

  cout << "Testing Spoken English\n";
  testLargeBook(resultsFile);

  cout << "Testing single character\n";
  testSingleChar(resultsFile);
  resultsFile.flush();

  cout << "Testing DNA Data:\n";
  testDNAMedium(resultsFile);
  resultsFile.flush();
  cout << "Medium test complete.\n";
  testDNALarge(resultsFile);
  resultsFile.flush();
  cout << "Large test 1 complete.\n";
  testDNALarge2(resultsFile);
  resultsFile.flush();
  cout << "Large test 2 complete.\n";
  testDNALarge3(resultsFile);
  resultsFile.flush();
  cout << "Large test 3 complete.\n";
  
  resultsFile.close();

  cout << "All tests completed.\n";
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

  resultsFile << "Binary Small Set, ";

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

void TestRunner::testBinaryMediumSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = generateRandomBinary(400);
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

  resultsFile << "Binary Medium Set, ";

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

void TestRunner::testBinaryLargeSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
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

  resultsFile << "Binary Large Set, ";

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

void TestRunner::testCharSmallSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
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

  resultsFile << "Random Small Set, ";

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

void TestRunner::testCharMediumSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
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

  resultsFile << "Random Medium Set, ";

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

void TestRunner::testCharLargeSet(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
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

  resultsFile << "Random Large Set, ";

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

void TestRunner::testSingleChar(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("Single_char_data.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Single Char, ";

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

void TestRunner::testDNAMedium(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_medium.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA Medium, ";

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


void TestRunner::testDNALarge(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_large.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA Large 1, ";

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

void TestRunner::testDNALarge2(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_Large_2.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA Large 2, ";

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

void TestRunner::testDNALarge3(ofstream &resultsFile)
{
  // Define Pattern:
  string pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("DNA_Large_3.txt");
  if (f_in.is_open())
  {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "DNA Large 3, ";

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
