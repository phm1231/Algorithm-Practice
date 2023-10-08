#include <iostream>
#include <vector>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();

int n, m;
const int MAX = 1e9;

vector<vector<int> > bd;
vector<vector<int> > sums;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;
    bd.resize(n+1, vector<int>(n+1, 0));
    sums.resize(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> bd[i][j];
        }
    }
}

void Solve()
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sums[i][j] = sums[i][j-1] + sums[i-1][j] - sums[i-1][j-1] + bd[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << sums[y2][x2] - sums[y2][x1-1] - sums[y1-1][x2] + sums[y1-1][x1-1] << endl;
    }
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}