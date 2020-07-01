#include <bits/stdc++.h>
using namespace std;
/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

struct Stack
{
    int data[10000];
    int size;
    Stack()
    {
        size = 0;
    }
    void push(int x)
    {
        data[size] = x;
        size += 1;
    }
    int pop()
    {
        if(empty()){
            return -1;
        }else{
            // 여기왔을때 data[size]는 빈공간이니 미리 사이즈를 빼줘야
            // 최상위에 있는 숫자를 반환할 수 있다.
            size -= 1;
            return data[size];
        }
    }
    int top()
    {
        if(empty()){
            return -1;
        }else{
            return data[size - 1];
        }
    }
    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Stack s;

    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            s.push(num);
        }else if (cmd == "pop"){
            cout << (s.empty() ? -1 : s.top()) << '\n';
            if(!s.empty())
                s.pop();
        }else if (cmd == "size"){
            cout << s.size << '\n';
        }else if (cmd == "empty"){
            cout << s.empty() << '\n';
        }else if (cmd == "top"){
            cout << (s.empty() ? -1 : s.top()) << '\n';
        }
    }

    return 0;
}