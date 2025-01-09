#include <bits/stdc++.h>
using namespace std;

int bs(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
        {
            return m;
        }

        if (arr[m] < x)
        {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int num = 1;

    while (true)
    {
        int arr[x];

        if (x == 0 && y == 0)
        {
            break;
        }

        for (int i = 0; i < x; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+x);
        
        printf("CASE# %d:\n", num);

        while (y--)
        {
            int q;
            cin >> q;
            int spot = bs(arr, 0, x-1, q);

            if (spot != -1)
            {
                if (arr[spot-1] == arr[spot])
                {
                    while (arr[spot-1] == arr[spot])
                    {
                        spot--;
                    }
                    printf("%d found at %d\n", q, spot+1);
                } else {
                    printf("%d found at %d\n", q, spot+1);
                }
            } else {
                printf("%d not found\n", q);
            }
        }

        num++;

        cin >> x >> y;
    }
}

int main()
{
   solve();

   return 0;
}