#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define ll long long
// #define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();
void Scan();
void Go();
void Open();

const int MAX = 1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
vector<bool> has_key;
queue<pair<int, int> > lockQ;
queue<pair<int, int> > q;
vector<vector<bool> > visited;
vector<string> bd;
int n, m, answer;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;

    answer = 0;
    bd.clear();
    has_key.clear();
    has_key.resize(27, false);
    visited.clear();
    visited.resize(n, vector<bool>(m, false));
    while(!q.empty()) q.pop();
    while(!lockQ.empty()) lockQ.pop();

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        bd.push_back(str);
    }

    string keys;
    cin >> keys;
    if(keys == "0") return;

    for(int i=0; i<keys.size(); i++){
        has_key[keys[i] - 'a'] = true;
    }
}

void Solve()
{
    Scan(); // bd의 가장자리를 스캔하여 출입구를 찾는다.
    while(1){
        Go(); // Q를 비우면서 나아갈 수 있는 곳을 탐색한다.
        Open(); // lockQ를 비우면서 나아갈 수 있는 곳을 탐색한다.
        if(q.empty()) break;
    } 
    cout << answer << endl;
}

void Open(){
    int qs = lockQ.size();
    while(qs--){
        int y = lockQ.front().first;
        int x = lockQ.front().second;
        lockQ.pop();
        if(visited[y][x]) continue;

        if(has_key[bd[y][x] - 'A']){
            visited[y][x] = true;
            q.push({y, x});
        }
        else{
            lockQ.push({y, x});
        }
    }
}

void Go(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(visited[ny][nx]) continue;
                // 벽
                if(bd[ny][nx] == '#') continue;
                // 문
                if('A' <= bd[ny][nx] && bd[ny][nx] <= 'Z'){
                    // 열쇠 보유 중
                    if(has_key[bd[ny][nx] - 'A']){
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                    // 열쇠 없음
                    else{
                        lockQ.push({ny, nx});
                    }
                }
                // 열쇠
                else if('a' <= bd[ny][nx] && bd[ny][nx] <= 'z'){
                    visited[ny][nx] = true;
                    has_key[bd[ny][nx] - 'a'] = true;
                    q.push({ny, nx});
                }
                // 빈 칸
                else if(bd[ny][nx] == '.'){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                // 문서
                else if(bd[ny][nx] == '$'){
                    visited[ny][nx] = true;
                    answer++;
                    q.push({ny, nx});
                }
            }
        }
    }
}

void Scan(){
    // 최상단, 최하단 스캔
    for(int y: {0, n-1}){
        for(int x=0; x<m; x++){
            // 벽
            if(bd[y][x] == '#') continue;
            // 문
            else if('A' <= bd[y][x] && bd[y][x] <= 'Z'){
                lockQ.push({y, x});
            }
            // 빈 칸
            else if(bd[y][x] == '.' && !visited[y][x]){
                visited[y][x] = true;
                q.push({y, x});
            }
            // 열쇠
            else if('a' <= bd[y][x] && bd[y][x] <= 'z' && !visited[y][x]){
                visited[y][x] = true;
                has_key[bd[y][x] - 'a'] = true;
                q.push({y, x});
            }
            // 문서
            else if(bd[y][x] == '$' && !visited[y][x]){
                visited[y][x] = true;
                q.push({y, x});
                answer++;
            }
        }
    }
    // 좌우 스캔
    for(int x: {0, m-1}){
        for(int y=0; y<n; y++){
            // 벽
            if(bd[y][x] == '#') continue;
            // 문
            if('A' <= bd[y][x] && bd[y][x] <= 'Z'){
                lockQ.push({y, x});
            }
            // 빈 칸
            else if(bd[y][x] == '.' && !visited[y][x]){
                visited[y][x] = true;
                q.push({y, x});
            }
            // 열쇠
            else if('a' <= bd[y][x] && bd[y][x] <= 'z' && !visited[y][x]){
                visited[y][x] = true;
                has_key[bd[y][x] - 'a'] = true;
                q.push({y, x});
            }
            // 문서
            else if(bd[y][x] == '$' && !visited[y][x]){
                visited[y][x] = true;
                q.push({y, x});
                answer++;
            }
        }
    }
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