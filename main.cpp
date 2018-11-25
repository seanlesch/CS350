#include "Algorithms.h"
#include <chrono>
#include <ctime>
#include <fstream>

int main(){
  TestRunner();

// 
  cout << "Brute" << endl;
  brute("the", "Algorithms and complexity.");

  cout << "KMP" << endl;
  kmp("go", "Algorithms and complexity.");

  cout << "Rabin karp" << endl;
  rabinKarp("go", "Algorithms and complexity.", 101);
  generateStrings();

  std::cout << "BoyerMoore" << std::endl;
  TestBoyerMoore testBoyerMoore;

  return 0;
}

void TestRunner(void)
{
  // Get current time stamp to append to filename.
  // Open file for output.
  ofstream resultsFile;

  TestBinarySmallSet(resultsFile);

  TestBinaryLargeSet(resultsFile);

  TestCharSmallSet(resultsFile);

  TestCharLargeSet(resultsFile);

  TestLargeBook(resultsFile);

}


void TestBinarySmallSet(ofstream resultsFile)
{
  // Define Pattern:
  string pattern = "100110010101011101001101101";
  string source;

  // Open file to be searched.
  ifstream f_in;
  f_in.open("binary_data_small.txt");
  if (f_in.is_open()) {
    f_in >> source;
    f_in.ignore(1000, '\n');
  }
  f_in.close();

  resultsFile << "Binary Small Set: ";

  // Search using Brute-Force:
  auto start = std::chrono::high_resolution_clock::now();
  brute(pattern, source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";


  // Search using Rabin-Karp:
  auto start = std::chrono::high_resolution_clock::now();
  rabinKarp(pattern, source, 101);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using KMP:
  auto start = std::chrono::high_resolution_clock::now();
  kmp(pattern, source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << ", ";

  // Search using BoyerMoore:
  auto start = std::chrono::high_resolution_clock::now();
  BoyerMoore *bm = new BoyerMoore(pattern);
  bm->FindFirst(&source);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
  resultsFile << duration << " \n";
}

void TestBinaryLargeSet(ofstream resultsFile)
{

  auto start = std::chrono::high_resolution_clock::now();
  BoyerMoore *bm = new BoyerMoore();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}

void TestCharSmallSet(ofstream resultsFile)
{
  auto start = std::chrono::high_resolution_clock::now();
  BoyerMoore *bm = new BoyerMoore();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}

void TestCharLargeSet(ofstream resultsFile)
{
  auto start = std::chrono::high_resolution_clock::now();
  BoyerMoore *bm = new BoyerMoore();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}

void TestLargeBook(ofstream resultsFile)
{

  auto start = std::chrono::high_resolution_clock::now();
  BoyerMoore *bm = new BoyerMoore();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}
