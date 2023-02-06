#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for(string operation: operations) {
        stringstream ss(operation);
        vector<string> splitted;
        
        string word;
        while(getline(ss, word, ' ')) {
            splitted.push_back(word);
        } // [0] -> operator, [1] -> operand
        if(splitted[0] == "I") ms.insert(stoi(splitted[1]));
        else if(splitted[0] == "D" && splitted[1] == "1" && !ms.empty()) ms.erase(--ms.end());
        else if(splitted[0] == "D" && splitted[1] == "-1" && !ms.empty()) ms.erase(ms.begin());
    }
    
    vector<int> answer;
    if(ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}