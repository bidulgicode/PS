/**
 * 문자열 내림순으로 배치하기
 * https://programmers.co.kr/learn/courses/30/lessons/12917
 */
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    // a > Z
    sort(s.begin(), s.end(), [](char u, char v) {
        // sort는 기본적으로 오름차순 정렬
        // Strick week Ordering, 즉 두개의 객체를 비교해서 
        // 첫번째가 두번째보다 작으면 true 그렇지 않다면 false를 리턴합니다.
        // 내부적으로는 퀵소트라는데
        // 왼쪽이 다음 비교대상이 되지 않는다면 true임
        return u > v;
    });
    return s;
}

string solution2(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    cout << solution(s) << '\n';
    return 0;
}
