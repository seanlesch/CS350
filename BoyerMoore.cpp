#include "BoyerMoore.h"

/// <summary>
/// Constructor.
/// </summary>
/// <param name="pPattern">The search pattern</param>
BoyerMoore::BoyerMoore(string * pPattern)
{
  pattern = pPattern;

  // Create BadMatchTable from pattern.
  generateBadMatchTable(pPattern);

  // Create GoodSuffixTable from pattern.
  generateGoodSuffixTable(pPattern);
}

/// <summary>
/// Default destructor.
/// </summary>
BoyerMoore::~BoyerMoore()
{
  delete badMatchTable;
  delete suffixTable;
  delete goodSuffixTable;
}

/// <summary>
/// Perform the Boyer-Moore search on the supplied string.
/// </summary>
/// <param name="pSource">The source text</param>
/// <returns>The start position of the found occurrence. -1 if not found.</returns>
long BoyerMoore::Search(string *pSource)
{
  return Search(pSource, 0);
}

/// <summary>
/// Perform the Boyer-Moore search on the supplied string.
/// </summary>
/// <param name="pSource">The source text</param>
/// <param name="offset">Offset into the source text to begin searching</param>
/// <returns>The start position of the found occurrence. -1 if not found.</returns>
long BoyerMoore::Search(string *pSource, int offset)
{
  // Get the length of the pattern
  int patternLen = pattern->length();
  int n = pSource->length();

  /* Searching */
  int j = offset;
  int i = 0;
  while (j <= n - patternLen)
  {
    for (i = patternLen - 1; i >= 0 && (pattern->at(i) == pSource->at(i + j)); --i);
    if (i < 0)
    {
      return j;
      j += goodSuffixTable[0];
    }
    else
      j += max(goodSuffixTable[i], badMatchTable[pSource->at(i + j)] - patternLen + 1 + i);
  }
  return -1;
}

/// <summary>
/// Generate the bad match table. This is the 
/// same table used also by Horspool's algorithm.
/// </summary>
/// <param name="pPattern">The search pattern</param>
void BoyerMoore::generateBadMatchTable(string * pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Allocate and initialize the bad match table with the length of the pattern.
  badMatchTable = new int[SIZE_CHAR];
  for (int index = 0; index < SIZE_CHAR; index++)
  {
    badMatchTable[index] = patternLen;
  }

  // Starting from the left update the bad match table with the offset
  // from the end of the string for each character in the pattern.
  for (int index = 0; index < (patternLen - 1); index++)
  {
    badMatchTable[pPattern->at(index)] = (patternLen - 1) - index;
  }
}

/// <summary>
/// Generate the good suffix table.
/// </summary>
/// <param name="pPattern">The search pattern</param>
void BoyerMoore::generateGoodSuffixTable(string * pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Allocate and fill the suffix table.
  suffixTable = new int[patternLen];

  suffixTable[patternLen - 1] = patternLen;
  int g = patternLen - 1;
  int f = 0;
  for (int i = patternLen - 2; i >= 0; --i)
  {
    if ((i > g) && (suffixTable[i + patternLen - 1 - f] < (i - g)))
    {
      suffixTable[i] = suffixTable[i + patternLen - 1 - f];
    }
    else
    {
      if (i < g)
      {
        g = i;
      }
      f = i;
      while (g >= 0 && pPattern->at(g) == pPattern->at(g + patternLen - 1 - f))
      {
        --g;
      }
      suffixTable[i] = f - g;
    }
  }

  // Allocate and initialize the good suffix and border position tables.
  goodSuffixTable = new int[patternLen];

  for (int i = 0; i < patternLen; ++i)
  {
    goodSuffixTable[i] = patternLen;
  }
  int j = 0;
  for (int i = patternLen - 1; i >= 0; --i)
  {
    if (suffixTable[i] == i + 1)
    {
      for (; j < patternLen - 1 - i; ++j)
      {
        if (goodSuffixTable[j] == patternLen)
        {
          goodSuffixTable[j] = patternLen - 1 - i;
        }
      }
    }
  }
  for (int i = 0; i <= patternLen - 2; ++i)
  {
    goodSuffixTable[patternLen - 1 - suffixTable[i]] = patternLen - 1 - i;
  }
}

/// <summary>
/// Get the associated shift for the supplied character.
/// </summary>
/// <param name="ch">The supplied character</param>
/// <returns>The associated shift</returns>
int BoyerMoore::GetBadMatch(char ch)
{
  return badMatchTable[ch];
}

/// <summary>
/// Get the associated good suffix shift for the supplied offset.
/// </summary>
/// <param name="offset">The supplied offset</param>
/// <returns>The associated shift</returns>
int BoyerMoore::GetGoodSuffix(char offset)
{
  int patternLen = pattern->length();
  return goodSuffixTable[patternLen - offset];
}

/// <summary>
/// Find the first occurrence of the search pattern.
/// Returns the start position of the found occurrence.
/// </summary>
/// <param name="pSource">The source text</param>
/// <returns>The start position of the found occurrence.</returns>
long BoyerMoore::FindFirst(string *pSource)
{
  return Search(pSource);
}

/// <summary>
/// Find all occurrences of the search pattern.
/// Returns a vector of all of the start position of each
//  occurrence.
/// </summary>
/// <param name="pSource">The source text</param>
/// <returns>The start position of the found occurrence.</returns>
vector<long> BoyerMoore::FindAll(string *pSource)
{
  long offset = 0;
  long last = 0;
  vector<long> result;

  do{
    last = offset;
    offset = Search(pSource, offset);
    if (offset != last)
    {
      result.push_back(offset);
    }
  } while (offset != last);

  return result;

}
