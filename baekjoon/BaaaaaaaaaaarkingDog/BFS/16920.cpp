#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
bool Bfs(const int player);

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

const int MAX = 1e9;
int n, m, p;
vector<string> bd;
vector<int> s;
vector<int> answer;
vector<queue<pair<int, int> > > vq;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m >> p;
    s.resize(p+1, 0);
    vq.resize(p+1, queue<pair<int, int> >());
    answer.resize(p+1, 0);
    for(int i=1; i<=p; i++) cin >> s[i];
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        bd.push_back(str);
        for(int j=0; j<m; j++){
            if('1' <= str[j] && str[j] <= '9'){
                int castle = str[j] - '0';
                vq[castle].push({i, j});
            }
        }
    }
}

void Solve()
{
    while(1){
        bool is_end = true;
        for(int player=1; player<=p; player++){
            bool is_expand = Bfs(player);
            if(is_expand) is_end = false;
        }
        if(is_end) break;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if('1' <= bd[i][j] && bd[i][j] <= '9'){
                int castle = bd[i][j] - '0';
                answer[castle]++;
            }
        }
    }
    for(int i=1; i<=p; i++) cout << answer[i] << ' ';
}

bool Bfs(const int player){
    bool is_expand = false;
    queue<pair<int, pair<int, int> > > q;
    while(!vq[player].empty()){
        const pair<int, int> castle = vq[player].front();
        vq[player].pop();
        q.push({s[player], castle}); // castle로부터 s[player]번 확장될 수 있음.
    }
    while(!q.empty()){
        int dist = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        // 더 이상 확장될 수 없으면
        if(dist == 0){
            vq[player].push({y, x});
            continue;
        }
        // 확장 가능하면
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(bd[ny][nx] == '.'){
                    bd[ny][nx] = bd[y][x];
                    is_expand = true;
                    q.push({dist - 1, {ny, nx}});
                }
            }
        }
    }
    return is_expand;
}

int main()
{
    Init();
    Input();
    Solve();
    return 0;
}