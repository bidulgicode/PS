/**
 * 두 정수 사이의 합
 * https://programmers.co.kr/learn/courses/30/lessons/12912
 */
#include <bits/stdc++.h>
using namespace std;

// -10,000,000 <= a,b <= 10,000,000

long long solution(int a, int b) {
    long long answer = 0;
    if (a == b) return a;

    if (a > b) {
        while (a >= b) {
            answer += b;
            b++;
        }
    } else {
        while (a <= b) {
            answer += a;
            a++;
        }
    }

    return answer;
}

long long solution2(int a, int b) {
    // 가우스 등차수열 합
    // (a+b)*n/2
    // (abs(a - b) + 1) 은 a~b 까지 개수가 몇개인지 구하는거
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
