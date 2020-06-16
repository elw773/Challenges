#include <iostream>
#include <vector>
using namespace std;
//https://open.kattis.com/problems/2048
int main(){
    int board[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>board[i][j];
        }
        cin.ignore(1,'\n');
    }
    int direction;
    cin>>direction;

    int di = 0;
    int dj = 0;
    switch(direction){
        case 0: dj = -1; break;
        case 1: di = -1; break;
        case 2: dj = 1; break;
        case 3: di = 1; break;
    }

    bool added[4][4] = {};

    bool anyMoved = true;
    while(anyMoved){
        anyMoved = false;
        for(int i=(di==-1?0:3);i<4&&i>=0;i+=(di==-1?1:-1)){
            for(int j=(dj==-1?0:3);j<4&&j>=0;j+=(dj==-1?1:-1)){
                if( board[i][j] != 0 && 
                    (0 <= i+di && i+di < 4) && 
                    (0 <= j+dj && j+dj < 4) && 
                    (board[i+di][j+dj] == 0 || 
                    (board[i][j] == board[i+di][j+dj] && !added[i][j] && !added[i+di][j+dj]))){

                    if(board[i][j] == board[i+di][j+dj]){
                        added[i][j] = true;
                    }
                    
                    board[i+di][j+dj] += board[i][j];
                    board[i][j] = 0;
                    added[i+di][j+dj] = added[i][j];
                    added[i][j] = false;
                    anyMoved = true;
                }
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}