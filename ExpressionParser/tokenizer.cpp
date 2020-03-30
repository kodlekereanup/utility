#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(const std::string& line) {
  std::vector<std::string> tokens(line.size()); 
  int index = 0;

  for(char c : line) {
    if(c == ' ') index++;
    else tokens[index] += c; 
  }
  
  return tokens;
}

int main() {

  std::string sentence = "Anup is a programmer";
  std::vector<std::string> tokens = tokenize(sentence);
  for(std::string token : tokens) std::cout << token << "\n";

  return 0;
}
