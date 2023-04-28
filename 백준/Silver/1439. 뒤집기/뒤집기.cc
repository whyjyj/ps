#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int diff_pattern0 = 0; // 00, , 0
    int diff_pattern1 = 0; // 1111, , 1
    string s;
    char cur = s[0];

    getline(cin, s);

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == cur)
            continue;
        else // s[i] != cur
        {
            if (s[i] == '0')
            {
                diff_pattern1++;
            }
            else
            {
                diff_pattern0++;
            }
            cur = s[i];
        }
    }

    cout << min(diff_pattern0, diff_pattern1);
}