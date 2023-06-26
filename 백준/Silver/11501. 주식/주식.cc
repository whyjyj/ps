#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    ll ans = 0;

    cin >> t;

    while (t--)
    {
        cin >> n;
        memset(arr, 0, sizeof(arr));
        ans = 0;
        int max = 0;
        // 뒤에서 부터 순회, max값 업데이트
        // case 1) max값보다 작으면 max값 - 현재값 profit에 더하기(주가 올랐으니까 사야하는 경우)
        // case 2) max값보다 크면 max값 업데이트(주가 내렸으니까 사면 안 되는 경우)
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] < max)
                ans += (max - arr[i]);
            else
                max = arr[i];
        }

        cout << ans << '\n';
    }
}