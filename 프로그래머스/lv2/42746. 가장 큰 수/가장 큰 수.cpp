#include <bits/stdc++.h>
using namespace std;

/*
    내림차순 정렬하고 붙이면 되는데 정렬 기준 세우는 것이 관건
    맨 앞에 자리수 큰 순서대로, 길이가 더 길면 그 다음 숫자가 다음 기준 -> 사전 순?
    그럼 3, 30은 어떻게 정렬되지? std::sort 기준 3이 앞임. 그니까 3이 작은 거, 30이 큰 거
    330 vs 303 -> 330이 앞에 와야 한다(더 크다)
    + 가장 큰 수 구하고 문자열로 구하는 거니 0에 대한 처리가 필요하다
*/

bool comp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    
    vector<string> nums;
    string answer = "";
    
    for(int num: numbers) {
        string s = to_string(num);
        nums.push_back(s);
    }
    
    sort(nums.begin(), nums.end(), comp);
    
    for(string s: nums) {
        answer.append(s);
    }
    if(answer[0]=='0') return "0";
    
    return answer;
}