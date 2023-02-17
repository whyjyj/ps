#include <bits/stdc++.h>
using namespace std;

// n개를 from에서 to로 옮기는 방법
void hanoi(int n, int from, int to) {
    // base case
    if(n==1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    // n-1개를 from번에서 from, to 아닌 곳으로
    hanoi(n-1, from, 6-from-to);
    // 1번에 있는 n을 3번으로
    cout << from << ' ' << to << '\n';
    // 2번에 있는 n-1개를 3번으로
    hanoi(n-1, 6-from-to, to);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    // k개 옮길 때 A번 -> k+1개 옮길 때 2A + 1번
    // 1, 3, 7, 15 -> 2^k - 1 
    cout << (int)pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3);
    
}