#include <bits/stdc++.h>
using namespace std;

/**
    completion 앞에서부터 하나하나 순회하면서 participant에서 찾아서 제거해야 한다
    completion 순회하는 건 O(n)이니까 그대로 두고 participant만 hash로 옮기고 하면 총 O(n)
    그러면 마지막에 남은 participant는 iterator로 가져와야 하나
**/

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_multiset<string> ms;
    
    for(string parti: participant) {
        ms.insert(parti);
    }
    
    
    for(string comple: completion) {
        ms.erase(ms.find(comple));
    }
    
    string answer = "";
    for(auto ans: ms) answer = ans;
    return answer;
}