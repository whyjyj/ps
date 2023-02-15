#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, c;

ll multi(ll x, ll y, ll z) {
    if(y==1) return x % z;
    ll ans = multi(x, y/2, z);
    ans = ans * ans % z;
    if(y%2==0) return ans % z;
    return x * ans % z;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> c;
    cout << multi(a, b, c);
}