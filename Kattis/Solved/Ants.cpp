#include <iostream>
using namespace std;
//https://open.kattis.com/problems/ants
/*
min = all ants walk straight out dirrection
max = all ants walk opposite (longest you can walk is the l-pos since the longest you can walk before buping is half way)
*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int trials;
    cin>>trials;
    while(trials--){
        int l, n;
        cin>>l>>n;

        int shortest = 0, longest = 0;
        for(int i=0;i<n;i++){
            int ant;
            cin>>ant;
            shortest = max(shortest, min(l-ant, ant));
            longest = max(longest, max(l-ant, ant));
        }
        cout<<shortest<<" "<<longest<<"\n";
    }

    return 0;
}