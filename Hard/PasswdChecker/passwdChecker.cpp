#include <iostream>
#include <vector>
#include <string.h>
#include <random>       
#include <time.h>

using namespace std;


// [+] These are the characters that will be used to search in a string for requirements


string lower {"abcdefghijklmnopqrstuvwxyz"};
string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
string digits{"0123456789"};
string symmbols {"`~!@#$%^&*()-=_+/|,./;':<>?"};

char low = 'l';
char cap = 'c';
char dgt = 'd';
char sym = 's';


// This Function checks for all required symbols in a password (lowercase / uppercase / digits and symbols)

string symbolChecker(string pwd) { 

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

        auto src = pwd.find(symmbols[l]);
        if(src != std::string::npos) { 
            auto look = miss.find('s');
            miss.erase(look, 1); 
            break;
        }
    }

    return miss;
}

// This function checks for length of the password and returns negative value if it's bigger than 50 and positive between [0,50]

int length(string pwd) {

    int len = pwd.size();

    if(len < 6) { return 6 - len; }

    else if(len > 50) { return 50 - len;}

    else { return 0; }

}

// This func identify what kind of character is passed

int identifyr(string sus) {

    if(lower.find(sus[0]) != std::string::npos) { return 0;}
    if (upper.find(sus[0]) != std::string::npos) { return 1;}
    if (digits.find(sus[0]) != std::string::npos) { return 2;}
    if (symmbols.find(sus[0]) != std::string::npos) {return 3;} 

    return 0;
    
}

// This function checks if there are 3 identical characters next to eachother 

vector<int> char3SerieCheck(string pwd) {

    vector<int> serie;

    if(pwd.size() < 2){
        
        cout << "[-] Try to add more than 1 character \nYou can handle 6 characters with ease";
        exit(-1);
    }
    for(int n = 0; n < pwd.size() - 2; n++) {
        if(pwd[n] == pwd[n+1] && pwd[n+1] == pwd[n+2]) {
            serie.push_back(n);
        }
    }
    
    return serie;
    
}

// Forces a number to be above 0

int forceUp0(int sz) {

    if(sz < 0) {

        sz = -sz -sz;
        return sz;
    }
    return sz;

    
}

// This function returns the number of steps to improve the strength of the password

int repairSteps(string pwd) {

    int steps = 0;
    int ln = length(pwd);
    string syck = symbolChecker(pwd);
    vector<int> tree = char3SerieCheck(pwd);
    ln = forceUp0(ln);

    steps += ln;

    if(syck != "") { steps += syck.size(); }
    if(tree.size() > 0) { steps += tree.size(); }
    return steps;
}
/*
This function generates a serie of characters depending of what you've passed
Ex: 
    llccddssd -- ssYM80|_5 
*/


vector<char> characterGenType(string opt) {

    vector<char> numb;
    random_device rand;
    mt19937 gen(rand());

    for(int l = 0; l < opt.size(); l++) {
    
        if(opt[l] == low) {
        
            uniform_int_distribution<>dis(0,26);    
            numb.push_back(lower[dis(gen)]);     
        }
        else if(opt[l] == cap) {

            uniform_int_distribution<>dis(0,26);
            numb.push_back(upper[dis(gen)]);
        }
        else if(opt[l] == sym) {

            uniform_int_distribution<>dis(0,27);
            numb.push_back(symmbols[dis(gen)]); 
        }
        else if(opt[l] == dgt) {

            uniform_int_distribution<>dis(0,9);
            numb.push_back(digits[dis(gen)]);
        }
        else { continue; }

    }

    return numb;

}

/*
Similar to the characterGenType this generates characters
However, this generates a string with the same type of characters and a specified size

Ex:
    c, 6 -- HACKED
    d, 3 -- 556 
*/

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
        for(int l = 0; l < sz; l++) { numb.push_back(symmbols[dis(gen)]); } 
    }

    if(opt == dgt) {

        uniform_int_distribution<>dis(0,9);
        for(int l = 0; l < sz; l++) { numb.push_back(digits[dis(gen)]); };
    }

    return numb;

}

// This function picks between 2 numbers

int picker(int n1, int n2) {

    time_t now = time(0);
    tm *GMT = gmtime(&now);
    int evan = GMT->tm_sec;
    if(evan % 2 == 0) {
        return n1;
    } 
    else { return n2; }

}

// This insersts characters at a specified position

string inserter(string pwd, int pos, char chr) {

    string s(1, chr);

    string pass = pwd.insert(pos, s);

    return pass;
}

// This implements changes to the password (pwd)

string modder(string pwd) {

    string wrkpwd = pwd;
    string opt = "lcds";
    int ln = length(pwd);
    string symChk = symbolChecker(pwd);
    
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
    

    vector<int> pos = char3SerieCheck(wrkpwd);

    for(int p : pos) {

        vector<char> gen = characterGenType("lcds"); // s / c // l / d        
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p]))); // l // s 1 // 4 
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p+1]))); // d // c 3 // 2
        
        wrkpwd.erase(wrkpwd.begin() + p);
        wrkpwd = inserter(wrkpwd, p, gen.at(picker(0,1)));
        
    }

    return wrkpwd;
}

// Test cases

int main() {

    string mod1 = "aa";
    string mod2 = "AA";
    string mod3 = "Aa1";
    string mod4 = "!1";
    string mod5 = "P@sssw0rd";

    string mod6 = "A5|_r";
    string mod7 = "L061cCpp"; 
    string mod8 = "TooMu<hL3nghtasdasdasdasdadadadadasdadadadasdasdaasdasd"; 
    string mod9 = "&*^%(%(^&%*&%#@)*&^$)@#_(*&_!#(*#_(*&@_(*#&_%(*&@#$%)))";
    string mod0 = "Nu|_l";

    string modrdy1 = "P4$$wdSec";
    string modrdy2 = "L337<0d3";

    int show1 = repairSteps(mod1);
    int show2 = repairSteps(mod2);
    int show3 = repairSteps(mod3);
    int show4 = repairSteps(mod4);
    int show5 = repairSteps(mod5);

    int show6 = repairSteps(mod6);
    int show7 = repairSteps(mod7);
    int show8 = repairSteps(mod8);
    int show9 = repairSteps(mod9);
    int show0 = repairSteps(mod0);
    
    int showrdy1 = repairSteps(mod0);
    int showrdy2 = repairSteps(mod0);

    string pwd1 = modder(mod1);
    string pwd2 = modder(mod2);
    string pwd3 = modder(mod3);
    string pwd4 = modder(mod4);
    string pwd5 = modder(mod5);

    string pwd6 = modder(mod6);
    string pwd7 = modder(mod7);
    string pwd8 = modder(mod8);
    string pwd9 = modder(mod9);
    string pwd0 = modder(mod0);
    
    string pwdrdy1 = modder(modrdy1);
    string pwdrdy2 = modder(modrdy2);


    cout << "[*] TESTING PASSWORDS FOR STRENGTH AGAINST BRUTEFORCE...\n";

    cout << "[?] Password: " << mod1 << " :: Imporvements: "
    << show1 << endl << "   Suggested: " << pwd1 << endl;
    
    cout << "[?] Password: " << mod2 << " :: Imporvements: "
    << show2 << endl << "   Suggested: " << pwd2 << endl;

    cout << "[?] Password: " << mod3 << " :: Imporvements: "
    << show3 << endl << "   Suggested: " << pwd3 << endl;

    cout << "[?] Password: " << mod4 << " :: Imporvements: "
    << show4 << endl << "   Suggested: " << pwd4 << endl;

    cout << "[?] Password: " << mod5 << " :: Imporvements: "
    << show5 << endl << "   Suggested: " << pwd5 << endl;

    cout << "[?] Password: " << mod6 << " :: Imporvements: "
    << show6 << endl << "   Suggested: " << pwd6 << endl;

    cout << "[?] Password: " << mod7 << " :: Imporvements: "
    << show7 << endl << "   Suggested: " << pwd7 << endl;

    cout << "[?] Password: " << mod8 << " :: Imporvements: "
    << show8 << endl << "   Suggested: " << pwd8 << endl;

    cout << "[?] Password: " << mod9 << " :: Imporvements: "
    << show9 << endl << "   Suggested: " << pwd9 << endl;

    cout << "[?] Password: " << mod0 << " :: Imporvements: "
    << show0 << endl << "   Suggested: " << pwd0 << endl;

    cout << "[?] Password: " << modrdy1 << " :: Imporvements: "
    << showrdy1 << endl << "   Suggested: " << pwdrdy1 << endl;

    cout << "[?] Password: " << modrdy2 << " :: Imporvements: "
    << showrdy2 << endl << "   Suggested: " << pwdrdy2 << endl;

    return 0;
}


