#include "Algorithms.h"
#define d 256

void rabinKarp(string pattern, string source, int q){
    int pLength = pattern.length();
    int sLength = source.length();
    int p = 0; //hash value of pattern string.
    int s = 0; //hash value of source string.
    int h = 1; //d^(s-1)

    //Computing hash of h.
    for(int i = 0; i < pLength - 1; i++){
        h = (h * d) % q;
    }

    //Computing hashes of pattern and source strings.
    for(int i = 0; i < pLength; i++)
    {
        p = (d * p + pattern[i]) % q;
        s = (d * s + source[i]) % q;
    }

    //Matching loop.
    for(int i = 0; i <= sLength - pLength; i++){
        if(p==s){//We have found a match.
            int j=0;
            for(j = 0; j < pLength; j++){ //Check the length of the string for mismatches.
                if(source[i + j] != pattern[j])
                    break;
            }
            if(j == pLength){//Pattern fully matched.
                cout << i << ",";
            }
        }
        if(i < (sLength - pLength)){//Are we still in bounds? Then get next hash.
            s = (d * (s - source[i] * h) + source[i+pLength])%q;
            if(s < 0)//If s is now negative, make positive.
                s = s + q;
        }
    }
    cout << endl;
}