/**
 * 서울에서 김서방 찾기
 * https://programmers.co.kr/learn/courses/30/lessons/12919
 */
#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int i = 0;
    for (string s : seoul) {        
        if(s.compare("Kim") == 0)
            break;
        i++;
    }
    answer = "김서방은 " + to_string(i) + "에 있다";
    return answer;
}

string solution2(vector<string> seoul) {
    string answer = "";
    // iterator을 '-'연산하면 서로의 위치값을 빼서 거리가 나오네
    int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer = "김서방은 " + to_string(pos) + "에 있다";
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v = {"Jane", "Kim"};
    cout << solution(v) << '\n';
    return 0;
}