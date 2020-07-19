/**
 * BOJ_1918_후위표기식
 * https://www.acmicpc.net/problem/1918
 */
#include <bits/stdc++.h>

using namespace std;

// 연산자 우선순위 반환
int getOpsPriority(char ch){
    if(ch == '(')
        return 0;
    if(ch == '+' || ch == '-')
        return 1;
    else
        return 2; // 곱하기 나누기같은애들
}

int main(){
    string s;
    cin >> s;
    string ans;
    stack<char> operators;
    for(char ch : s){
        if('A' <= ch && ch <= 'Z'){
            ans += ch;  // 문자면 무조건 답안에 추가
        } else if (ch == '('){
            operators.push(ch);
        } else if (ch == ')'){
            // 닫는괄호면 '(' 나올때까지 연산자 스택에서 계속 뽑아냄
            while(!operators.empty()){
                char op = operators.top();
                operators.pop();
                // 닫는괄호면 그만뽑아내고
                if(op == '(')
                    break;
                // 아니면 그 연산자를 답안에 즉시 추가
                ans += op;
            }
        } else {
            // 현재 연산자의 우선순위가
            // 스택에 가장 위에 있는 연산자의 우선순위보다
            // 작거나 같은 동안 스택에 있는 연산자를 결과에 추가
            while(!operators.empty()
            && getOpsPriority(ch) <= getOpsPriority(operators.top())) {
                ans += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    //남은 연산자 다 꺼냄
    while(!operators.empty()){
        char op = operators.top();
        operators.pop();
        ans += op;
    }
    cout << ans << '\n';
    return 0;
}