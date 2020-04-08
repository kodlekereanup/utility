#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// Friend class prototype
class Lexer;

// Class Token
// Has a list of all tokens possible in an Enum : SyntaxType.

class Token {
    public:
    friend class Lexer;

    enum SyntaxType { 
	Number, 
	Space, 
	Plus, 
	Minus, 
	Star, 
	Slash, 
	OpenParanthesis, 
	CloseParanthesis, 
	Bad, 
	EndOfFile
} Type;

    int position;
    std::string Text;
    public:
    	Token() { }
        Token(SyntaxType type, int pos, std::string text) {
            Type = type;
            position = pos;
            Text = text;
        }
};

class Lexer {
    std::string _text;
    int _pos;

    public:
    Lexer(std::string text) {
        _text = text;
    }
    
    char current()  { return (_pos >= _text.size())? '\0' : _text[_pos]; }

    void next() { _pos++; }

    //Token t;
    Token nextToken() {
        
        if(_pos >= _text.size()) {
            Token t(endof, _pos, "\0");
            return t;
        }

        if(isdigit(current())) {
            auto start = _pos;
            while(isdigit(current())) next();
            auto len = _pos - start;
            auto text = _text.std::string::substr(start, len);
            Token t(Number, start, text);
            return t;
        }
       
        if(isdigit(current())) {
            auto start = _pos;
            while(isspace(current())) next();
            auto len = _pos - start;
            auto text = _text.std::string::substr(start, len);
            Token t(pace, start, text);
            return t;
        }

        // Special Cases:
        if(current() == '+') {
            Token t(Plus, _pos++, "+");
        	return t;
        }
        else if(current() == '-') {
            Token t(Minus, _pos++, "-");
            return t;
        }
        else if(current() == '*') {
            Token t(Star, _pos++, "*");
            return t;
        }
        else if(current() == '/') {
            Token t(Slash, _pos++, "/");
            return t;
        }
        else if(current() == '(') {
            Token t(OpenParanthesis, _pos++, "(");
            return t;
        }
        else if(current() == ')') {
            Token t(CloseParanthesis, _pos++, ")");
            return t;
        }
        
        Token t(Bad, _pos++, "bad");
        return t;
    }

};

int main() {
  
    std::string line = "1 + 2 * 3";
    Lexer lexer(line);

    while(true) {
        auto token = lexer.nextToken();
        if(token.Type == endof) break;
        std::cout << token.Type << token.Text << "\n"; 
    }

    return 0;
}
