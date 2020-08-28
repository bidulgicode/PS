/**
 * 완주하지 못한 선수
 * https://programmers.co.kr/learn/courses/30/lessons/42576
 * 두 배열의 비교 문제인데
 * 정렬 후 비교하든지, 해시맵 사용해서 푼다
 */

#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 정렬 후 비교 O(nlogn)

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int size = participant.size();
    for (int i = 0; i <= size; i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    // return participant[participant.size() - 1]; 이거인 이유는 
    // 완주자의 수가 참가자보다 1작으니까 정렬을 한뒤 마지막 참가자인 이름이 완주를 못할경우에 마지막 참가자를 보내줘야하기 떄문이예요
    return participant[participant.size() - 1];
}

// https://modoocode.com/224
// unordered_set, unordered_map 같은 애들은 해시함수를 쓰는데
// hashset, hashmap 과 같은 뜻임.. 이름 충돌때문에 저런 이름으로 정했다고
// 해시 함수 : 임의 크기의 데이터를 고정된 크기의 데이터로 대응시켜주는 함수
string solution2(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> names; // 중복된 원소 허락

    for (int i = 0; i < participant.size(); i++){
        names.insert(participant[i]); // 삽입할때 해시함수를 통해 어디에 저장할지 결정함.
    }

    for (int i = 0; i < completion.size(); i++){
        // find 하려는 값을 해시함수에 넣으면 값이 있는 멀티셋 내부의 위치가 나오니깐
        // O(n)밖에 안걸림
        unordered_multiset<string>::iterator iter = names.find(completion[i]);
        names.erase(iter);
    }

    return *names.begin();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}
