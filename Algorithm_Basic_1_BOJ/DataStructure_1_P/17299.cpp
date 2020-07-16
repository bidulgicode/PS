/**
 * BOJ_17299_오등큰수
 * https://www.acmicpc.net/problem/17299
 */
#include <bits/stdc++.h>
using namespace std;

// brute force - O(N^2)로 풀면 시간초과임
// 바로 전에 풀었던 오큰수처럼 monotone stack 이용
int freq[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> inputs(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        cin >> inputs[i];
        freq[inputs[i]] += 1;   // 입력값별로 빈도수 저장함
    }

    stack<int> s; // 오등큰수 찾아야 하는애들의 인덱스 저장용
    s.push(0);
    for (int i = 1; i < n; i++){
        if(s.empty()) {
            s.push(i);
        }
        // 오큰수와 달리 입력된 숫자가 몇번이나 등장했나가 비교대상임
        while(!s.empty() && freq[inputs[s.top()]] < freq[inputs[i]]){
            ans[s.top()] = inputs[i];
            s.pop(); // inputs[s.top()]의 오등큰수를 찾았으니 저장용 스택에서 뺀다.
        }
        s.push(i);
    }
    // 여기까지 오면 s에 저장된 인덱스에 해당하는 수들은 오등큰수 못찾은거임
    while(!s.empty()){
        ans[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}