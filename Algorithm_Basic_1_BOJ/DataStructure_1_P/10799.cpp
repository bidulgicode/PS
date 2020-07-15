/**
 * BOJ_10799_쇠막대기
 * https://www.acmicpc.net/problem/10799
 */
#include <bits/stdc++.h>
using namespace std;

// 막대는 얻어맞은 레이저n개+1개로 잘림
// 올바른 괄호 문자열 문제와 비슷
// ()를 만날때마다 몇개의 막대가 맞는지 '('의 개수를 세어야함 -> 스택에 넣어놨음
// ')'를 만났을때 이게 레이저인지 쇠막대의 끝인지 확인 필요
// 레이저는 무조건 () 이모양임
// 스택에 '(' 인덱스를 넣어서 인덱스가 1차이나냐 아니냐로 레이저 구분
int main(){
    stack<int> s;
    string a;
    cin >> a;
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        if(a[i] == '('){
            s.push(i);
        } else{
            if(s.top()+1 == i){
                // ')'가 나왔는데 인덱스가 직전 '(' 보다 1만 큼
                // 레이저임
                s.pop();
                ans += s.size(); // 여기서 스택 크기 == 잘린 막대수
            } else{
                // 아니면 막대의 끝임
                s.pop();
                ans += 1; // 막대의 끝을 추가 
            }
        }
    }
    cout << ans << '\n';
    return 0;
}