
// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{

}

void solve()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(3, 2));
    v.push_back(make_pair(7, 2));
    v.push_back(make_pair(6, 2));
    v.push_back(make_pair(9, 2));
    v.push_back(make_pair(1, 2));

    cout << "\n";
    for(pair<int, int> p: v){
        cout << p.first << ' ';
    }
    sort(v.begin(), v.end());
        cout << "\n";
    for(pair<int, int> p: v){
        cout << p.first << ' ';
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}