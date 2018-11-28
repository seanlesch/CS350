#include "TestRunner.h"

/// <summary>
/// Run all test cases.
/// </summary>
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

  resultsFile << "Test Case, Brute-Force, Rabin-Karp, Knuth-Morris-Pratt, Boyer-Moore\n";

  // ------------------------------------------------------------
  cout << "Testing Binary Data:\n";
  
  cout << "Testing not found - worst case.\n";
  string pattern = generateSingleChar(100);
  RunTestCase(resultsFile, "binary_data_1mil.txt", pattern);
  resultsFile.flush();
  RunTestCase(resultsFile, "binary_data_10mil.txt", pattern);
  resultsFile.flush();
  RunTestCase(resultsFile, "binary_data_100mil.txt", pattern);
  resultsFile.flush();

  cout << "Testing string found case.\n";
  pattern = "110101111001111100101001100011111100101010010110010001000111101101100010110111010111100101010101111001101011111110001";
  RunTestCase(resultsFile, "binary_data_1mil.txt", pattern);
  resultsFile.flush();
  pattern = "11111100100000001010111010000111011110111111000110001001111000010100111111001001010011101110110100100111000101";
  RunTestCase(resultsFile, "binary_data_10mil.txt", pattern);
  resultsFile.flush();
  pattern = "0010101101010111011011001110010011101101000111111101011011010011101111001010001011011100011100111011";
  RunTestCase(resultsFile, "binary_data_100mil.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "Testing Random Character Data:\n";

  cout << "Testing not found - worst case.\n";
  pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
  RunTestCase(resultsFile, "Alphanum_1mil.txt", pattern);
  resultsFile.flush();
  pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
  RunTestCase(resultsFile, "Alphanum_10mil.txt", pattern);
  resultsFile.flush();
  pattern = "qJFgPUMNdwP6ZeH8E6p8iLi101RFgqu9RQgoDsuNJLATvaQyJQ3PrFtDtzPflRuOtJbr4qQR6KOaOTlPv7Qp9e3xCAJWhsGqP3Wz0Sl1agugxRamF";
  RunTestCase(resultsFile, "Alphanum_100mil.txt", pattern);
  resultsFile.flush();

  cout << "Testing string found case.\n";
  pattern = "JQ9WGmFTjYxhPnKuvKDMWWCzSva58kqOgBkfeTiSMqiKDFFiJOrURRQshup7XA41rUDzVlPEhocJumaEV4y6J6JKdA9KY3yesww0Mfv9onpQCTkwJ";
  RunTestCase(resultsFile, "Alphanum_1mil.txt", pattern);
  resultsFile.flush();
  pattern = "29Z2F8XqGjg8GGaYUnDBBVzA0YmnJNq20Jr8Ncc0AeoQ7P39d8LE5ge0BkAEHXaPlFh8UYttN7BynTWaecgCI48HPJG8GNmQRqzDhLIry1RvOZ9Vm";
  RunTestCase(resultsFile, "Alphanum_10mil.txt", pattern);
  resultsFile.flush();
  pattern = "vtpkkzgFty80GILAtQOPRNM24LyZI7N07XIxPE0V5Bf8hNg0LY22sbCObU1yHzlS16jUsogGnKxzJExrwubldCXlQzX6F9Jmgeb8";
  RunTestCase(resultsFile, "Alphanum_100mil.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "Testing Single Character Data:\n";

  pattern = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  RunTestCase(resultsFile, "Single_1mil.txt", pattern);
  resultsFile.flush();
  pattern = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  RunTestCase(resultsFile, "Single_10mil.txt", pattern);
  resultsFile.flush();
  pattern = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  RunTestCase(resultsFile, "Single_100mil.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "Testing DNA Data:\n";

  cout << "Testing not found - worst case.\n";
  pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  RunTestCase(resultsFile, "DNA_1mil.txt", pattern);
  resultsFile.flush();
  pattern = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
  RunTestCase(resultsFile, "DNA_10mil.txt", pattern);
  resultsFile.flush();
  pattern = "ATAGTATGGTAAGCCTTCGGAATGCGGTTTTCCATGCGACACGAGAGCGCCTCTACTAAGTAGGTAACGGTTGACGGTGTGGAGGGCAGATGTGTGTTACGATACAAGGTTTCTTCAGTACGCCGGGTCCTTGATAGCATGGG";
  RunTestCase(resultsFile, "DNA_100mil.txt", pattern);
  resultsFile.flush();

  cout << "Testing string found case.\n";
  pattern = "CCCGACTGATGTAAAAAGTTAAGATGTTTGGATGGATAAATGACTAGGCGCTATACCGTAGAGGAATCTGAGGCCTGTCCTTTGTAAGCACTGCGGGGTAACTGTTACATAAAGG";
  RunTestCase(resultsFile, "DNA_1mil.txt", pattern);
  resultsFile.flush();
  pattern = "CAGTTTCGCATGACATTACAATCTGCCATCAACCAGTCCCGCTTCTGTAGCATAGTATTATCAGGCTACTCTCAAATGATGGCCGTGACAATTATTCTTTCATGGACAATCCGTC";
  RunTestCase(resultsFile, "DNA_10mil.txt", pattern);
  resultsFile.flush();
  pattern = "CACTTTCTGATCGGAGATTACAAGTTGAAATATCGTGACGAACCAGTCGGTTACCTTTAGAGTAAACCCCCACGCTCATCTCAGAATGCGCTAGACGAGT";
  RunTestCase(resultsFile, "DNA_100mil.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "Testing Spoken English:\n";

  pattern = "Storm Petrel";
  RunTestCase(resultsFile, "birds_of_guernsey.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "Testing Binary Consecutive:\n";

  pattern = "00000000000000000000000000000000000000001111111111111111111111111111111111111111";
  RunTestCase(resultsFile, "binary_consecutive_data.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "Testing Binary Alternating:\n";

  pattern = "110101010101010101010101010101010101010101010101";
  RunTestCase(resultsFile, "binary_alternating_data.txt", pattern);
  resultsFile.flush();

  // ------------------------------------------------------------
  cout << "All tests completed.\n";
  resultsFile.close();
}

/// <summary>
/// Run the specified test case.
/// </summary>
/// <param name="resultsFile">Where to save the results.</param>
/// <param name="sourceFile">The source text to be searched.</param>
/// <param name="pattern">The specified search pattern.</param>
void TestRunner::RunTestCase(ofstream &resultsFile, string sourceFile, string pattern)
{
  // Define Pattern:
  string sourceText;
  // Open file to be searched.
  cout << "Opening source file - " << sourceFile << " - ";
  ifstream f_in;
  //We have to change the file read in for this one case to
  //handle spaces.
  if(sourceFile == "birds_of_guernsey.txt"){
    f_in.open(sourceFile);
    if (f_in.is_open())
    {
      char ch;
      cout << "Reading source text - ";
      while(!f_in.eof())
      {
        f_in.get(ch);
        sourceText += ch;
      };    
    }
  f_in.close();
  }else{
    f_in.open(sourceFile);
    if (f_in.is_open())
    {
      f_in >> sourceText;
      f_in.ignore(1000, '\n');
      cout << "Reading source text - ";
    }
    f_in.close();
  }
  cout << "done.\n";

  resultsFile << sourceFile << ", ";

  // Search using Brute-Force:
  cout << "Running Brute force - ";
  auto start = std::chrono::high_resolution_clock::now();
  long locBrute = brute(&pattern, &sourceText);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done.\n";

  long locRK = 0;
  // Search using Rabin-Karp:
  if(sourceFile[0]=='A'){
  cout << "Running Rabin-Karp - ";
  start = std::chrono::high_resolution_clock::now();
  locRK = rabinKarp(&pattern, &sourceText, 1059749, 62);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done.\n";
  }
  if(sourceFile[2]=='n' || sourceFile[0]=='S'){
  cout << "Running Rabin-Karp - ";
  start = std::chrono::high_resolution_clock::now();
  locRK = rabinKarp(&pattern, &sourceText, 1059749, 2);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done.\n";
  }

  if(sourceFile[0]=='D'){
  cout << "Running Rabin-Karp - ";
  start = std::chrono::high_resolution_clock::now();
  locRK = rabinKarp(&pattern, &sourceText, 1059749, 4);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done.\n";
  }

  if(sourceFile == "birds_of_guernsey.txt"){
  cout << "Running Rabin-Karp - ";
  start = std::chrono::high_resolution_clock::now();
  locRK = rabinKarp(&pattern, &sourceText, 1059749, 256);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done.\n";
  }
  
  

  // Search using KMP:
  cout << "Running Knuth-Morris-Pratt - ";
  start = std::chrono::high_resolution_clock::now();
  long locKMP = kmp(&pattern, &sourceText);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";
  cout << "done.\n";

  // Search using BoyerMoore:
  cout << "Running Boyer-Moore - ";
  start = std::chrono::high_resolution_clock::now();
  BoyerMoore *bm = new BoyerMoore(&pattern);
  long locBM = bm->FindFirst(&sourceText);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
  cout << "done.\n";
  resultsFile << "Found at, " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
  cout << "Search result: " << locBrute << ", " << locRK << ", " << locKMP << ", " << locBM << endl;
}

