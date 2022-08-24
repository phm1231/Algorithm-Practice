#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int cnt;
vector<string> vec;
map<int, int> mm;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        mm.insert(make_pair(k, 0));
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        mm[k]++;
    }
    for (auto iter = mm.begin(); iter != mm.end(); iter++)
    {
        if (iter->first == 0)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}