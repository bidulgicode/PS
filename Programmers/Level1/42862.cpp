/**
 * 체육복
 * https://programmers.co.kr/learn/courses/30/lessons/42862
 */

#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clotheCount;
    clotheCount.assign(n + 1, 1);
    clotheCount[0] = 0;

    for (auto i : lost) {
        clotheCount[i] -= 1;
    }
    for (auto j : reserve) {
        clotheCount[j] += 1;
    }

    for (int i = 1; i <= n; i++) {
        if (clotheCount[i] == 0 && 1 < i < n) {
            if (clotheCount[i - 1] == 2) {
                clotheCount[i] += 1;
                clotheCount[i - 1] -= 1;
            } else if (clotheCount[i + 1] == 2) {
                clotheCount[i] += 1;
                clotheCount[i + 1] -= 1;
            }
        } else {
            if (i == 1 && clotheCount[i + 1] == 2) {
                clotheCount[i] += 1;
                clotheCount[i + 1] -= 1;
            } else if (i == n && clotheCount[i - 1] == 2) {
                clotheCount[i] += 1;
                clotheCount[i - 1] -= 1;
            }
        }
    }

    for (auto i : clotheCount) {
        if (i >= 1) {
            answer += 1;
        }
    }

    return answer;
}

// 선처리 -> lost와 reserve 배열을 비교해서 같은번호가 있으면 두 배열에서 다 뺀다.

// iterator 사용해서 풀은 예
int solution2(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lostSize = lost.size();
    int reserveSize = reserve.size();

    int numLeft, numRight;

    // reserve 순회하면서 동일한 값이 lost에 있으면 양쪽다 지움
    vector<int>::iterator iterLost, iterReserve;
    for (iterReserve = reserve.begin(); iterReserve != reserve.end();) {
        // reserve.begin()값 기준으로 lost값과 비교
        for (iterLost = lost.begin(); iterLost != lost.end();) {
            if (*iterLost == *iterReserve) {
                // 있으면 양쪽다 지움
                lost.erase(iterLost);
                reserve.erase(iterReserve);
                break;
            } else {
                // 없음, lost배열의 다른 값으로 한칸 이동
                iterLost++;
            }
        }

        if (reserveSize != reserve.size()) {
            // reserve.size()가 바뀌었으면
            // reserve.begin() 값이 reserve 배열에 있었다는거임
            reserveSize = reserve.size();
        } else {
            // 여기 왔으면 reserve.begin()의 짝이 없었다는 소리니
            // reserve 배열의 다음값으로 이동
            iterReserve++;
        }
    }

    // reserveSize = reserve.size();  // 이제 안쓰니깐 갱신 안해줘도 상관없을듯

    for (iterReserve = reserve.begin(); iterReserve != reserve.end(); iterReserve++) {
        numLeft = *iterReserve - 1;
        numRight = *iterReserve + 1;
        for (iterLost = lost.begin(); iterLost != lost.end();) {
            if (*iterLost == numLeft || *iterLost == numRight) {
                lost.erase(iterLost);
                break;
            } else {
                iterLost++;
            }
        }
    }

    answer = n - lost.size();

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(5, vector<int>{2, 4}, vector<int>{1, 3, 5});
    solution2(5, vector<int>{2, 4}, vector<int>{1, 3, 5});

    return 0;
}
