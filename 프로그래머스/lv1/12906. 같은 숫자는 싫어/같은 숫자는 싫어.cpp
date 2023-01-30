#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    
    s.push(-1);
    
    int len = arr.size();
    if(len==1) return arr;
    
    for(int i=0;i<len;i++) {
        int top = s.top();
        if(top != arr[i]) {
            answer.push_back(arr[i]);
        }
        s.push(arr[i]);
    }
    return answer;
}