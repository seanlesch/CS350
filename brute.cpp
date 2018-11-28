#include "Algorithms.h"
//Worst case O(m*(n-m+1))
long* brute(string * pattern, string * text) {
    int text_i = 0;
    int pat_i = 0;
    int text_len = text->length();
    int pat_len = pattern->length();
    int stop_i = text_len - pat_len;
    int count = 0;
    static long r[1];
    for(text_i;text_i < stop_i; ++text_i){
        ++count;
        while (text->at(text_i + pat_i) == pattern->at(pat_i)) {
            ++pat_i;
            ++count;
            if(pat_i == pat_len){
                r[0] = text_i;
                r[1] = count;
                return r;
            }
        }
        pat_i = 0;
    }
    r[0] = -1;
    r[1] = count;
    return r;
}
