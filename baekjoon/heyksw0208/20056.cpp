// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

typedef struct fireball{
    int m, s, d;
    fireball(int m, int s, int d): m(m), s(s), d(d) {}
}fireball;

void init();
void input();
void solve();

int n, fbcnt, k;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<vector<fireball> > > bd;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> fbcnt >> k;
    bd.resize(n, vector<vector<fireball> >(n, vector<fireball>()));

    for(int i=0; i<fbcnt; i++){
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        if(m == 0) continue;
        bd[r-1][c-1].push_back(fireball(m, s, d));
    }
}

void solve()
{
    for(int i=0; i<k; i++){
        vector<vector<vector<fireball> > > newbd(n, vector<vector<fireball> >(n, vector<fireball>()));
        // move
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                for(fireball fb: bd[y][x]){
                    int ny = (y + (dy[fb.d] * (fb.s % n)));
                    if(ny < 0) ny = n + ny;
                    if(ny >= n) ny %= n;

                    int nx = (x + (dx[fb.d] * (fb.s % n)));
                    if(nx < 0) nx = n + nx;
                    if(nx >= n) nx %= n;

                    newbd[ny][nx].push_back(fb);
                }
            }
        }
        // 합체
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                if(newbd[y][x].size() > 1){
                    int nm, nd, ns;
                    nm = nd = ns = 0;

                    bool isOdd = true;
                    bool isEven = true;

                    for(int j=0; j<newbd[y][x].size(); j++){
                        fireball fb = newbd[y][x][j];
                        nm += fb.m;
                        ns += fb.s;
                        
                        if(fb.d % 2 == 0) isOdd = false;
                        else if(fb.d % 2 == 1) isEven = false;
                    }

                    ns /= newbd[y][x].size();
                    nm /= 5;

                    while(newbd[y][x].size() > 0) newbd[y][x].pop_back();
                    // newbd[y][x].clear();
                    if(nm == 0) continue;

                    // 모두 홀수이거나 짝수이면, 방향은 0, 2, 4, 6
                    if(isOdd || isEven){
                        int dist[] = {0, 2, 4, 6};
                        for(int j=0; j<4; j++){
                            newbd[y][x].push_back(fireball(nm, ns, dist[j]));
                        }
                    }
                    // 그렇지 않으면 1 3 5 7 
                    else{
                        int dist[] = {1, 3, 5, 7};
                        for(int j=0; j<4; j++){
                            newbd[y][x].push_back(fireball(nm, ns, dist[j]));
                        }
                    }
                }

            }
        }
        bd = newbd;
    }

    int answer = 0;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            for(fireball fb: bd[y][x]){
                answer += fb.m;
            }
        }
    }
    cout << answer;
}



int main()
{
    init();
    input();
    solve();
    return 0;
}