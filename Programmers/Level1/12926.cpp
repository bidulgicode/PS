/**
 * 시저 암호
 * https://programmers.co.kr/learn/courses/30/lessons/12926
 */

#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(auto item : s){
        char r;
        if(islower(item)){
            r = !islower(item + (n % 26)) ? item + (n % 26) - 26 : item + (n % 26);
        }
        else if(isupper(item)){
            r = !isupper(item + (n % 26)) ? item + (n % 26) - 26 : item + (n % 26);
        }
        else {
            r = ' ';
        }
        answer.push_back(r);
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}
