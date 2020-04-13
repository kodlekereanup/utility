using System;

namespace exppar
{
    class Program
    {
        static void Main(string[] args)
        {
           while(true) {
	   	Console.Write(">");
		var line = Console.ReadLine();
		if(string.IsNullOrWhiteSpace(line)) return;

		var lexer = new Lexer(line);
		while(true) {
			var token = lexer.nextToken();
			if(token.type == Type.EndOfFile) break;
			Console.WriteLine($"{token.type} : '{token.text}'");
			Console.WriteLine();
		}
        }
    }
    }

    enum Type {
	    Number,
	    Space,
	    Plus,
	    Minus, 
	    Slash,
	    Star,
	    OpenParanthesis,
	    CloseParanthesis,
	    EndOfFile,
	    Bad
    }


    class Token {

	    public Token(Type t, int pos, string text) {
		   type = t;
		   position = pos;
		   text = text;
	    }

	    public Type type    { get; }
	    public int position { get; }
	    public string text  { get; }
    }

    class Lexer {
    	
	    private readonly string _text;
	    private int _position;

	    public Lexer(string text) { _text = text; }

	    private char current {
		    get {
			    if(_position >= _text.Length) return '\0';
			    else return _text[_position];
		    }
	    }

	    private void next() { _position++; } 

	    public Token nextToken() {
			
		    if(_position >= _text.Length) return new Token(Type.EndOfFile, _position, "\0");	
		    if(char.IsDigit(current)) {
			    var start = _position;
			    while(char.IsDigit(current)) next();
			    var length = _position - start;
			    var text = _text.Substring(start, length);
			    return new Token(Type.Number, start, text);
		    } 
		    if(char.IsWhiteSpace(current)) {
			    var start = _position;
			    while(char.IsDigit(current)) next();
			    var length = _position - start;
			    var text = _text.Substring(start, length);
			    return new Token(Type.Space, start, text);
		    }   

		    if (current == '+') return new Token(Type.Plus, _position++, "+");
		    else if(current == '-') return new Token(Type.Minus, _position++, "-");
		    else if(current == '*') return new Token(Type.Star, _position++, "*");
		    else if(current == '/') return new Token(Type.Slash, _position++, "/");
		    else if(current == '(') return new Token(Type.OpenParanthesis, _position++, "(");
		    else if(current == ')') return new Token(Type.CloseParanthesis, _position++, ")");
		    else return new Token(Type.Bad, _position++, _text.Substring(_position - 1, 1));
		    
	    }
    
    } 
}
