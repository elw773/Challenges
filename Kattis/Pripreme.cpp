#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long longest = 0, total = 0;
    long long curr;
    while(n--){
        cin>>curr;
        longest = max(curr, longest);
        total+=curr;
    }
    cout<<max(total, longest*2)<<endl;

    return 0;
}