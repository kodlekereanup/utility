#include <iostream>
#include <string>
#include <vector>

// TODO:
// Add File Support: Read the file and tokenize it.
// Add Exception Handling

// enum Token_Type {

// 		 TOKEN_IDENT,
// 		 TOKEN_KEY,
// 		 TOKEN_NUMBER,
// 		 TOKEN_STRING
// };

// Token_Type *peek_next_token();

std::vector<std::string> tokenize(const std::string& line, const char delim = ' ') {
  std::vector<std::string> tokens(line.size()); 
  int index = 0;

  if(line == "") {
    std::cout << "\n String cannot be empty! \n";
    exit(1);
  }

  for(char c : line) {
    if(c == delim) index++;
    else tokens[index] += c; 
  }
  
  return tokens;
}

int main() {

  std::string str = "Anup is a programmer";
  std::string t = "";
  char delim = ' ';
  
  std::vector<std::string> tokens = tokenize(t, delim);
  for(std::string token : tokens) std::cout << token << "\n";

  return 0;
}

// What I want to do:

// Given a file as input,
// Break the file into tokens
// Ex:
//
// File:
// Anup + Ankit = Awesome
//
// Tokens: Anup     : string
//         Ankit    : string
//         Awesome  : string
//         +        : expr
//         space    : expr (?)
//         =        : expr
    
