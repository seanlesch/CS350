#include "Algorithms.h"
#define d 256

void rabinKarp(string pattern, string source, int q){
    int M = pattern.length();
    int N = source.length();
    int i, j;
    int p = 0, t = 0, h = 1;

    for(i = 0; i < M - 1; i++){
        h = (h * d) % q;
    }

    for(i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + source[i]) % q;
    }

    for(i = 0; i <= N - M; i++){
        if(p==t){
            for(j = 0; j < M; j++){
                if(source[i + j] != pattern[j])
                    break;
            }
            if(j == M){
                cout << "Pattern found at index: " << i << endl;
            }
        }
        if(i < (N - M)){
            t = (d * (t - source[i] * h));
            if(t < 0)
                t = t + q;
        }
    }

}