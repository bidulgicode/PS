/** 
 * 스킬 트리
 * https://programmers.co.kr/learn/courses/30/lessons/49993?language=cpp
 */
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees){
    int answer = 0;
    map<char, int> tree;
    // 맵에 스킬순서를 저장
    // 체크할 스킬이 아닌 경우 0번
    for (int i = 0; i < skill.length(); i++){
        tree[skill[i]] = i + 1;
    }
    // 스킬트리 순회하면서 체크
    for(auto skt : skill_trees){
        int curCount = 1; // 현재 순서에 맞는 단어의 카운트
        bool check = true; // 이 스킬트리가 맞는가?
        // 스킬트리 유효성 확인
        for (int i = 0; i < skt.length(); i++){
            if(tree[skt[i]]> curCount){
                check = false;
                break;
            }
            // 해당하는 스킬트리가 존재한다면 다음 스킬트리를 찾기 위해 카운트 증가
            else if(tree[skt[i]] == curCount)
                curCount++;
        }
        // 여기서 check가 ture이면 모든 확인을 통과했으니
        // skt는 유효한것이다.
        if(check)
            answer++;
    }

    return answer;
}

int main (){
    string skill = "CBD";
    vector<string> skill_trees {"BACDE", "CBADF", "AECB", "BDA"};

    // cout << solution(skill, skill_trees);

    // map<string, int> tree;
    // tree["cd"] = 2;
    // cout << tree["ab"];
    // cout << tree["cd"];
    // cout << tree["ef"];
// []로 접근했을때 있으면 있던거 꺼내고 아니면 0뱉네

    return 0;
}