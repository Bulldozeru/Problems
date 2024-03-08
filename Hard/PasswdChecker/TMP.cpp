#include <iostream>
#include <vector>
#include <string.h>
#include <random>     
#include <ctime>
// #include <dictionary.h>

using namespace std;

string lower {"abcdefghijklmnopqrstuvwxyz"};
string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
string digits{"0123456789"};
string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"};

char low = 'l';
char cap = 'c';
char dgt = 'd';
char sym = 's';

string symb(string pwd) { 

    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"};
    string miss = "lcds";

    for(int l = 0; l < 27; l++) {

        auto src = pwd.find(lower[l]);
        if(src != std::string::npos) { 
            auto look = miss.find('l');
            miss.erase(look, 1); 
            break;
        }
    }

    for(int l = 0; l < 27; l++) {

        auto src = pwd.find(upper[l]);
        if(src != std::string::npos) { 
            auto look = miss.find('c');
            miss.erase(look, 1); 
            break;
        }
    }

    for(int l = 0; l < 10; l++) {

        auto src = pwd.find(digits[l]);
        if(src != std::string::npos) { 
            auto look = miss.find('d');
            miss.erase(look, 1); 
            break;
        }
    }

    for(int l = 0; l < 30; l++) {

        auto src = pwd.find(symbols[l]);
        if(src != std::string::npos) { 
            auto look = miss.find('s');
            miss.erase(look, 1); 
            break;
        }
    }

    return miss;
}

int length(string pwd) {

    int len = pwd.size();

    if(len < 6) { return 6 - len; }

    else if(len > 50) { return 50 - len;}

    else { return 0; }

}

int identifyr(string sus) {

    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"};

    if(lower.find(sus[0]) != std::string::npos) { return 0;}
    if (upper.find(sus[0]) != std::string::npos) { return 1;}
    if (digits.find(sus[0]) != std::string::npos) { return 2;}
    if (symbols.find(sus[0]) != std::string::npos) {return 3;} 

    return 0;
    
}

vector<char> characterGenType(string opt) {

    vector<char> numb;
    random_device rand;
    mt19937 gen(rand());

    for(int l = 0; l < opt.size(); l++) {
    
        if(opt[l] == low) {
        
            uniform_int_distribution<>dis(0,25);    
            numb.push_back(lower[dis(gen)]);     
        }
        else if(opt[l] == cap) {

            uniform_int_distribution<>dis(0,25);
            numb.push_back(upper[dis(gen)]);
        }
        else if(opt[l] == sym) {

            uniform_int_distribution<>dis(0,27);
            numb.push_back(symbols[dis(gen)]); 
        }
        else if(opt[l] == dgt) {

            uniform_int_distribution<>dis(0,9);
            numb.push_back(digits[dis(gen)]);
        }
        else { continue; }

    }

    return numb;

}

vector<char> characterGenSz(char opt, int sz) {

    vector<char> numb;
    random_device rand;
    mt19937 gen(rand());

    if(opt == low) {

        uniform_int_distribution<>dis(0,25);    
        for(int l = 0; l < sz; l++) { numb.push_back(lower[dis(gen)]); }     
    }

    if(opt == cap) {

        uniform_int_distribution<>dis(0,25);
        for(int l = 0; l < sz; l++) { numb.push_back(upper[dis(gen)]); }
    }

    if(opt == sym) {

        uniform_int_distribution<>dis(0,27);
        for(int l = 0; l < sz; l++) { numb.push_back(symbols[dis(gen)]); } 
    }

    if(opt == dgt) {

        uniform_int_distribution<>dis(0,9);
        for(int l = 0; l < sz; l++) { numb.push_back(digits[dis(gen)]); };
    }

    return numb;

}


/*
vector<char> chargen(string opt) {

    char low = 'l';
    char cap = 'c';
    char dgt = 'd';
    char sym = 's';

    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"};

    vector<char> numb;
    random_device rand;
    mt19937 gen(rand());

    for(int l = 0; l < opt.size(); l++) {
    
        if(opt[l] == low) {
        
            uniform_int_distribution<>dis(0,25);    
            numb.push_back(lower[dis(gen)]);     
        }
        else if(opt[l] == cap) {

            uniform_int_distribution<>dis(0,25);
            numb.push_back(upper[dis(gen)]);
        }
        else if(opt[l] == sym) {

            uniform_int_distribution<>dis(0,27);
            numb.push_back(symbols[dis(gen)]); 
        }
        else if(opt[l] == dgt) {

            uniform_int_distribution<>dis(0,9);
            numb.push_back(digits[dis(gen)]);
        }
        else { continue; }

    }

    return numb;

}
*/
vector<int> treeck(string pwd) {

    vector<int> serie;

    for(int n = 0; n < pwd.size() - 2; n++) {
        if(pwd[n] == pwd[n+1] && pwd[n+1] == pwd[n+2]) {
            serie.push_back(n);
        }
    }
    
    return serie;
    
}

int picker(int n1, int n2) {

    time_t now = time(0);
    tm *GMT = gmtime(&now);
    int evan = GMT->tm_sec;
    if(evan % 2 == 0) {
        return n1;
    } 
    else { return n2; }

}

string inserter(string pwd, int pos, char chr) {

    string s(1, chr);

    string pass = pwd.insert(pos, s);

    return pass;
}

string modder(string pwd) {

    string wrkpwd = pwd;
    string opt = "lcds";
    int ln = length(pwd);
    string symChk = symb(pwd);
    
    if(symChk != "") {

        vector<char> gene = characterGenType(symChk);
        for(char l : gene) { 
            wrkpwd = inserter(wrkpwd, 0, l); 
        }
    }

    if(ln < 6 && ln > 0) {

        vector<char> gene;   
        gene = characterGenSz(sym, ln);
        
        for(char l : gene) { wrkpwd += l; }
    }

    if (ln < 0){
        wrkpwd.erase(wrkpwd.end()+ln, wrkpwd.end()); 
    }
    

    vector<int> pos = treeck(wrkpwd);
    for(int p : pos) {

        vector<char> gen = characterGenType("lcds"); // s / c // l / d        
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p]))); // l // s 1 // 4 
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p+1]))); // d // c 3 // 2 
        wrkpwd.erase(p);
        wrkpwd = inserter(wrkpwd, p, gen.at(picker(0,1)));
        
    }

    return wrkpwd;
}



int main() {
/*
    string mod1 = modder("A~1r");
    string mod2 = modder("aslr");
    string mod3 = modder("Aslr");
    string mod4 = modder("A5lr");
    string mod5 = modder("a~lr");
    
    string mod6 = modder("A5|_r");
    string mod7 = modder("L06!cC++"); */
    string mod8 = modder("TooMu<hL3nghtasdasdasdasdadadadadasdadadadasdasdaasdasd"); 
    string mod9 = modder("&*^%(%(^&%*&%#@)*&^$)@#_(*&_!#(*#_(*&@_(*#&_%(*&@#$%)))");
    string mod0 = modder("P4$$wdSec");
/*
    cout << mod1 << endl;
    cout << mod2 << endl;
    cout << mod3 << endl;
    cout << mod4 << endl;
    cout << mod5 << endl;

    cout << mod6 << endl;
    cout << mod7 << endl; */

    cout << mod8 << endl;
    cout << mod9 << endl;
    cout << mod0 << endl;

    return 0;
}
