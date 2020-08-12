/*
BOJ_1158_요세푸스 문제
https://www.acmicpc.net/problem/1158
*/

#include <iostream>
#include <queue>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    queue<int> q;
    
    for(int i = 1; i <= n; i++)
        q.push(i);
    
    cout << "<";

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front() << ">";

    return 0;
}
