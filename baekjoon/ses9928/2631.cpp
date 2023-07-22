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
vector<int> sequence;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    sequence.resize(n, 0);
    for(int i=0; i<n; i++){
        cin >> sequence[i];
    }
}

void solve()
{
    vector<int> lis;
    lis.push_back(sequence[0]);
    for(int i=1; i<n; i++){
        if(lis.back() < sequence[i]) lis.push_back(sequence[i]);
        else{
            int idx = lower_bound(lis.begin(), lis.end(), sequence[i]) - lis.begin();
            lis[idx] = sequence[i];
        }
    }
    cout << n - lis.size();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}