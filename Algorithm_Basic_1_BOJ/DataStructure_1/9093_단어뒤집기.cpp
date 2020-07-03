#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();   // 입력 버퍼 비우기.
    // cin은 줄바꿈문자를 변수에 담지 않음 -> 버퍼에는 남아있음
    // getline은 버퍼에 남은 '\n' 개행문자를 읽고 한 행이 끝난걸로 처리.
    // 결국 진짜 입력이 들어가기도 전에 아무것도 없는 한 행이 입력된 상태로 시작.
    // 출처 : https://namwhis.tistory.com/entry/cin%EA%B3%BC-getline%EC%9D%84-%EA%B0%99%EC%9D%B4-%EC%82%AC%EC%9A%A9%ED%95%A0%EB%95%8C-cinignore%EC%9D%B4-%ED%95%84%EC%9A%94%ED%95%9C-%EC%9D%B4%EC%9C%A0-%EA%B8%B0%EB%A1%9D
    while(t--){
        string str;
        getline(cin, str);
        
        str += '\n';    // getline으로 입력받은 개행문자는 배열에 저장될때 널문자로 대체되니까, 따로 개행문자를 넣어줘야함
        stack<char> s;
        for(char ch : str){
            // 띄어쓰기나 개행문자를 발견하면 스택에 push 하지 않고
            // 이전까지 스택에 쌓아뒀던 모든 문자를 출력
            // 출력하고 if에 걸렸던 띄어쓰기나 개행문자를 다시 출력해줘야 
            // 입력받았던 형식은 그대로고, 단어만 뒤집을수 있음.
            if(ch == ' ' || ch == '\n'){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
               cout << ch;
            }else
            {
                s.push(ch);
            }
            
        }
    }

    return 0;
}