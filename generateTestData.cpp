#include "Algorithms.h"
#include <fstream>

string generateRandomChars(const int len){
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string s;

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;

}

string generateRandomBinary(const int len){
    static const char alphabet[] = "01";
    string s = string(len, '0');

    for (int i = 0; i < len; ++i) {
        s[i] = alphabet[rand() % (sizeof(alphabet)-1)];
    }
    return s;
}

void generateStrings(){
    ofstream fout;
    fout.open("binary_data.txt");
    cout << "Writing data to file binary_data.txt...\n";

    fout << generateRandomBinary(10) << endl;
    fout << generateRandomBinary(1000) << endl;
    fout << generateRandomBinary(1000000) << endl;
    fout << generateRandomBinary(1000000000) << endl;

    fout.close();

}

