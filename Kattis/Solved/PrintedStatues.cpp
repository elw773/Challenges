#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;

    int days = 1;
    
    while(pow(2,(days-1)) < n){
        days ++;
    }

    cout<<days;

    
    
    cout<<endl;
    return 0;
}
