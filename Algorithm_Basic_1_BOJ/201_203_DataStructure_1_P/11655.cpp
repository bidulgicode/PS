/**
 * BOJ_11655_ROT13
 * https://www.acmicpc.net/problem/11655
 */
#include <iostream>
#include <string>
using namespace std;

string rot13(string s){
    // 알파벳 13번째인 m을 기준으로 m보다 크면 -13한다.
    // n이 14번째 문자고 이걸 rot13하면 1번째 문자 a인데
    // 14-13=1 이다.
    for (int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'm'){
            s[i] = s[i] + 13;
        } else if (s[i] >= 'n' && s[i] <= 'z'){
            s[i] = s[i] - 13;
        } else if (s[i] >= 'A' && s[i] <= 'M'){
            s[i] = s[i] + 13;
        } else if (s[i] >= 'N' && s[i] <= 'Z'){
            s[i] = s[i] - 13;
        }
        
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    cout << rot13(s) << '\n';

    return 0;
}
