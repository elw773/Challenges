#include <iostream>
using namespace std;
//https://open.kattis.com/problems/compass


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    int angle = b-a;
    if(angle<=-180){
        angle+=360;
    } else if(angle>180){
        angle-=360;
    }
    cout<<angle<<endl;

    return 0;
}