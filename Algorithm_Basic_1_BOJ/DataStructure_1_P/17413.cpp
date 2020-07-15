/**
 * BOJ_17413_단어뒤집기2
 * https://www.acmicpc.net/problem/17413
 * https://torbjorn.tistory.com/155
 * FSM으로 푼 버전
 */
#include <bits/stdc++.h>
using namespace std;

void print(stack<char> &s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);  // 띄어쓰기가 포함된 입력은 getline으로 받는다.
    bool tag = false;
    stack<char> s;

    for(char ch : str){
        if(ch == '<') {
            // 태그시작
            print(s); // 태그시작 전까지 stack에 쌓였던 문자를 뱉는다
            tag = true;
            cout << ch;
        } else if(ch == '>'){
            // 태그끝
            tag = false;
            cout << ch;
        } else if (tag) {
            cout << ch; // 태그상태면 그냥 뱉으면 됨
        } else {
            if(ch == ' '){
                print(s); // 띄어쓰기 직전까지 저장한거 뱉고
                cout << ch;
            } else {
                s.push(ch); // 아니면 뒤집기 위해 스택에 쌓음
            }
        }
    }

    print(s); // 스택에서 미처 못뺸놈 털고 끝냄
    cout << '\n';
    return 0;
}