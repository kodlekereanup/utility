#include <iostream>
#include <string>
#include <vector>

// TODO:
// Add File Support: Read the file and tokenize it.
// Add Exception Handling

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

  std::string str = "1 + 2 * 3";
  char delim = ' ';
  
  std::vector<std::string> tokens = tokenize(str, delim);
  for(std::string token : tokens) std::cout << token << "\n";

  return 0;
}


    
