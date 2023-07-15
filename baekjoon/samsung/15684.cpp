// based problem:
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void go(int idx, int height, int start);
void dfs(int bridge, int depth, int maxDepth);

int n, m, h;
vector<vector<pair<int, int> > > ladder; // ladder[0] = 0번 점선에서 연결된 (b, b+1) 가로줄이 존재한다.
bool isLadder[31][11][11]; // isLadder[i][j][k] = 가로선 i가 세로선 j, k를 잇고 있으면 true
bool isSuccess;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    memset(isLadder, false, sizeof(isLadder));
}

void input()
{
    cin >> n >> m >> h;
    ladder.resize(h+1, vector<pair<int, int> >());
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b; // b번 세로선과 b+1번 세로선을 a번 가로선(점선) 위치에서 연결
        ladder[a].push_back({b, b+1});
        isLadder[a][b][b+1] = true;
    }
}

// 두 가로선이 연속하거나 서로 접하면 안된다.
void solve()
{
    for(int answer=0; answer<4; answer++){
        isSuccess = false;
        dfs(1, 0, answer);
        if(isSuccess){
            cout << answer;
            return;
        }
    }
    cout << -1;
    return;
}

// maxDepth만큼 사다리를 연결함.
void dfs(int bridge, int depth, int maxDepth){
    // 사다리 연결이 종료됨.
    if(depth == maxDepth){
        isSuccess = true;
        // 검사
        for(int i=1; i<=n; i++){
            if(isSuccess) go(i, 1, i);
            else break;
        }
        return;
    }

    if(isSuccess) return;

    // 가로선을 놓을 수 있는 위치
    for(int i=bridge; i<=h; i++){
        // 이을 세로선
        for(int j=1; j<n; j++){
            // 이미 추가하려고 하는 위치에 가로선이 존재한다.
            if(isLadder[i][j][j+1]) continue;

            // 이전에 가로선이 연속해서 존재한다.
            if(isLadder[i][j-1][j]) continue;

            // 이후에 가로선이 연속해서 존재한다.
            if(j < n-1 && isLadder[i][j+1][j+2]) continue;

            // 가로선을 추가한다
            isLadder[i][j][j+1] = true;
            ladder[i].push_back({j, j+1});
            dfs(i, depth + 1, maxDepth);
            if(isSuccess) return;

            ladder[i].pop_back();
            isLadder[i][j][j+1] = false;
        }
    }
}

// 현재 idx번 세로줄을 타고 가로줄이 height임 있음.
void go(int idx, int height, int start){
    // 다 내려옴
    if(height == h + 1){
        if(idx != start) isSuccess = false;
        return;
    }
    // height 높이에 연결된 다리를 순회하면서
    for(pair<int, int>& p : ladder[height]){
        int src = p.first;
        int dst = p.second;
        // idx와는 연관이 없는 다리인 경우
        if(src != idx && dst != idx) continue;
        // src -> dst로 이동하는 경우
        if(src == idx){
            go(dst, height + 1, start);
            return;
        }
        // dst -> src로 이동하는 경우
        else if(dst == idx){
            go(src, height + 1, start);
            return;
        }
    }
    // 사다리를 건너지 않음.
    go(idx, height + 1, start);
    return;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}