/*
에디터
https://www.acmicpc.net/problem/1406
*/

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;


char a[600000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    stack<char> left, right;
    int n = strlen(a);
    for (int i = 0; i < n; i++){
        left.push(a[i]);
    }
    int ordernum; // 명령어 개수
    cin >> ordernum;
    while(ordernum--){
        char order;
        cin >> order;
        if(order == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }else if(order == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }else if(order == 'B'){
            if(!left.empty()){
                left.pop();
            }
        }else if(order == 'P'){
            char ins;
            cin >> ins;
            left.push(ins);
        }
    }

    // 오른쪽에 다 몰아넣고 다시 뿌리자
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    cout << '\n';
    return 0;
}