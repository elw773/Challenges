#include <iostream>
using namespace std;
//https://open.kattis.com/problems/listgame

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin>>x;

    int y = 0;

    for(int p=2;p*p<=x;){
        if(x%p == 0){
            x = x/p;
            y++;
        } else {
            p++;
        }
    }

    y++;
    cout<<y<<endl;
}