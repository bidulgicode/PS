/**
 * 이상한 문자 만들기
 * https://programmers.co.kr/learn/courses/30/lessons/12930
 */

#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";

    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += " ";
            n = 0;
        } else if (n == 0 || n % 2 == 0) {
            answer += toupper(s[i]);
            n++;
        } else {
            answer += tolower(s[i]);
            n++;
        }
    }
    return answer;
}

// 생성한 idx의 숫자로 홀수 짝수 구분 않고, idx 1번은 무조건 짝수, 다음은 홀수식으로 했네

string solution2(string s) {
    string answer = "";
    int nIndex = 1;
    for (int i = 0; i < s.size(); i++, nIndex++)
    {
        if (s[i] == ' ')
        {
            nIndex = 0;
            answer += " ";
        }
        else
            nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}

// 이게 깔끔하다
string solution3(string s) {
    int idx = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') { idx = 1; continue; }
        s[i] = (idx % 2 == 1) ? toupper(s[i]) : tolower(s[i]);
        idx++;
    }
    return s;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution2("HeLLo");

    return 0;
}
