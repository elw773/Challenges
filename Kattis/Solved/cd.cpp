#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
//https://open.kattis.com/problems/cd


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    
    while((cin>>a>>b) && !(a == 0 && b == 0)){
        int sell = 0;
        int id;

        std::vector<std::bitset<1000000001>> wrapper(1);
        auto & ids = wrapper[0];

        for(int i=0;i<a;i++){
            cin>>id;
            ids[id] = 1;
        }
        for(int i=0;i<b;i++){
            cin>>id;
            sell += ids[id];
        }
        
        cout<<sell<<"\n";
    }

    return 0;
}