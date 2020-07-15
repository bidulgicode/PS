/**
 * BOJ_17298_오큰수
 * https://www.acmicpc.net/problem/17298
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    stack<int> s; // 오큰수 못찾은애들 위치 저장용
    s.push(0); // 0번 인덱스는 넣고 시작.
    for (int i = 1; i < n; i++){
        if(s.empty()){
            s.push(i);
        }
        while(!s.empty() && a[s.top()] < a[i]){
            // 맨 처음 a[s.top()]은 a[0]과 같다 -> 위에서 0 넣어놨음
            // s에는 오큰수를 찾지 못한 인덱스들이 들어가있음
            // s에 들어간 인덱스들이 가리키는 숫자들은 내림차순임
            // s[0] = 1, s[1] = 5, s[2] = 2 이런식은 안됨 왜냐면
            // s[1]이 s[0]의 오큰수라 바로 찾아낼것이기 때문
            // 그러므로 while이 돌다 멈추더라도 
            // a[i]가 스택안에서 비교되지 못한 인덱스들의 오큰수가 될 수 없음.
            ans[s.top()] = a[i];
            s.pop(); // 답을 찾아낸 인덱스는 뺀다.
        }
        s.push(i);  // 현재 위치를 스택에 넣는다.
    }
    // 여기까지 왔으면 오큰수 못찾은거임
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}