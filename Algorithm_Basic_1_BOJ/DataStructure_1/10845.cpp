/*
BOJ_10845_큐
https://www.acmicpc.net/problem/10845
*/

#include <iostream>
//FIFO
struct MyQueue{
    int data[10000];
    int begin, end;
    MyQueue(){
        begin = 0;
        end = 0;
    }
    void push(int num){
        data[end] = num;
        end += 1;
    }
};

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    MyQueue q;

    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int n;
            cin >> n;
        } else if(cmd == "pop"){
            // 맨앞의수를 보여주고, 뺀다
        } else if(cmd == "size"){

        } else if(cmd == "empty"){

        } else if(cmd == "front"){
            // 없으면 -1 출력
        } else if(cmd == "back"){
            // 없으면 -1
        }
    }

    return 0;
}
