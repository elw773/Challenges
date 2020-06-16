#include <iostream>
#include <vector>
using namespace std;

int main(){
    string num;
    int set = 1;
    while(getline(cin, num)){
        int n = stoi(num);
        if(n != 0){
            cout << "SET " << set++ << "\n";
            int b = n/2;
            string names[b];
            int j = 0;
            for(int i=0;i<n;i++){
                string name;
                getline(cin, name);

                if(i%2==0){
                    cout << name << "\n";
                } else {
                    names[j++] = name;
                }
            }
            for(int i=j-1;i>=0;i--){
                cout << names[i] << "\n";
            }     
        } else {
            break;
        }
    }
    
    return 0;
}