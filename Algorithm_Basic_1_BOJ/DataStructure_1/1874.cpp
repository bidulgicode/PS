// BOJ 1874 스택 수열
#include <bits/stdc++.h>
using namespace std;

// 범위 1 < n < 100000

int main(){
    stack<int> s;
    int n;
    string ans; // 뿌려줄 답안

    cin >> n;

    int m = 0; // 스택에 들어갈 값

    while(n--){
        int x;  // 만들어야하는수
        cin >> x;
        if(x > m){
            while(x > m){
                s.push(++m); // m부터 x까지 모든수를 push
                ans += '+';
            }
            // x == m
            s.pop();
            ans += '-';
        } else {
            // x <= m 수열에 들어가야하는 숫자가 스택에 추가될 숫자보다 작으면?
            // m을 그만 늘리고 스택의 top을 확인
            bool isFound = false;

            if(!s.empty()){
                int top = s.top();
                s.pop();
                ans += '-';
                if(x == top){
                    // 스택 최상단 숫자가 x와 같아야함
                    // 아니면 스택의 값을 버려야하니 성립안됨
                    isFound = true;
                }
            }

            if(!isFound){
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    for (auto x : ans){
        cout << x << '\n';
    }
    return 0;
}