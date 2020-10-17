/**
 * https://programmers.co.kr/learn/courses/30/lessons/12934
 * 정수 제곱근 판별
 */

#include <bits/stdc++.h>
using namespace std;

bool IsInteger(long long d){
    return floor(d) == d;
}

long long solution(long long n) {
    long long answer = 0;

    long long sq = sqrt(n);

    // pow, powl
    // pow<long double, int> 조합은 C++에서만 됨
    if(n != pow(sq, 2)){
        answer = -1;
    }else{
        answer = pow(sq + 1, 2);
    }

    // if(IsInteger(sq)){
    //     answer = pow(sq + 1, 2);
    // } else {
    //     answer = -1;
    // }

    return answer;
}

long long solution2(long long n) {
    long long answer = sqrt(n);

    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(3);

    return 0;
}
