/**
 * 수박수박수박수박수박수?
 * https://programmers.co.kr/learn/courses/30/lessons/12922
 */

#include <bits/stdc++.h>
using namespace std;

// n <= 10000

string solution(int n) {
    string answer = "";
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            answer += "박";
        else
            answer += "수";
    }
    return answer;
}

string solution2(int n) {
    string answer = "";

    // 1은 이진수로 0000...0001 이고
    // 홀수의 이진수는 xxxx...xxx1 이니깐
    // 두 수를 AND 연산하면 항상 1이 리턴됨.
    for (int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << solution(n) << '\n';

    return 0;
}
