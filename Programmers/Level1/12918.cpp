/**
 * 문자열 다루기 기본
 * https://programmers.co.kr/learn/courses/30/lessons/12918
 * isdigit
 */
#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    bool answer = true;
    // 길이
    // if (s.length() != 4 && s.length() != 6) return false;
    if (s.size() == 4 || s.size() == 6) {
        for (char c : s) {
            if (c < '0' || c > '9')
                answer = false;
        }
    } else {
        answer = false;
    }

    return answer;
}

bool solution2(string s) {
    bool answer = true;

    for (char c : s) {
        if (isdigit(c) == false) // 이런게있네
            return false;
    }

    if (s.length() != 4 && s.length() != 6)
        return false;

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    cout << solution(s) << '\n';

    return 0;
}
