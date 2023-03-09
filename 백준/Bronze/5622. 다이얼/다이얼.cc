#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    int arr['Z' - 'A' + 2]; // 1 - idx
    int end_idx = 'Z' - 'A' + 1;
    int idx = 1;
    int ans = 0;

    arr[0] = 0;
    for (int i = 3; i <= 7; i++)
    {
        arr[idx++] = i;
        arr[idx++] = i; // idx+1
        arr[idx++] = i; // idx+2
    }

    for (int i = 0; i < 4; i++)
        arr[idx++] = 8;

    for (int i = 0; i < 3; i++)
        arr[idx++] = 9;

    for (int i = 0; i < 4; i++)
        arr[idx++] = 10;

    cin >> input;
    for (char c : input)
    {
        int index = c - 'A' + 1;
        ans += arr[index];
    }

    cout << ans;
}