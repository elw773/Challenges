#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//https://open.kattis.com/problems/classy

void addModifier(string &rank, string modifier, int k){
    if(modifier == "upper"){
        rank[k] = 'a';
    } else if(modifier == "middle"){
        rank[k] = 'b';
    } else if(modifier == "lower"){
        rank[k] = 'c';
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases, n;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cin>>n;

    string ppl[n];
    for(int j=0;j<n;j++){
      string name;
      cin>>name;
      name.pop_back();

      string modifiers;
      cin>>modifiers;

      string c;
      cin>>c;

      int k = 9;
      string rank = "bbbbbbbbbb";
      int pos;
      while ((pos = modifiers.find('-')) != std::string::npos) {
        string modifier = modifiers.substr(0, pos);
        addModifier(rank, modifier, k--);
        modifiers.erase(0, pos + 1);
      }
      addModifier(rank, modifiers, k);
      if(k>0){
        for(int m=0;m<10-k;m++){
          rank[m] = rank[k+m];
          rank[m+k] = 'b';
        }
      }
      ppl[j] = rank + name;
    }
    int N = sizeof(ppl)/sizeof(ppl[0]);

    sort(ppl,ppl+N);

    for(int j=0;j<n;j++){
      cout<<ppl[j].substr(10,ppl[j].length())<<"\n";
    }
    cout<<"=============================="<<"\n";
  }

  return 0;
}
