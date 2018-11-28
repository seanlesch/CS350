#include "Algorithms.h"

void kmp_prefix(string * pattern, int *& to_skip, int pattern_length) { 
    int pre_suf_count = 0;//the number times the prefix and suffix match
    int i_to_match = 1;//marks the index to begin matching with the prefix
    
    to_skip = new int[pattern_length];
    to_skip[0] = 0;//first index is always 0 b/c it is the smallest prefix
    
    //creates the to_skip array
    for (i_to_match; i_to_match < pattern_length; ++i_to_match) {

        //increments the number of indices to skip for a text/pattern
        // mismatch and stores it in the to_skip array
        if (pattern->at(i_to_match) == pattern->at(pre_suf_count)) {
            ++pre_suf_count;
            to_skip[i_to_match] = pre_suf_count;
        }
        else {
            //no prefix/suffix match but previous index was a match
            if (pre_suf_count != 0) { 
                pre_suf_count = to_skip[pre_suf_count-1];
                --i_to_match;
            }
            //no prefix/suffix match so no index skips
            //added to the to_skip array
            else to_skip[i_to_match] = 0;
        }
    }
    return;
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
    long count = 0;
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
