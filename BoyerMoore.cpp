#include "BoyerMoore.h"

/// <summary>
/// Constructor.
/// </summary>
/// <param name="pPattern">The search pattern</param>
BoyerMoore::BoyerMoore(string * pPattern)
{
  pattern = pPattern;

  // Create bad match table from pattern.
  generateBadMatchTable(pPattern);

  // Create suffix table from pattern.
  generateSuffixTable(pPattern);

  // Create good suffix table from pattern.
  generateGoodSuffixTable(pPattern);
}

/// <summary>
/// Default destructor.
/// </summary>
BoyerMoore::~BoyerMoore()
{
  delete badMatch;
  delete suffix;
  delete goodSuffix;
}

/// <summary>
/// Perform the Boyer-Moore search on the supplied string.
/// </summary>
/// <param name="pSource">The source text</param>
/// <returns>The start position of the found occurrence. -1 if not found.</returns>
long * BoyerMoore::Search(string *pSource)
{
  return Search(pSource, 0);
}

/// <summary>
/// Perform the Boyer-Moore search on the supplied string.
/// </summary>
/// <param name="pSource">The source text</param>
/// <param name="offset">Offset into the source text to begin searching</param>
/// <returns>The start position of the found occurrence. -1 if not found.</returns>
long * BoyerMoore::Search(string *pSource, int offset)
{
  static long result[1];
  long count = 0;

  result[0] = -1;
  result[1] = 0;

  // Get the length of the pattern
  int patternLen = pattern->length();
  int textLen = pSource->length();

  // Only search if the pattern is smaller than or equal to the size of the source text.
  if (patternLen <= textLen)
  {
    int j = offset;
    int i = 0;
    while (j <= textLen - patternLen)
    {
      for (i = patternLen - 1; i >= 0 && (pattern->at(i) == pSource->at(i + j)); --i, ++count);
      if (i < 0)
      {
        result[1] = count;
        result[0] = j;
        return result;
        //j += goodSuffix[0];
      }
      else
      {
        j += max(goodSuffix[i], badMatch[pSource->at(i + j)] - patternLen + 1 + i);
      }
    }
  }

  result[1] = count;
  return result;
}

/// <summary>
/// Generate the bad match table. This is the 
/// same table used also by Horspool's algorithm.
/// </summary>
void BoyerMoore::generateBadMatchTable(string * pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Allocate and initialize the bad match table with the length of the pattern.
  badMatch = new int[SIZE_CHAR];
  for (int index = 0; index < SIZE_CHAR; index++)
  {
    badMatch[index] = patternLen;
  }

  // Starting from the left update the bad match table with the offset
  // from the end of the string for each character in the pattern.
  for (int index = 0; index < (patternLen - 1); index++)
  {
    badMatch[pPattern->at(index)] = (patternLen - 1) - index;
  }
}

/// <summary>
/// Generate the suffixes table.
/// </summary>
void BoyerMoore::generateSuffixTable(string * pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Allocate and initialize the last entry of the suffix table.
  suffix = new int[patternLen];
  suffix[patternLen - 1] = patternLen;

  int prevInner = 0;
  int outer = patternLen - 1;
  int inner = patternLen - 2;

  // Scan through the pattern looking for instances of the suffix.
  while (inner >= 0)
  {
    if ((inner > outer) && (suffix[inner + patternLen - 1 - prevInner] < (inner - outer)))
    {
      suffix[inner] = suffix[inner + patternLen - 1 - prevInner];
    }
    else
    {
      if (inner < outer)
      {
        outer = inner;
      }
      prevInner = inner;
      while ((outer >= 0) && (pPattern->at(outer) == pPattern->at(outer + patternLen - 1 - prevInner)))
      {
        --outer;
      }

      suffix[inner] = prevInner - outer;
    }

    --inner;
  }
} 

/// <summary>
/// Generate the good suffix table.
/// </summary>
void BoyerMoore::generateGoodSuffixTable(string * pPattern)
{
  // Get the length of the pattern
  int patternLen = pPattern->length();

  // Allocate and initialize the good suffix and border position tables.
  goodSuffix = new int[patternLen];
  for (int index = 0; index < patternLen; ++index)
  {
    goodSuffix[index] = patternLen;
  }

  int inner = 0;
  int outer = patternLen - 1;
  while (outer >= 0)
  {
    if (suffix[outer] == (outer + 1))
    {
      while (inner < patternLen - 1 - outer)
      {
        if (goodSuffix[inner] == patternLen)
        {
          goodSuffix[inner] = patternLen - 1 - outer;
        }

        ++inner;
      }
    }
    --outer;
  }

  for (int index = 0; index <= patternLen - 2; ++index)
  {
    goodSuffix[patternLen - 1 - suffix[index]] = patternLen - 1 - index;
  }

}

/// <summary>
/// Get the associated shift for the supplied character.
/// </summary>
/// <param name="ch">The supplied character</param>
/// <returns>The associated shift</returns>
int BoyerMoore::GetBadMatch(char ch)
{
  return badMatch[ch];
}

/// <summary>
/// Get the associated good suffix shift for the supplied offset.
/// </summary>
/// <param name="offset">The supplied offset</param>
/// <returns>The associated shift</returns>
int BoyerMoore::GetGoodSuffix(char offset)
{
  int patternLen = pattern->length();
  return goodSuffix[patternLen - offset];
}

/// <summary>
/// Find the first occurrence of the search pattern.
/// Returns the start position of the found occurrence.
/// </summary>
/// <param name="pSource">The source text</param>
/// <returns>The start position of the found occurrence.</returns>
long * BoyerMoore::FindFirst(string *pSource)
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
    //offset = Search(pSource, offset);
    if (offset != last)
    {
      result.push_back(offset);
    }
  } while (offset != last);

  return result;

}
