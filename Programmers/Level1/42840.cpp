/**
 * 모의고사 (완전탐색 - bruteforce)
 * https://programmers.co.kr/learn/courses/30/lessons/42840
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// 찍는 패턴이 총 3가지
vector<int> one = {1, 2, 3, 4, 5};
vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> result;
    vector<int> count(3);

    // 입력값에 대해, 세가지 답안 패턴을 다 대입해보고 있음.
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % one.size()]) count[0]++; // 0~4
        if (answers[i] == two[i % two.size()]) count[1]++; // 0~7
        if (answers[i] == three[i % three.size()]) count[2]++; // 0~9
        // 만약 패턴이 10개가 넘어가면??
    }

    // 맞춘 개수중에 가장 큰 것 구하기
    int maxCount = *max_element(count.begin(), count.end());

    // find(count.begin(), count.end(), maxCount);
   
    // vector<int>::iterator iter;
    // for (iter = count.begin(); iter != count.end(); iter++){
    //     if (*iter == maxCount) result.push_back(distance(count.begin(), iter) + 1);
    // }

    for (int i = 0; i < count.size(); i++) {
        if (count[i] == maxCount) result.push_back(i + 1);  // 사람 번호가 1번부터임
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
