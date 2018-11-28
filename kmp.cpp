#include "Algorithms.h"

//called by the kmp function
//preprocesses the pattern to search for, finding the longest proper 
//prefix with a matching suffix populates an array with the number 
//of indices to skip if a pattern/text mismatch occurs
void kmp_prefix(char* pat,int* lps,int M ) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

//cycles through the text outputting to the screen all the indices of the
//text string where the pattern begins if a full match occurs
long* kmp(string * pattern, string * text){
    int * to_skip = NULL;//holds the number of indices to skip
    int text_length = text->length();
    int pattern_length = pattern->length();    
    int pat_i = 0;
    int text_i = 0;
    int start_i = 0;
    int count = 0;
    static long r[1];

    //creates the prefix/suffix match array determining how many 
    //pattern indices to skip back on mismatch
    kmp_prefix(pattern, to_skip, pattern_length);

    //cycles through the text comparing to the pattern, storing the 
    //indices of the text where the pattern began 
    while (text_i < text_length) { 
        
        if (pattern->at(pat_i) == text->at(text_i)) { 
            ++pat_i; 
            ++text_i;
            ++count;
        } 
        
        //if the pattern has a match 
        if (pat_i == pattern_length) {
            r[0] = text_i - pat_i;
            r[1] = count;
            return r;

            //pattern and text at their corresponding indices don't match
        } else if ((text_i < text_length) && (pattern->at(pat_i) != text->at(text_i))) { 
            //if the pattern index is greater than 0 it gets set to the previous
            //index in the to_skip array, preventing repeat compares
            ++count;
            if (pat_i != 0) pat_i = to_skip[pat_i - 1]; 
            else ++text_i; 
        } 
    }
    
    delete to_skip;
    r[0] = -1;
    r[1] = count;
    return r;
}
