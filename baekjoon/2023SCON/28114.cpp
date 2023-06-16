// based problem:
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

void init();
void input();
void solve();

map<int, string> pf;
vector<int> years;
void init()
{
    FAST
}

void input()
{
    for(int i=0; i<3; i++){
        int p, y;
        string s;
        cin >> p >> y >> s;
        pf.insert(make_pair(p, s));
        years.push_back(y);
    }
}

void solve()
{
    vector<int> ys;
    for(int year: years){
        ys.push_back(year % 100);
    }
    sort(ys.begin(), ys.end());

    string s1 = "";
    for(int y: ys){
        s1 += to_string(y);
    }

    string s2 = "";
    for(auto iter = pf.begin(); iter != pf.end(); iter++){
        s2 += iter->second[0];
    }
    reverse(s2.begin(), s2.end());

    cout << s1 << endl;
    cout << s2 << endl;

}

int main()
{
    init();
    input();
    solve();
    return 0;
}