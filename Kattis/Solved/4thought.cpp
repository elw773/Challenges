#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int evaluate(char operators[]){
    int ans[4] = {4, 4, 4, 4};

    int j=0;
    for(int i=0;i<3;i++){
        if(operators[i] == '*'){
            ans[j] = ans[j] * ans[j+1];
        } else if(operators[i] == '/'){
            ans[j] = ans[j] / ans[j+1];
        } else {
            j++;
        }
    }

    j=0;
    for(int i=0;i<3;i++){
        if(operators[i] == '+'){
            ans[j] = ans[j] + ans[j+1];
            ans[j+1] = ans[j+2];
        } else if(operators[i] == '-'){
            ans[j] = ans[j] - ans[j+1];
            ans[j+1] = ans[j+2];
        }
    }
    return ans[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int,string> answers;

    char operators[4] = {'+', '-', '*', '/'};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                char curr[3] = {operators[i], operators[j], operators[k]};
                int ans = evaluate(curr);
                char str[30];
                sprintf(str, "4 %c 4 %c 4 %c 4 = %d", curr[0], curr[1], curr[2], ans);
                string strng = str;
                answers.emplace(ans, strng);
            }
        }
    }

    int n;
    cin>>n;
    while(n--){
        int goal;
        cin>>goal;
        auto ans = answers.find(goal);
        if(ans==answers.end()){
            cout<<"no solution"<<"\n";
        } else {
            cout<<ans->second<<"\n";
        }
    }
    return 0;
}
