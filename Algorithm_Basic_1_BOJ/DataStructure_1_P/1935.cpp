/** 후위 표기식 2
 * https://www.acmicpc.net/problem/1935
 */

#include <bits/stdc++.h>
using namespace std;
int operand[26]; // 1 <= n <= 26;
int main(){
    int n;
    cin >> n;

    string postfix; // ABC*+DE/-
    cin >> postfix;
    for (int i = 0; i < n; i++){
        cin >> operand[i]; // ABCDE~~에 대응되는 숫자들
    }
    stack<double> s;
    for(char ch : postfix){
        if( ch >= 'A' && ch <= 'Z'){
            // A~Z 아스키코드는 연속적이라서
            // A기준으로 뺴면 위에 operand와 대응가능
            s.push((double)operand[ch - 'A']);
        } else {
            // 연산자면 스택에서 숫자 두개를 꺼내 계산 후 다시넣음
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();
            if(ch == '+'){
                s.push(op1 + op2);
            }else if(ch == '-'){
                s.push(op1 - op2);
            }else if(ch == '*'){
                s.push(op1 * op2);
            }else if(ch == '/'){
                s.push(op1 / op2);
            }
        }
    }
    // setprecision(n) 정수부+소수부 합쳐서 n자리를 반올림해서 출력
    // fixed + setprecision(n) 소수부만 따져서 n자리를 반올림해서 출력
    cout << fixed << setprecision(2) << s.top() << '\n';
    return 0;
}