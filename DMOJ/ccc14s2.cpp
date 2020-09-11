#include <iostream>
#include <map>
using namespace std;

//https://dmoj.ca/problem/ccc14s2

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    if(n%2){
        cout<<"bad\n";
    } else {
        int arr[n];

        string names[n];
        for(int i=0;i<n;i++){
            cin>>names[i];
        }

        string name;
        for(int i=0;i<n;i++){
            cin>>name;
            for(int j=0;j<n;j++){
                if(name == names[j]){
                    arr[i] == j;
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(arr[arr[i]]!=i){
                cout<<"bad\n";
                return 0;
            }
        }
        cout<<"good\n";
    }

    return 0;
}