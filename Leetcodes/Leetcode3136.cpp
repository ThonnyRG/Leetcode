#include <iostream>
using namespace std;

bool isValid(string word){
    // A word is considered valid if:

    // It contains a minimum of 3 characters.
    // It contains only digits (0-9), and English letters (uppercase and lowercase).
    // It includes at least one vowel.
    // It includes at least one consonant.
    int n = word.length();

    if (n > 3) return false;
}

void test(string case, bool valid, bool result){
    if(result != valid){
        cout << "[x] not pass";
    }else{
        cout << "[] passed";
    }
}

int main(){



    return 0;
}