#include "Algorithms.h"
#include "TestRunner.h"

int main()
{
<<<<<<< HEAD
  /*
     int len = 10000;
    
    string text(generateRandomBinary(len));
    string pattern(text, 9980, 10);
    struct timeval start, stop;
    cout << endl << endl << endl;

    gettimeofday(&start, NULL);
    cout << "Brute" << endl;
    brute(&pattern, &text);
    gettimeofday(&stop, NULL);
    cout << "Brtue took:" << stop.tv_usec - start.tv_usec << endl;

    gettimeofday(&start, NULL);
    cout << "KMP" << endl;
    kmp(&pattern, &text);
    gettimeofday(&stop, NULL);
    cout << "KMP took:" << stop.tv_usec - start.tv_usec << endl;
    
    gettimeofday(&start, NULL);
    cout << "Rabin karp" << endl;
    rabinKarp(&pattern, &text, 101);
    gettimeofday(&stop, NULL);
    cout << "Rabin-Karp took:" << stop.tv_usec - start.tv_usec << endl;
*/
    TestRunner tr;
    tr.RunTests();
=======
     TestRunner tr();
>>>>>>> f6745b5b8d023bc6de2b717757fe2f8526495656

     return 0;
}
