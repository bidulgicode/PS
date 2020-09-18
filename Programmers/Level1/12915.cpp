/**
 * 문자열 내 마음대로 정렬하기
 * https://programmers.co.kr/learn/courses/30/lessons/12915
 */
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    sort(strings.begin(), strings.end(), [n](const string &u, const string &v) {
        // 이 안에서 u, v가 수정되면 안됨. 그냥 비교용으로만 쓴다.
        int compare;

        if(u.at(n) != v.at(n)){
            compare = u.at(n) < v.at(n);
        } else {
            compare = u < v;
        }

        return compare;
    });

    answer.assign(strings.begin(), strings.end());

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(vector<string>{"abca", "abcb", "abc"}, 1);

    return 0;
}
