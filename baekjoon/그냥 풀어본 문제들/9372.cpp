#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();

const int MAX = 1e9;
int n, m;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
    }
}

void Solve()
{
    cout << n-1 << endl;
}


int main()
{
    Init();
    int t;
    cin >> t;
    while(t--){
        Input();
        Solve();
    }
    return 0;
}