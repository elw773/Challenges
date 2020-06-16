#include <iostream>
#include <vector>
using namespace std;
//https://open.kattis.com/problems/skener
int main(){
    int r, c, zr, zc;
    cin>>r>>c>>zr>>zc;

    char out[r*zr][c*zc]; //y,x

    for(int i=0;i<r*zr;i+=zr){
        cin.ignore(2,'\n');
        for(int j=0;j<c*zc;j+=zc){
            char ch;
            cin.get(ch);
            
            for(int zi=0; zi<zr;zi++){
                 for(int zj=0; zj<zc;zj++){
                     out[i+zi][j+zj] = ch;
                }
            }
        } 
    }

    for(int i=0;i<r*zr;i++){
        for(int j=0;j<c*zc;j++){
            cout<<out[i][j];
        }
        cout<<endl;
    }

    return 0;
}