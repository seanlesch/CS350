#include "Algorithms.h"
#include <fstream>

string generateRandomDNA(const int len){
    static const char alphabet[] ="ACTG";
    string s = string(len, '0');

    for (int i = 0; i < len; ++i) {
        s[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    return s;
}

string generateBinaryAlternating(const int len){
    string s = string(len, '0');

    for (int i = 0; i < len; ++i) {
        if(i % 2 == 0) 
            s[i] = '0';
        else
            s[i] = '1';
        }
    return s;
}

string generateBinaryConsecutive(const int len){
    int half = len / 2;
    string s = string(len, '0');

    for (int i = half; i < len; ++i) {
        s[i] = '1';
    }
    return s;
}

string generateSingleChar(const int len){
    string s = string(len, '0');
    return s;
}

string generateRandomChars(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string s = string(len, '0');

    for (int i = 0; i < len; ++i)
    {
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

    /*fout.open("binary_alternating_data.txt");
    fout << generateBinaryAlternating(1000000);
    fout.close();
    fout.open("binary_consecutive_data.txt");
    fout << generateBinaryConsecutive(1000000);
    fout.close();*/
    fout.open("binary_data_100mil.txt");
    fout << generateRandomBinary(100000000);
    fout.close();
    fout.open("binary_data_1mil.txt");
    fout << generateRandomBinary(1000000);
    fout.close();
    fout.open("binary_data_10mil.txt");
    fout << generateRandomBinary(10000000);
    fout.close();

  /*  cout << "Generating Single Char Data...\n";
    fout.open("Single_char_data.txt");
    fout << generateSingleChar(1000000);
    fout.close();*/

    cout << "Generating DNA Data...";
    fout.open("DNA_100mil.txt");
    fout << generateRandomDNA(100000000) << endl;
    fout.close();
    fout.open("DNA_1mil.txt");
    fout << generateRandomDNA(1000000) << endl;
    fout.close();
    fout.open("DNA_10mil.txt");
    fout << generateRandomDNA(10000000) << endl;
    fout.close();


    cout << "Generating WORST CASE Data...";
    fout.open("Single_100mil.txt");
    fout << generateSingleChar(100000000) << endl;
    fout.close();
    fout.open("Single_1mil.txt");
    fout << generateSingleChar(1000000) << endl;
    fout.close();
    fout.open("Single_10mil.txt");
    fout << generateSingleChar(10000000) << endl;
    fout.close();

    fout.open("Alphanum_100mil.txt");
    fout << generateRandomChars(100000000);
    fout.close();
    fout.open("Alphanum_1mil.txt");
    fout << generateRandomChars(1000000);
    fout.close();
    fout.open("Alphanum_10mil.txt");
    fout << generateRandomChars(10000000);
    fout.close();
    cout << "Done!\n";
}

