#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <math.h>

// TODO Overflow Handling
// Throw exception if error is found. Not 0 or -1.
// utility functions
void remove_spaces(std::string& character) {
    character.erase(std::remove(character.begin(), character.end(), ' '), character.end());
}

bool inline has_any_chars(const std::string& s) { return std::any_of(s.begin(), s.end(), :: isalpha); }

// '0' --> 48
float atoi(std::string character) {
    float value = 0;
    bool neg = false, frac = false;
    
    //error handling
    remove_spaces(character);
    
    // check if any of the charcters is an alphabet
    if(has_any_chars(character)) {
        std::cerr << "\n Enter only numbers in the string! \n";
        exit(1);
    }
          
    int k = character.size(), p = 0, f = 0;
    auto dot = character.find('.');
    
    if(character[0] == '-') { neg = true; k--; }
    if(dot != std::string::npos) { frac = true; f = dot; k--; }
    
    for(char c : character) {
        if(c == '-' || c == '.') continue;
        p = pow(10, --k);
        value += (c - '0') * p;
    }
    
    if(neg) value *= -1;
    if(frac) value /= pow(10, character.size() - 1 - f);
    return value;
}

int main() {

    std::string character;
    std::cout << "\n ASCII TO INTEGER CONVERTER \n";
    std::cout << "\n Enter the english character: ";
    std::cin >> character;
    
    std::cout << " Converted to Numeric Format from String: " << atoi(character);
     
    return 0;

}
