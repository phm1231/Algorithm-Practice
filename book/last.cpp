#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX 1001

using namespace std;

int n, m;
int board[MAX][MAX];
int dx[] = {-1, -1, 0};
int dy[] = {-1, 0, -1};

void init();
void input();
void solve();

void init(){
    memset(board, 0, sizeof(board));
}

void input(){
    scanf("%d %d", &n, &m);
    getchar();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char ch;
            scanf("%c", &ch);
            board[i][j] = ch - '0';
        }
        getchar();
    }
}

void solve(){
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            int min_v = INT_MAX;
            for(int i=0; i<3; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                min_v = min(min_v, board[ny][nx]);
            }
            if(board[y][x] != 0){
                board[y][x] = min_v + 1;
            }
        }
    }
    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ans = max(ans, board[i][j]);
        }
    }
    printf("%d\n", ans * ans);
}

int main(){
    init();
    input();
    solve();
    return 0;
}