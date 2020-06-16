#include <iostream>
using namespace std;

// does not work for some reason

void insert(pair<string, string> ppl[], int n, pair<string, string> person){
    int i = 0;
    
    while(i > 0 && (ppl[i].first == " " || ppl[i].first.compare(person.first)>0)){
        ppl[i] = ppl[i-1];
        i--;
    }
    ppl[i] = person;
}

void replace(string &phrase, string find, string replace){
    int i=0;
    int flength = find.length();
    while(phrase.find(find, i) != string::npos){
        i = phrase.find(find, i);
        phrase.replace(i,flength,replace);
    }
}

int main(){

    int cases, n;
    string in;
    getline(cin, in);
    cases = stoi(in);
    
    for(int i=0;i<cases;i++){
        getline(cin, in);
        n = stoi(in);
        pair<string, string> ppl[n];
        for(int j=0;j<cases;j++){
            string line;
            getline(cin, line);
            pair<string, string> person;
            person.second = line.substr(0, line.find(":"));
            int sequenceStart = line.find(":")+2;
            string sequence = line.substr(sequenceStart, line.find(" ",sequenceStart)-sequenceStart);

            replace(sequence, "upper", "a");
            replace(sequence, "middle", "b");
            replace(sequence, "lower", "c");
            replace(sequence, "-", "");

            person.first = "bbbbbbbbbb";
            int m = 0;
            for(int k=sequence.length()-1;k>=0;k--){
                person.first.at(m++) = sequence.at(k);
            }
            insert(ppl, n, person);
        }
        for(int j=0;j<n;j++){
            cout<<ppl[j].second<<"\n";
        }
        cout<<"==============================\n";
    }

    return 0;
}