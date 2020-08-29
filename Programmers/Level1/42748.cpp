/**
 * K번째수 (정렬)
 * https://programmers.co.kr/learn/courses/30/lessons/42748
 * 주어진 배열에서 필요한 부분만 잘라다가 사용하는 방법을 생각해보자.
 * 대부분 임시벡터 하나 만들어서 거따가 새로 만드는듯?
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto cmd : commands) {
        // cmd
        // 0 min cut
        // 1 max cut
        // 2 get index
        vector<int> tempVec(array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
        sort(tempVec.begin(), tempVec.end());
        answer.push_back(tempVec[cmd[2] - 1]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> array{{
        1,
        5,
        2,
        6,
        3,
        7,
        4,
    }};
    vector<vector<int>> commands{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    solution(array, commands);

    return 0;
}
