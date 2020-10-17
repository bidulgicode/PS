/**
 * 제일 작은 수 제거하기
 * https://programmers.co.kr/learn/courses/30/lessons/12935
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    answer.assign(arr.begin(), arr.end());

    if (answer.size() <= 1) {
        answer.front() = -1;
    } else {
        // 최소값구하기
        // sort(arr.begin(), arr.end(), less<int>());
        // int min = arr.front();
        int min = *min_element(arr.begin(), arr.end());  // 이게낫네

        // 최소값이 있는 위치 찾기
        // vector<int>::iterator iter = answer.begin();
        // for (iter; iter < answer.end(); iter++){
        //     if(min == *iter)
        //         answer.erase(iter);
        // }
        int pos = find(answer.begin(), answer.end(), min) - answer.begin();

        // 찾아가서 제거    
        answer.erase(answer.begin() + pos);
    }

    // if로 안거르고 일단 1개가 있더라도 제거하면 아래것이 낫다
    // return answer.empty() ? vector<int>(1, -1) : answer; 
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
