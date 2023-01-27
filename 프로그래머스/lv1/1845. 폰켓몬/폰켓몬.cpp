#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    int answer = 0;
    int origin_n = nums.size();
    
    for(int num:nums) s.insert(num);
    int real_n = s.size();
    
    if(origin_n / 2 > real_n) answer = real_n;
    else answer = origin_n / 2;
    
    
    return answer;
}