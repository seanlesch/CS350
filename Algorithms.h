#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sys/time.h>
#include "BoyerMoore.h"
#include "TestBoyerMoore.h"

using namespace std;

void rabinKarp(string, string, int);
void kmp(string, string);
void brute(string, string);
void generateStrings();
string generateRandomBinary(const int len);
string generateRandomChars(const int len);
string generateRandomDNA(const int len);
