#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i: scoville) {
        pq.push(i);
    }
    
    
    while(true) {
        int top = pq.top(); pq.pop();
        if(top < K) {
            if(pq.empty()) return -1;
            int second_top = pq.top(); pq.pop();
            int mix = top + (second_top * 2);
            if(top == 0 && second_top == 0 && K!=0) return -1;
            pq.push(mix);
            answer++;
        }
        else {
            break;
        }
    }
    return answer;
}