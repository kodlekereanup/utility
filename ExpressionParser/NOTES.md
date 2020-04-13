# Tokenizer
A tokenizer is a program that breaks another program into a set of atoms, called tokens. It divides the 
input according to the delimiter supplied, which is usually the space character.

# Lexer - Lexical Analysis
A lexer is a better version of a tokenizer. It not only tokenizes the input, but also provides information
about the tokens - like it's type.

# Parser
A parser is a tool that parses the output by the lexer and generates trees. These trees are walked on and 
meaningful programming language syntax is generated. (?)

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

