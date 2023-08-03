// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<int> v;
vector<pair<int, int> > pv;
vector<int> from; // from[i] =
vector<int> to; // to[i] = 
 
void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{   
    cin >> n >> m;
    v.resize(n, 0);
    from.resize(n, -1);
    to.resize(n, -1);
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        pv.push_back(make_pair(a, b));
    }
}

void solve()
{
    vector<pair<int, int> > answer(m);
    for(pair<int, int> p: pv){
        int a = p.first - 1;
        int b = p.second;

        int minNumber = 1000000001;
        int maxNumber = 0;
        for(int i=a; i<b; i++){
            minNumber = min(minNumber, v[i]);
            maxNumber = max(maxNumber, v[i]);
        }
        cout << minNumber << ' ' << maxNumber << "\n";
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}