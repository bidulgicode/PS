/**
 * 문자열 내 p와 y의 개수
 * https://programmers.co.kr/learn/courses/30/lessons/12916
 */
#include <bits/stdc++.h>
using namespace std;

bool solution(string s) // s <= 50
{
    bool answer = true;

    int p = 0, y = 0;

    for(auto c : s){
        if( c == 'P' || c == 'p')
            p++;
        
        if( c == 'Y' || c == 'y')
            y++;
    }

    // if (p == y || p+y == 0) answer = true;
    // else
    //     answer = false;

    // return answer;
    return p == y; // 이러면 같을때, 서로 0이어도 true 반환하네 ㅋㅋ
}

bool solution2(string s){
    bool answer = true;
    int p = 0, y = 0;

    // 뭐이리 복잡해??
    // https://stackoverflow.com/questions/5539249/why-cant-transforms-begin-s-end-s-begin-tolower-be-complied-successfu
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(cbegin(s), cend(s), begin(s), [](const unsigned char i) { return tolower(i); });

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    cout << solution(s) << '\n';

    return 0;
}
