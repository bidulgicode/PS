/**
 * 가운데 글자 가져오기
 * https://programmers.co.kr/learn/courses/30/lessons/12903
 */

#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int midNum = s.length() / 2;
    if (s.size() % 2 == 0) {
        //짝수
        answer = s.substr(midNum - 1, 2);

    } else {
        // 홀수
        answer = s[midNum];
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    cout << solution(s) << '\n';

    return 0;
}
