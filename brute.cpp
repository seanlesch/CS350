#include "Algorithms.h"

void brute(string pattern, string text) {
    int text_i = 0;
    int pat_i = 0;
    int text_len = text.length();
    int pat_len = pattern.length();
    int stop_i = text_len - pat_len;
  
    /*for (int i = 0; i <= text_len - pat_len; i++) { 
        int j = 0;
        for (; j < pat_len; j++) 
            if (text[i + j] != pattern[j]) 
                break; 
        if (j == pat_len) cout << i << ",";
    } 
    cout << endl;
}*/ 
    while (text_i < text_len - pat_len +1) {
        while (text[text_i + pat_i] == pattern[pat_i]) {
            if (pat_i == pat_len - 1) {
                cout << text_i  << ",";
            }
            ++pat_i;
        }
        ++text_i;
        pat_i = 0;
    }
    cout << endl;
    return;
    
}