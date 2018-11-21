#include "Algorithms.h"

int main(){
    cout << "Brute" << endl;
    brute("go", "Algorithms and complexity.");

    cout << "KMP" << endl;
    kmp("go", "Algorithms and complexity.");

    cout << "Rabin karp" << endl;
    rabinKarp("go", "Algorithms and complexity.", 101);
    return 0;
}