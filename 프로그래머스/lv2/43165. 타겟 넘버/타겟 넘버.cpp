#include <bits/stdc++.h>
using namespace std;

int answer;

void DFS(int cur, int sum, int target, vector<int> &numbers) {
    int len = numbers.size();
    if(cur == len) {
        if(sum == target) answer+=1;
        return; // end condition
    }
    
    for(int i: {1, -1}) {
        DFS(cur + 1, sum + numbers[cur] * i, target, numbers);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, target, numbers);
    
    return answer;
}