#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pb push_back
using namespace std;
// 01010001
// 01110011
//
// 02120012

void solve(int test)
{
    int n;
    cin >> n;
    vector<int> a(2 * n - 1, 0);

    for (int i = 0; i < 2 * n - 1; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> save;

    int l = 0, r = 2 * n - 2;
    int sum = a[l] + a[r];
    while (l < r)
    {
        if (sum == a[l] + a[r])
        {
            l++;
            r--;
        }
        else if (sum > a[l] + a[r])
        {
            save.push_back(a[l]);
            l++;
        }
        else
        {
            save.push_back(a[r]);
            r--;
        }
    }
    if (save.size() >= 2)
    {
        save.clear();

        l = 1, r = 2 * n - 2;
        sum = a[l] + a[r];
        while (l < r)
        {
            if (sum == a[l] + a[r])
            {
                l++;
                r--;
            }
            else if (sum > a[l] + a[r])
            {
                save.push_back(a[l]);
                l++;
            }
            else
            {
                save.push_back(a[r]);
                r--;
            }
        }

        if (save.size() == 0)
        {
            cout << "Case #" << test << ": " << sum - a[0] << endl;
        }
        else
        {
            cout << "Case #" << test << ": " << -1 << endl;
        }
        return;
    }

    if (save.size() == 0)
    {
        cout << "Case #" << test << ": " << sum - a[l] << endl;
        return;
    }

    cout << "Case #" << test << ": " << sum - save[0] << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    cin >> t;

    for (int test = 1; test <= t; test++)
        solve(test);

    return 0;
}
