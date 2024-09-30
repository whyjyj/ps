#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> vec(500001);

int upper_bound(const vector<int> &arr, int target, int lo, int hi)
{
    int mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (target >= arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

int lower_bound(const vector<int> &arr, int target, int lo, int hi)
{
    int mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (target <= arr[mid])
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tar;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.begin() + n);

    cin >> m;
    for (size_t i = 0; i < m; i++)
    {
        cin >> tar;
        cout << upper_bound(vec, tar, 0, n) - lower_bound(vec, tar, 0, n) << ' ';
    }
}