#include "BoyerMoore.h"

BoyerMoore::BoyerMoore(string* pPattern)
{
  // Create BadMatchTable from pattern.
  generateBadMatchTable(pPattern);

  // Create GoodSuffixTable from pattern.
  generateGoodSuffixTable(pPattern);
}

long BoyerMoore::Search(string* pSource)
{
  //  Perform the search.
  return -1;
}

/// <summary>
/// Generate the bad match table. This is essentially the 
/// shift table used also by Horspool's algorithm.
/// </summary>
/// <param name="pattern">The search pattern</param>
void BoyerMoore::generateBadMatchTable(string *pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Initialize the BadMatchTable with the length of the pattern.
  for (int iter = 0; iter < SIZE_CHAR; iter++)
  {
    badMatchTable.push_back(patternLen);
  }

  // Starting from the left
  for (int iter = 0; iter < (patternLen - 1); iter++)
  {
    badMatchTable[pPattern->at(iter)] = (patternLen - 1) - iter;
  }
}

/// <summary>
/// Generate the good suffix table.
/// </summary>
/// <param name="pattern">The search pattern</param>
void BoyerMoore::generateGoodSuffixTable(string *pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Initialize the goodSuffixTable and the borderPositionTable.
  for (int charIndex = patternLen; charIndex > 0; charIndex--)
  {
    goodSuffixTable.push_back(patternLen);
    borderPositionTable.push_back(0);
  }

  // Starting from the right, look for matching
  // characters that have a different character infront
  // of them.
  int i = patternLen, j = patternLen + 1;

  borderPositionTable[i] = j;
  while (i > 0)
  {
    while ((j <= patternLen) && (pPattern->at(i - 1) != pPattern->at(j - 1)))
    {
      if (goodSuffixTable[j] == 0)
      {
        goodSuffixTable[j] = j - i;
      }
      j = borderPositionTable[j];
    }
    i--;
    j--;
    borderPositionTable[i] = j;
  }
}

int BoyerMoore::GetBadMatch(char letter)
{
  return badMatchTable[letter];
}

int BoyerMoore::GetGoodSuffix(char offset)
{
  return goodSuffixTable[offset - 1];
}

long BoyerMoore::FindFirst(string* pSource)
{
  long result = -1;

  return result;
}

vector<long> BoyerMoore::FindAll(string* pSource)
{
  vector<long> result;

  return result;

}
