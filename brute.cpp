#include "Algorithms.h"

void brute(string * pattern, string * text) {
    int text_i = 0;
    int pat_i = 0;
    int text_len = text->length();
    int pat_len = pattern->length();
  
    while (text_i < text_len - pat_len +1) {
        while (text->at(text_i + pat_i) == pattern->at(pat_i)) {
            /*if (pat_i == pat_len - 1) {
                return;
                //cout << text_i  << ",";
            }*/
            ++pat_i;
            ++text_i;
        }
        text_i -= pat_i + 1;
        pat_i = 0;
    }
    //cout << endl;
    return;
}
