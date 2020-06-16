#include <iostream>
#include <cmath>
using namespace std;

//doesnt work for some reason

int evaluatePostFix(char postfix[]){
    int stack[4];
    int stacki=0;
    for(int i=0;i<7;i++){
        if(postfix[i]=='4'){
            stack[stacki]=4;
            stacki++;
        } else {
            switch(postfix[i]){
                case '+': stack[stacki-2] = stack[stacki-2] + stack[stacki-1]; stacki--; break;
                case '-': stack[stacki-2] = stack[stacki-2] - stack[stacki-1]; stacki--; break;
                case '*': stack[stacki-2] = stack[stacki-2] * stack[stacki-1]; stacki--; break;
                case '/': 
                    if(stack[stacki-2] != 0){
                        stack[stacki-2] = stack[stacki-2] / stack[stacki-1];
                        stacki--;
                    } else {
                        return 1111111;
                    }
                    break;
            }
        }
    }
    return stack[0];
}

void newOperator(char postfix[], char operators[], int precedence[], int postOps[], int &j, int &k, int &i){
        if(k==0){
            postOps[k++] = i;
        } else if(precedence[i] > precedence[postOps[k-1]]){
            postOps[k++]=i;
        } else if(precedence[i] == precedence[postOps[k-1]]){
            postfix[j++] = operators[postOps[k-1]];
            postOps[k-1] = i; 
        } else if(precedence[i] < precedence[postOps[k-1]]){
            postfix[j++] = operators[postOps[k-1]];
            k--;
            newOperator(postfix, operators, precedence, postOps, j, k, i);
        }
}

int solve(char operators[]){
    int precedence[3] = {};
    char postfix[7];
    for(int i=0;i<3;i++){
        precedence[i] = (operators[i]=='*'||operators[i]=='/')?1:0;
    }

    int j=0;
    int k=0;
    int postOps[3]={-1};
    for(int i=0;i<3;i++){
        postfix[j++] = '4';
        newOperator(postfix, operators, precedence, postOps, j, k, i);
    }
    postfix[j++] = '4';
    for(int i=k-1;i>=0;i--){
        postfix[j++] = operators[postOps[i]];
    }

    return evaluatePostFix(postfix);
}

void findExpression(int goal){
    char operators[4] = {'+', '-', '*', '/'};
    bool solved;
    for(int i=0;i<4&&!solved;i++){
        for(int j=0;j<4&&!solved;j++){
            for(int k=0;k<4&&!solved;k++){
                char curr[3] = {operators[i], operators[j], operators[k]};
                int ans = solve(curr);
                if(goal == ans){
                    cout<<"4 "<<operators[i]<<" 4 "<<operators[j]<<" 4 "<<operators[k]<<" 4 = "<<goal<<"\n";
                    solved = true;
                }
            }
        }
    }
    if(!solved){
        cout<<"no solution"<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int goal;
        cin>>goal;
        findExpression(goal);
    }
    return 0;
}