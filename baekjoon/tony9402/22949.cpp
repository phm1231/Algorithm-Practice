// based problem:
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
vector<vector<char> > spin(const vector<vector<char> >& origin);

int n, k;
vector<vector<char> > bd;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> k;
    n = 4*k;
    bd.resize(n, vector<char>(n, ' '));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> bd[i][j];
        }
    }
}

void solve()
{
    queue<pair<int, int> > peopleQ;
    queue<pair<int, int> > spinQ; // 구역 first가 second번 돌았음.
    
}

void paste(int y, int x, const vector<vector<char> >& origin){

}

// origin을 90도 회전시킴
vector<vector<char> > spin(const vector<vector<char> >& origin){
    int N = 2*k;
    vector<vector<char> > ret = origin;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ret[j][N-i-1] = origin[i][j]; // 시계방향 회전
            // ret[i][j] = origin[j][N-i-1] 반시계방향 회전
        }
    }
    return ret;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}