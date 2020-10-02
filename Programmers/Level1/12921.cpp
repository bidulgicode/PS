/**
 * 소수 찾기
 * https://programmers.co.kr/learn/courses/30/lessons/12921
 */

#include <bits/stdc++.h>
using namespace std;

bool check[100];

int solution(int n) {
    int answer = 0;
    // 1 ~ n
    // 시작 2

    check[0] = check[1] = true;  // 0,1은 소수아니다.
    for (int i = 2; i * i <= n; i++) {
        if (check[i] == false) {
            for (int j = i + i; j <= n; j += i) {
                check[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (check[i] == false) {
            answer++;
        }
    }
    cout << answer << endl;
    return answer;
}

int solution2(int n) {
    int answer = 0;
    vector<bool> tmp(n + 1, true);

    for (int i = 2; i < n + 1; i++) {
        if (tmp[i] == true) {
            for (int j = 2; i * j < n + 1; j++) tmp[i * j] = false;
            answer++;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution(10);
    solution(5);

    return 0;
}
