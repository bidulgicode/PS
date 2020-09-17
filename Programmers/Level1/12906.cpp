/**
 * 같은 숫자는 싫어
 * https://programmers.co.kr/learn/courses/30/lessons/12906
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prevNum = 1e7;
    for(int item : arr){
        if(item == prevNum)
            continue;
        answer.push_back(item);
        prevNum = item;
    }

    return answer;
}

vector<int> solution2(vector<int> arr)
{
    // https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
    // 벡터 중복제거, set은 중복허용 안하니깐 여기다 다 때려넣고 다시 벡터에 넣는것도 있다.
    // 중복된 값이 set에 넣었다가 빼는게 더 빠르다고함.
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer = arr;
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr{1, 1, 3, 3, 0, 1, 1};

    for(int item : solution(arr)){
        cout << item << '\n';
    }


    return 0;
}
