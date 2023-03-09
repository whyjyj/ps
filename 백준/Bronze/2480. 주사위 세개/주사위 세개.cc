#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int samecount = 0, price = 0, samenum = 0;
    cin >> a >> b >> c;

    // case 5
    if (a == b && a == c) // a == b == c
    {
        samecount = 3;
        samenum = a;
    }

    else if (a == b && a != c) // a == b != c
    {
        samecount = 2;
        samenum = a;
    }

    else if (a != b && a == c) // a == c != b
    {
        samecount = 2;
        samenum = a;
    }
    else if (a != b && a != c)
    {
        if (b == c)
        {
            samecount = 2;
            samenum = b;
        }
        else
            samecount = 0;
    }

    if (samecount == 3)
    {
        price = 10000 + samenum * 1000;
    }
    else if (samecount == 2)
        price = 1000 + samenum * 100;
    else
    {
        int maxnum = max(a, b);
        maxnum = max(maxnum, c);
        price = maxnum * 100;
    }

    cout << price;
}