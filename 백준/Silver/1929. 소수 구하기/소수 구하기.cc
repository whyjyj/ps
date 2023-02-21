#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimes(int m, int n) {
    vector<int> primes;
    vector<bool> state(n+1, true);
    state[1] = false;
    
    for(int i=2;i*i<=n;i++) {
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i) {
            state[j] = false;
        }
    }
    
    for(int i=m;i<=n;i++) {
        if(state[i]) primes.push_back(i);
    }
    return primes;
}

bool isPrime(int n) {
    if(n==1) return 0;
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0) return 0;
    }
    return 1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    
    vector<int> ans = findPrimes(m,n);
    for(int p:ans) {
        cout << p << '\n';
    }

    return 0;
}
