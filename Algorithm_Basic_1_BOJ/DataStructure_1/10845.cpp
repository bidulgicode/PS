/*
BOJ_10845_큐
https://www.acmicpc.net/problem/10845
*/

#include <iostream>
using namespace std;

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
    void pop(){
        if(empty() == 1){
            cout << -1 << '\n';              
        }else{
            cout << data[begin] << '\n';
            begin += 1;
        }
    }
    int size(){
        return end - begin;
    }
    int empty(){
        if(size() == 0)
            return 1;
        else
            return 0;        
    }
    void front(){
        if(empty() == 1){
            cout << -1 << '\n';
        }
        else{
            cout << data[begin] << '\n';
        }
    }
    void back(){
        if(empty() == 1){
            cout << -1 << '\n';               
        }
        else{
            cout << data[end-1] << '\n';
        }
    }
};

int main()
{
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
            q.push(n);
        } else if(cmd == "pop"){
            // 맨앞의수를 보여주고, 뺀다
            q.pop();
        } else if(cmd == "size"){
            cout << q.size() << '\n';
        } else if(cmd == "empty"){
            cout << q.empty() << '\n';
        } else if(cmd == "front"){
            q.front();
            // 없으면 -1 출력
        } else if(cmd == "back"){
            q.back();
            // 없으면 -1
        }        
    }

    return 0;
}
