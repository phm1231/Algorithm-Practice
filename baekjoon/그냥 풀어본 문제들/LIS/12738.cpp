// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    vector<int> answer;
    vector<int> lis;
    lis.push_back(v[0]);

    for(int i=1; i<n; i++){
        if(lis.back() < v[i]){
            lis.push_back(v[i]);
        }
        else{
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }
    cout << lis.size();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}