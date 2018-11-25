#include "Algorithms.h"
#include <fstream>

string generateRandomChars(const int len){
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string s = string(len, '0');

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
    fout.open("binary_data_small.txt");
    fout << generateRandomBinary(1000);
    fout.close();
    fout.open("binary_data_medium.txt");
    fout << generateRandomBinary(1000000);
    fout.close();
    fout.open("binary_data_large.txt");
    fout << generateRandomBinary(1000000000);
    fout.close();

    fout.open("random_data_small.txt");
    fout << generateRandomChars(1000);
    fout.close();
    fout.open("random_data_medium.txt");
    fout << generateRandomChars(1000000);
    fout.close();
    fout.open("random_data_large.txt");
    fout << generateRandomChars(1000000000);
    fout.close();
    cout << "Done!\n";

    // Todo: Create a large file of all the same character.
}

