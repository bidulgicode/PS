/**
 * 자릿수 더하기
 * https://programmers.co.kr/learn/courses/30/lessons/12931
 */
#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int answer = 0;

    string temp = to_string(n);

    for(auto item : temp){
        answer += item - '0';
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(123);

    return 0;
}
