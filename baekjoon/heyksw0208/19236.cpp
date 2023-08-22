// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001
typedef struct shark{
    int y, x, d;
    shark(int y, int x, int d): y(y), x(x), d(d) {}
}shark;

void init();
void input();
void solve();

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
vector<int> dir(17, 0);
vector<vector<int> > bd(4, vector<int>(4, 0));
shark s;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a, b;
            cin >> a >> b; // 번호, 방향
            bd[i][j] = a;
            dir[a] = b;
        }
    }
}

void solve()
{
    s = shark(0, 0, dir[bd[i][j]]);
    bd[i][j] = -1;
}

void move(int num){
    int d = dir[num];
    for(int i=0; i<8; i++){
        int nextdir = (d + i) % 8;
        // 갈 수 있으면
        if(){
            
        }
    }
}


int main()
{
    init();
    input();
    solve();
    return 0;
}