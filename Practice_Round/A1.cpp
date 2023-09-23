#include <iostream>
#include <vector>

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
    int s,d,k;
    cin>>s>>d>>k;
    
    int Cheese_Patty =  s + 2*d;

    int Buns = 2*(s+d);

    int Cheese_Patty_Needed = k;
    int Buns_Needed = k+1;
   // cout << Cheese_Patty << Buns << Cheese_Patty_Needed << Buns_Needed;
     if (Cheese_Patty >= Cheese_Patty_Needed && Buns >= Buns_Needed) cout
         << "Case #" << test << ": YES" << endl;
    else
          cout << "Case #" << test << ": NO" << endl;

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
