/**
 * 자연수 뒤집어 배열로 만들기
 * https://programmers.co.kr/learn/courses/30/lessons/12932
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    // 이게 더 느려
    // string temp = to_string(n);
    // for_each(temp.rbegin(), temp.rend(), [&answer](char s) -> void {
    //     answer.push_back(s - '0');
    // });

    while(n){
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(123456);

    return 0;
}
