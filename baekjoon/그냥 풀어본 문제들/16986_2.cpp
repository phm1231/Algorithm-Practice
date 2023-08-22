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
void dfs(vector<bool>& visited, int round_2, int round_3, int p1, int p2, int win_1, int win_2, int win_3);

int n, k; // n개의 손동작, k번 우승
int g[11][11]; // 상성 정리
vector<int> v2(20); // 경희
vector<int> v3(20); // 민호
bool canWin = false; // 이길 수 있는지.

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    memset(g, 0, sizeof(g));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> g[i][j];
        }
    }

    for(int i=0; i<20; i++) cin >> v2[i]; // 경희
    for(int i=0; i<20; i++) cin >> v3[i]; // 민호
}

void solve()
{
    vector<bool> visited(n+1, false);
    dfs(visited, 0, 0, 1, 2, 0, 0, 0); // 처음에는 무조건 1이랑 2랑 싸운다.
    cout << canWin;
}

// 이제 round이고, p1이랑 p2랑 싸울거야.
// 여태까지 각자 win_1, win_2, win_3번 승리했어.
void dfs(vector<bool>& visited, int round_2, int round_3, int p1, int p2, int win_1, int win_2, int win_3){
    // 이미 이길 수 있다면
    if(canWin) return;

    // 누군가가 이미 k번 승리했다면
    if(win_1 == k || win_2 == k || win_3 == k){
        if(win_1 == k) canWin = true;

        return;
    }

    // 지우가 참여하는 경기
    if(p1 == 1 || p2 == 1){
        // 1과 2의 싸움
        if(p1 == 2 || p2 == 2){
            if(round_2 >= 20) return;

            for(int i=1; i<=n; i++){
                // i번 손동작을 낸 적이 없으면
                if(!visited[i]){
                    // i를 낸다.
                    visited[i] = true;

                    // 1이 2에게 이김
                    if(g[i][v2[round_2]] == 2) dfs(visited, round_2 + 1, round_3, 1, 3, win_1 + 1, win_2, win_3);
                    // 2가 이김
                    else dfs(visited, round_2 + 1, round_3, 2, 3, win_1, win_2 + 1, win_3);

                    visited[i] = false;
                }
            }
        }
        // 1과 3의 싸움
        else if(p1 == 3 || p2 == 3){
            if(round_3 >= 20) return;

            for(int i=1; i<=n; i++){
                if(!visited[i]){
                    visited[i] = true;

                    // 1이 3에게 이김
                    if(g[i][v3[round_3]] == 2) dfs(visited, round_2, round_3 + 1, 1, 2, win_1 + 1, win_2, win_3);
                    // 1이 3에게 짐
                    else dfs(visited, round_2, round_3 + 1, 3, 2, win_1, win_2, win_3 + 1);

                    visited[i] = false;
                }
            }
        }
    }

    // 지우가 참여하지 않는 경기
    else{
        if(round_2 >= 20 || round_3 >= 20) return;
        // 2가 3에게 이김
        if(g[v2[round_2]][v3[round_3]] == 2) dfs(visited, round_2 + 1, round_3 + 1, 2, 1, win_1, win_2 + 1, win_3); 
        // 3이 2에게 이김
        else dfs(visited, round_2 + 1, round_3 + 1, 3, 1, win_1, win_2, win_3 + 1);
    }

}

int main()
{
    init();
    input();
    solve();
    return 0;
}