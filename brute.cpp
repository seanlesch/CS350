#include "Algorithms.h"
//Worst case O(m*(n-m+1))
long brute(string * pattern, string * text) {
    int text_i = 0;
    int pat_i = 0;
    int text_len = text->length();
    int pat_len = pattern->length();
    int stop_i = text_len - pat_len;
    for(text_i;text_i < stop_i; ++text_i){
        while (text->at(text_i + pat_i) == pattern->at(pat_i)) {
            ++pat_i;
            if(pat_i == pat_len){
                return text_i;
            }
        }
        pat_i = 0;
    }
    return -1;
}
