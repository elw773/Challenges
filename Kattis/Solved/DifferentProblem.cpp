#include <iostream>
using namespace std;
//https://open.kattis.com/problems/different


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    while(cin>>a>>b){
        cout<<abs(a-b)<<endl;
    }

    return 0;
}