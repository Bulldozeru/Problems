#include "include.h"

using namespace std;

bool matched(regex pattern, string searchTGT) {

    bool found = regex_match(searchTGT, pattern);

    return found;
}

bool conditionToExist(string searchTGT) {

    int min = 1;
    int max = 20;
    
    regex pattern1 {"\\d+"};
    regex pattern2 {"[A-Z]+"};
    regex pattern3 {"\\s+"};
    regex pattern4 {"[[:punct:]]+"};
    if(searchTGT.length() > 20 || searchTGT.length() < 1) { return false; }

    if(regex_search(searchTGT, pattern1) == true) { return false; }
    if(regex_search(searchTGT, pattern2) == true) { return false; }
    if(regex_search(searchTGT, pattern3) == true) { return false; }
    if(regex_search(searchTGT, pattern4) == true) { return false; }
    
    return true;
}

int main() {

    string tgt1 = "AA missile";
    string tgt2 = "garbage Coll3ctor";
    string tgt3 = "h!fen";
    string tgt4 = "N07 n0rm4|_ $7@55 |-|3r3";
    string tgt5 = " ";
    string tgt6 = "";

    string tgt11 = "lockedon";
    string tgt7 = "on";
    string tgt8 = "aa";
    string tgt9 = "aamissile";
    string tgt10 = "aimgx";

    regex patt1 {"[a-z]+"};
    regex patta {"[a]+"};
    regex patton {"[on]+"};
    regex pattaa {"[aa]+"};
    regex pattgx {"[gx]+"};
  
    if(conditionToExist(tgt1) == true) { cout << matched(patt1, tgt1) << "\t" << "TGT1" << endl; }
    if(conditionToExist(tgt2) == true) { cout << matched(patt1, tgt2) << "\t" << "TGT2" << endl; }
    if(conditionToExist(tgt3) == true) { cout << matched(patt1, tgt3) << "\t" << "TGT3" << endl; }
    if(conditionToExist(tgt4) == true) { cout << matched(patt1, tgt4) << "\t" << "TGT4" << endl; }  
    if(conditionToExist(tgt5) == true) { cout << matched(patt1, tgt5) << "\t" << "TGT5" << endl; }  
    if(conditionToExist(tgt6) == true) { cout << matched(patt1, tgt6) << "\t" << "TGT6" << endl; }  
    
    if(conditionToExist(tgt7) == true) { cout << matched(patton, tgt7) << "\t" << "TGT7" << endl; }  
    if(conditionToExist(tgt8) == true) { cout << matched(pattaa, tgt8) << "\t" << "TGT8" << endl; }  
    if(conditionToExist(tgt9) == true) { cout << matched(pattaa, tgt9) << "\t" << "TGT9" << endl; }  
    if(conditionToExist(tgt10) == true) { cout << matched(patta, tgt10) << "\t" << "TGT10" << endl; }  
    if(conditionToExist(tgt10) == true) { cout << matched(pattgx, tgt10) << "\t" << "TGT10" << endl;}  
    if(conditionToExist(tgt11) == true) { cout << matched(patton, tgt11) << "\t" << "TGT11" << endl;}  

    return 0;
    
}
