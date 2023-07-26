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
    vector<int> nge(n, -1);

    for(int here=n-2; here>=0; here--){
        int next = here + 1;
        while(next != -1){
            if(v[here] < v[next]){
                nge[here] = next;
                break;
            }
            next = nge[next];
        }
    }

    for(int i=0; i<n; i++){
        if(nge[i] == -1) cout << -1 << ' ';
        else cout << v[nge[i]] << ' ';
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}