#include "Algorithms.h"
#include <fstream>

string generateRandomDNA(const int len){
    static const char alphanum[] ="ACTG"
    string s = string(len, '0');

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

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
    fout.open("DNA.txt");
    cout << "Writing data to file DNA.txt...\n";

    fout << generateRandomDNA(10) << endl;
    fout << generateRandomDNA(1000) << endl;
    fout << generateRandomDNA(1000000) << endl;
    fout << generateRandomDNA(1000000000) << endl;

    cout << "Done!\n";

    fout.open("binary_data.txt");
    cout << "Writing data to file binary_data.txt...\n";

    fout << generateRandomBinary(10) << endl;
    fout << generateRandomBinary(1000) << endl;
    fout << generateRandomBinary(1000000) << endl;
    fout << generateRandomBinary(1000000000) << endl;

    cout << "Done!\n";

    fout.open("random_data.txt");
    cout << "Writing data to file random_data.txt...\n";

    fout << generateRandomChars(10) << endl;
    fout << generateRandomChars(1000) << endl;
    fout << generateRandomChars(1000000) << endl;
    fout << generateRandomChars(1000000000) << endl;
    cout << "Done!\n";
    fout.close();

    // Todo: Create a large file of all the same character.
}

