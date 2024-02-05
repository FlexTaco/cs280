#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <map>
#include <sstream>
#include <string>
#include <iostream>
#include "lex.h"


using std::map;
using namespace std;
map <string, Token> StrToTok = {
        //keyword
		{"WRITELN", WRITELN},
		{ "IF", IF },
		{ "ELSE", ELSE },	

        //IDENT
		{ "IDENT", IDENT },
        
        //NIDENT/SIDENT
		{ "NIDENT", NIDENT },
		{ "SIDENT", SIDENT },

        //ICONST/RCONST
		{ "ICONST", ICONST },
		{ "RCONST", RCONST },

        //SCONST
		{ "SCONST", SCONST  },
		
        //operators
		{ "PLUS", PLUS },
		{ "MINUS" , MINUS },
		{ "MULT" , MULT  },
		{ "DIV" , DIV },
		{ "EXPONENT" , EXPONENT },
		{ "ASSOP", ASSOP },
		{ "NEQ", NEQ  },
		{ "NGTHAN" , NGTHAN  },
		{ "NLTHAN", NLTHAN },

		{ "CAT", CAT },
		{ "SREPEAT" , SREPEAT  },
		{ "SEQ", SEQ },
		{ "SGTHAN", SGTHAN },
		{ "SLTHAN", SLTHAN },
		            
		{ "COMMA", COMMA  },
		{ "LPAREN", LPAREN },
		{ "RPAREN", RPAREN },
		{ "LBRACES", LBRACES },
		{ "RBRACES", RBRACES  },
		
		{ "SEMICOL", SEMICOL  },
		
        //error
		{ "ERR",ERR  },

		{ "DONE", DONE },
};

LexItem id_or_kw(const string& lexeme, int linenum){
    
    auto value = StrToTok.find(lexeme);
    Token token;
    if(value != StrToTok.end()){
        token = StrToTok[lexeme];
       
    }else{
        //can be IDENT, SIDENT, or NIDENT
        token = IDENT;
    }
    LexItem item(token, lexeme, linenum);
    return item;
}


ostream& operator<<(ostream& out, const LexItem& tok){
    //Token token = tok.GetToken();
    //create if statement
    out << tok.GetToken();
    //iconst/ rconst ()
    //ident nothing
    //sconst ''
    //else "" 
    if (tok.GetToken()==ICONST|| tok.GetToken()==RCONST){
        out << " (" << tok.GetLexeme() << ")" ; 
    }else if(tok.GetToken()==IDENT){
        out << tok.GetLexeme() ;
    }else if(tok.GetToken()==SCONST){
        out << " '" << tok.GetLexeme() << "'" ;
    }else{
        out << " \"" << tok.GetLexeme() << "\"" ;
    }
    
    out << " at Line " << tok.GetLinenum() << endl;
    
    return out;
}