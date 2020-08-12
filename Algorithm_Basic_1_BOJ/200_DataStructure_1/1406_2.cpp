/*
에디터 with LinkedList
https://www.acmicpc.net/problem/1406
*/
#include <list>
#include <iostream>
#include <string.h>
using namespace std;
char a[600000];
int len;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    len = strlen(a);
    list<char> charList;
    for (int i = 0; i < len; i++)
        charList.push_back(a[i]); // 리스트의 back에 넣어서 마지막글자가 리스트의 마지막 위치에 있어야함.

    auto cursor = charList.end();   // iterator 반환

    int orderNum;
    cin >> orderNum;
    while(orderNum--){
        char order;
        cin >> order;
        if(order == 'L'){
            if(cursor != charList.begin())
                cursor--;
        }else if(order == 'D'){
            if(cursor != charList.end())
                cursor++;
        }else if(order == 'B'){
            if(cursor != charList.begin()){
                cursor--;
                cursor = charList.erase(cursor);
            }
        }else if(order == 'P'){
            char ins;
            cin >> ins;
            charList.insert(cursor, ins); // 넣으려는 위치포함 죄다 오른쪽으로 밀림 12345 (3위치에777넣음) 12777345
        }
    }

    for(char item : charList)
        cout << item;
    return 0;
}