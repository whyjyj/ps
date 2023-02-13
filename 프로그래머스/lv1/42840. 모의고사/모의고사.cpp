#include <bits/stdc++.h>
using namespace std;

int first[5] = {1,2,3,4,5};
int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> scores = {0,0,0};
    vector<int> answer;
    int n = answers.size();
    for(int i=0;i<n;i++) {
        if(first[i%5] == answers[i]) scores[0]++;
        if(second[i%8] == answers[i]) scores[1]++;
        if(third[i%10] == answers[i]) scores[2]++;
    }
    
    int _max = *max_element(scores.begin(), scores.end());
    
    for(int i=0;i<3;i++) {
        if(scores[i]==_max) answer.push_back(i+1);
    }
    
    return answer;
}