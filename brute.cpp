#include "Algorithms.h"
//Worst case O(m*(n-m+1))
void brute(string * pattern, string * text) {
    int text_i = 0;
    int pat_i = 0;
    int text_len = text->length();
    int pat_len = pattern->length();
    int stop_i = text_len - pat_len;
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
  
=======
>>>>>>> 4e1653d9daaf96a1f4d7d9c5691f2dea16c062d1

>>>>>>> dcf5b49eb7ec60d41d59e7173ba33319e70a80c5
=======
>>>>>>> 91817b0dfa2643f61ba75bc73bea7d6918b7b341
    for(text_i;text_i < stop_i; ++text_i){
        while (text->at(text_i + pat_i) == pattern->at(pat_i)) {
            ++pat_i;
            if(pat_i == pat_len-1){
                return;
            }
<<<<<<< HEAD
<<<<<<< HEAD

        }
        pat_i = 0;
    }
    
=======
<<<<<<< HEAD
=======

>>>>>>> dcf5b49eb7ec60d41d59e7173ba33319e70a80c5
=======
>>>>>>> 91817b0dfa2643f61ba75bc73bea7d6918b7b341
        }
        pat_i = 0;
    }
>>>>>>> 4e1653d9daaf96a1f4d7d9c5691f2dea16c062d1
    return;
}
