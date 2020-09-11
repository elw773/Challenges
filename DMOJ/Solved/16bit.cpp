#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    long long a, b, p;

    while(n--){
        cin>>a>>b>>p;
        if(a*b == p){
            cout<<"POSSIBLE DOUBLE SIGMA\n";
        } else {
            cout<<"16 BIT S/W ONLY\n";
        }
    }

    return 0;
}