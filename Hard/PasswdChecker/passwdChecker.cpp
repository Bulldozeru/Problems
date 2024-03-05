#include <iostream>
#include <vector>
#include <string.h>
#include <random>       
#include <time.h>

using namespace std;

int length(string pwd) {

    int len = pwd.size();

    if(len < 6) { return 6 - len; }

    else if(len > 50) { return 50 - len;}

    else { return 0; }

}

vector<int> treeck(string pwd) {

    vector<int> serie;

    for(int n = 0; n < pwd.size() - 2; n++) {
        if(pwd[n] == pwd[n+1] && pwd[n+1] == pwd[n+2]) {
            serie.push_back(n);
        }
    }
    
    return serie;
    
}

string symb(string pwd) { 

    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"+ 0x5C + 0x22};
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

/*
generator function takes a string and an int as args and returns a 
vector container type char with 
    letters capitals symbols or digits
string is desired options and int is the length of generation
*/

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

            uniform_int_distribution<>dis(0,29);
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

int showChkr(string pwd) {

    int steps = 0;
    int ln = length(pwd);
    string syck = symb(pwd);
    vector<int> tree = treeck(pwd);
    
    if(ln != 0) { steps++; }
    if(syck != "") { steps += syck.size() / 2; }
    if(tree.size() > 0) { steps += tree.size(); }
    return steps;
}

int identifyr(string sus) {

    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"+ 0x5C + 0x22};

    if(lower.find(sus[0]) != std::string::npos) { return 0;}
    else if (upper.find(sus[0]) != std::string::npos) { return 1;}
    else if (digits.find(sus[0]) != std::string::npos) { return 2;}
    else {return 3;} 
    
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

string modder(string pwd) {

    string wrkpwd = pwd;
    string opt = "lcds";
    int ln = length(pwd);
    string symbChk = symb(pwd);
    
    vector<char> gene;

    if(ln < 6 && ln > 0 && symbChk != "") {
        
        gene = chargen(symbChk);
        
        for(int l = 0; l < gene.size(); l++) { wrkpwd += gene[l]; }
    }

    else if (ln < 0){
        wrkpwd.erase(wrkpwd.end()+ln, wrkpwd.end()); 
    }
    

    vector<int> pos = treeck(wrkpwd);

    for(int p = 0; p < pos.size(); p++) {

        vector<char> gen = chargen("lcds"); // s / c // l / d        
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p]))); // l // s 1 // 4 
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p+1]))); // d // c 3 // 2 
        wrkpwd.erase(p);
        wrkpwd.insert(p, to_string(gen.at(picker(0,1))));
    }

    return wrkpwd;
}

int main() {

    string tstle = "As1)"; // 2
    string tstse = "!0ngpw"; // 1
    string tst3e = "P4sss$"; // 1
    string tstfe = "nnn"; // 4
    string tstgp = "P4$$wd"; // 0

    int show1 = showChkr(tstle);
    int show2 = showChkr(tstse);
    int show3 = showChkr(tst3e);
    int show4 = showChkr(tstfe);
    int show5 = showChkr(tstgp);

    string pwd1 = modder(tstle);
    string pwd2 = modder(tstse);
    string pwd3 = modder(tst3e);
    string pwd4 = modder(tstfe);
    string pwd5 = modder(tstgp);

    cout << "[*] TESTING PASSWORDS FOR STRENGTH AGAINST BRUTEFORCE...\n";
    cout << "[?] Password: " << tstle << " :: Imporvements: "
    << show1 << endl << "   Suggested: " << pwd1;
    cout << "[?] Password: " << tstse << " :: Imporvements: "
    << show2 << endl << "   Suggested: " << pwd2;
    cout << "[?] Password: " << tst3e << " :: Imporvements: "
    << show3 << endl << "   Suggested: " << pwd3;
    cout << "[?] Password: " << tstfe << " :: Imporvements: "
    << show4 << endl << "   Suggested: " << pwd4;
    cout << "[?] Password: " << tstgp << " :: Imporvements: "
    << show5 << endl << "   Suggested: " << pwd5;


    // Set a passwd
    // Then runn it with moder
    // Do some user-friendly shit ;)

    return 0;
}
