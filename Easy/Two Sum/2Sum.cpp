#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Function for solution resolver
vector<int> seeker(vector<int> sq, int tgt) {

    vector<int> sol;
    vector<int> probe;
    
    for(int n = 0; n < sq.size(); n++) {
        
        int t {tgt};
        probe.push_back(t - sq.at(n));

    }

    for(int n = 0; n < sq.size(); n++) {
        auto src = find(sq.begin(), sq.end(), probe.at(n));
        if(*src != 0) { sol.push_back(n); } 
        int h = 0;
    }

    return sol;
}

// Function to check if TGT or nums have negative values 
bool negProbe(int tgt, vector<int> sq) {

    string tgtInf = "+";
    string vectInf = "+";
    int c = 0;

    if(tgt < 0) { tgtInf = "-"; }

    for(int n = 0; n < sq.size(); n++) {

        if(sq.at(n) < 0) { vectInf = "-";}
        else {c++;}
    }

    if(c == 0) { vectInf = "--";}

    if(tgtInf == "-" && vectInf == "+") {
        return false;
    }
    else if(tgtInf == "+" && vectInf == "--") {
        return false;
    }
    else { return true; }
}

// Function for checking criteria
bool probe(int tgt, vector<int> sq) {


    int bill = 1000000000;
    int size = sq.size();

    if(size < 2 || size > 10000) {return false;}
    if(tgt < -bill || tgt > bill) {return false;}
    for(int n = 0; n < size; n++) {

        int numb = sq.at(n);
        if (numb < -bill || numb > bill) { return false;}
    }

    return true;

}

int main() {

    int tgt = 556;
    vector<int> sequ = {5,56,550,6}
    bool ngPrb = negProbe(tgt, sequ);
    bool prb = probe(tgt, sequ);

    if(ngPrb != true || prb != true) {

        cout << "[x] ERROR: Passed TGT or Sequence did not meet the criteria \nProbe: " << prb << "\nNegative Probe: " << ngPrb << endl << "Exiting...\n";
        exit(-1);
    }

    vector<int> sol = seeker(sequ, tgt);

    if(sol.size() != 2) { 
        
        cout << "[x] ERROR: The Solution has less or too many elements " << "\nSolution Elements Number: "<< sol.size() << "\nExiting... \n";
        exit(-1);
    }
    else if(sol.size() == 0) {
        cout << "[-] No valid solution has been found \n[0] Exiting...\n";
    }

    cout << "[+] Solution: \n";

    for(int n = 0; n < sol.size(); n++) {
        cout << sol.at(n) << endl;
        
    }

    return 0;
}
