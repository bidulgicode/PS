/**
 * 2016년
 * https://programmers.co.kr/learn/courses/30/lessons/12901
 */

#include <bits/stdc++.h>
using namespace std;

// 2016년 1월 1일은 금요일, 같은 달인 경우 +7 단위로 요일이 같다
// 윤년, 2월 29일까지
// 121 + 24 = 145
// 145 % 7 = 5 -> 2


// 121 + 23 = 144
// 4 -> 1
// 
// 146 % 7 = 6

// 31 29 31 30 31 30 31 31 30 31 30 31

string solution(int a, int b) {
    string answer = "";
    // a = 월, b = 일
    int months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int d = 0;

    for (int i = 1; i < a; i++){
        d += months[i];
    }
    d += b - 1; //r
    d %= 7;
    answer = days[d];

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution(5, 24);

    return 0;
}
