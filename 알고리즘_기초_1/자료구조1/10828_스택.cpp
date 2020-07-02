#include <bits/stdc++.h>
using namespace std;
/*
?��?���? ????��?��?�� ?��?��?�� 구현?�� ?��?��, ?��?��?���? 주어�??�� 명령?�� 처리?��?�� ?��로그?��?�� ?��?��?��?��?��.

명령??? �? ?��?�� �?�??��?��.

push X: ?��?�� X�? ?��?��?�� ?��?�� ?��?��?��?��.
pop: ?��?��?��?�� �??�� ?��?�� ?��?�� ?��?���? 빼고, �? ?���? 출력?��?��. 만약 ?��?��?�� ?��?��?��?�� ?��?���? ?��?�� 경우?��?�� -1?�� 출력?��?��.
size: ?��?��?�� ?��?��?��?�� ?��?��?�� 개수�? 출력?��?��.
empty: ?��?��?�� 비어?��?���? 1, ?��?���? 0?�� 출력?��?��.
top: ?��?��?�� �??�� ?��?�� ?��?�� ?��?���? 출력?��?��. 만약 ?��?��?�� ?��?��?��?�� ?��?���? ?��?�� 경우?��?�� -1?�� 출력?��?��.
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
            // ?��기왔?��?�� data[size]?�� 빈공간이?�� 미리 ?��?��즈�?? 빼줘?��
            // 최상?��?�� ?��?�� ?��?���? 반환?�� ?�� ?��?��.
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