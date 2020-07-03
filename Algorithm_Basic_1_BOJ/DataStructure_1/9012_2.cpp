// withstack

#include <bits/stdc++.h>
using namespace std;

string Valid(string s){
    stack<char> _stack;

    for(char ch : s){
        if(ch == '(') {
            _stack.push(ch);
        }else{
            if(_stack.empty())
                return "NO";
            
            _stack.pop();
        }
    }

    if(_stack.empty())
        return "YES";
    else
        return "NO";
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        cout << Valid(s) << '\n';
    }

    return 0;
}