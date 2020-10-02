/**
 * 정수 내림차순으로 배치하기
 * https://programmers.co.kr/learn/courses/30/lessons/12933
 */

#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    string temp = to_string(n);
    // sort(temp.begin(), temp.end(), [](int u, int v) {
    //     return u > v;
    // });
    // c++14 버전부터는 템플릿을 통한 타입 추론이 가능해서 greater<>() 이래도 됨
    sort(temp.begin(), temp.end(), greater<char>());
    answer = stoll(temp);
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(118372);

    return 0;
}
