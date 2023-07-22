// based problem:
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m, answer;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
vector<string> bd;
vector<vector<bool> > visited;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    visited.resize(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        bd.push_back(str);
    }
}

void solve()
{
    queue<pair<set<char>&, pair<int, int> > > q;
    set<char> s;

    int sy = 0;
    int sx = 0;
    s.insert(bd[sy][sx]);
    visited[sy][sx] = 0;
    answer = 1;

    q.push(make_pair(s, make_pair(y, x)));
    while(!q.empty()){
        set<char> alpha = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
    }
}




int main()
{
    init();
    input();
    solve();
    return 0;
}