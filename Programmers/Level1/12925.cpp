/**
 * 문자열을 정수로 바꾸기
 * https://programmers.co.kr/learn/courses/30/lessons/12925
 * 뭐임??
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> inputs;
    for (char item : s) {
        inputs.push_back(item);
    }

    // 부호체크
    if (inputs.front() == '-') {
        // 음수
        string temp(inputs.begin() + 1, inputs.end());
        answer = stoi(temp) * -1;

    } else {
        // 양수
        string temp(inputs.begin(), inputs.end());
        answer = stoi(temp);
    }

    return answer;
}

int solution2(string s) {
    // 위 뻘짓 말고
    return stoi(s); // 이러면 됨
}

int main() {
    string s;
    getline(cin, s); // 띄어쓰기 없는것 같지만
    cout << solution(s) << '\n';
    return 0;
}