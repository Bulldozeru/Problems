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
        if(pwd[n] = pwd[n+1] = pwd[n+2]) {
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
    string res = "";
    int lw,up,dt,sy;

    for(int l = 0; l < 27; l++) {

        auto src = pwd.find(lower[l]);
        if(src != std::string::npos) { 
            lw = 1; 
            break;
        }
    }
    for(int l = 0; l < 27; l++) {

        auto src = pwd.find(upper[l]);
        if(src != std::string::npos) { 
            up = 1; 
            break;
        }
    }
    for(int l = 0; l < 10; l++) {

        auto src = pwd.find(digits[l]);
        if(src != std::string::npos) { 
            dt = 1; 
            break;
        }
    }
    for(int l = 0; l < 30; l++) {

        auto src = pwd.find(symbols[l]);
        if(src != std::string::npos) { 
            sy = 1; 
            break;
        }
    }

    if(lw == 0) { res = "lw"; }
    if(up == 0) { res = "up"; }
    if(dt == 0) { res = "dt"; }
    if(sy == 0) { res = "sy"; }

    return res;
}

/*
generator function takes a string and an int as args and returns a 
vector container type char with 
    letters capitals symbols or digits
string is desired options and int is the length of generation
*/

vector<char> generator(string opt, int len) {

    char str = 'l';
    char cap = 'c';
    char dgt = 'd';
    char sym = 's';

    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"+ 0x5C + 0x22};

    char opt[3] {0};
    vector<char> numb;
    random_device rand;
    mt19937 gen(rand());    


    for(int l = 0; l < len; l++) {
    
        if(opt[l] = 'l') {
        
            uniform_int_distribution<>dis(0,26);    
            numb.push_back(lower.at(dis(gen)));     
        }
        else if(opt[l] = 'c') {

            uniform_int_distribution<>dis(0,26);
            numb.push_back(upper.at(dis(gen)));
        }
        else if(opt[l] = 's') {

            uniform_int_distribution<>dis(0,29);
            numb.push_back(symbols.at(dis(gen))); 
        }
        else if(opt[l] = 'd') {

            uniform_int_distribution<>dis(0,10);
            numb.push_back(digits.at(dis(gen)));
        }
        else { continue; }

    }

    return numb;

}

string showChkr(string pwd) {

    int steps = 0;
    int ln = length(pwd);
    string syck = symb(pwd);
    vector<int> tree = treeck(pwd);
    
    if(ln != 0) { steps++; }
    if(syck != "") { steps += syck.size() / 2; }
    if(tree.size() > 0) { steps += tree.size(); }
}

int identifyr(string sus) {

    string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string lower {"abcdefghijklmnopqrstuvwxyz"};
    string digits{"0123456789"};
    string symbols {"`~!@#$%^&*()-=_+/|,./;':<>?"+ 0x5C + 0x22};

    if(sus.compare(0, 26, lower)) { return 0;}
    else if (sus.compare(0, 26, upper)) { return 1;}
    else if (sus.compare(0, 10, digits)) { return 2;}
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
        
        gene = generator(symbChk, ln);
        
        for(int l = 0; l < gene.size(); l++) { wrkpwd += gene[l]; }
    }

    else if (ln < 0){
        wrkpwd.erase(wrkpwd.end()+ln, wrkpwd.end()); 
    }
    

    vector<int> pos = treeck(wrkpwd);

    for(int p = 0; p < pos.size(); p++) {

        vector<char> gen = generator("lcds", 4); // s / c // l / d        
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p]))); // l // s 1 // 4 
        gen.erase(gen.begin() + identifyr(to_string(wrkpwd[p+1]))); // d // c 3 // 2 
        wrkpwd.erase(p);
        wrkpwd.insert(p, to_string(gen.at(picker(0,1))));
    }

    return wrkpwd;
}

int main() {

    // Set a passwd
    // Then runn it with moder
    // Do some user-friendly shit ;)

    return 0;
}
