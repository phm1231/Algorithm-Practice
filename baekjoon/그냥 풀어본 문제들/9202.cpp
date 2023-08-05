// based problem:
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define ll long long
#define MAX 100001

typedef struct node{
    int y, x, idx;
    node(int y, int x, int idx): y(y), x(x), idx(idx) {}
}node;

void init();
void input();
void solve();
void go(const int strnum, const int bdnum);
void dfs(const int strnum, const int bdnum, const node& n, vector<vector<bool> >& visited);
int getScore(const int length);

bool isFind;
int w, b;
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<string> dics;
vector<vector<string> > bd;
vector<int> score;
vector<string> longest_str;
vector<int> cnt;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> w;
    for(int i=0; i<w; i++){
        string tmp;
        cin >> tmp;
        dics.push_back(tmp);
    }
    cin >> b;
    bd.resize(b, vector<string>());

    score.resize(b, 0);
    longest_str.resize(b, "");
    cnt.resize(b, 0);

    for(int i=0; i<b; i++){
        for(int j=0; j<4; j++){
            string tmp;
            cin >> tmp;
            bd[i].push_back(tmp);
        }
    }
}

// 각각의 bd에 대해 얻을 수 있는 최대 점수, 가장 긴 단어

void solve()
{
    for(int i=0; i<w; i++){ // 모든 단어에 대해
        for(int j=0; j<b; j++){ // 모든 보드
            go(i, j);
        }
    }
    for(int i=0; i<b; i++){
        if(cnt[i] > 0){
            cout << score[i] << ' ' << longest_str[i] << ' ' << cnt[i] << "\n";
        }
    }
}

void go(const int strnum, const int bdnum){
    isFind = false;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(bd[bdnum][i][j] == dics[strnum][0]){
                vector<vector<bool> > visited(4, vector<bool>(4, false));
                visited[i][j] = true;
                dfs(strnum, bdnum, node(i, j, 0), visited);
            }
            if(isFind) return;
        }
        if(isFind) return;
    }
}

void dfs(const int strnum, const int bdnum, const node& n, vector<vector<bool> >& visited){
    if(isFind) return;

    int y = n.y;
    int x = n.x;
    int idx = n.idx;

    // bd[bdnum]에서 dics[strnum] 단어를 찾음.
    if(idx == dics[strnum].size() - 1){
        score[bdnum] += getScore(dics[strnum].size());
        // 길이가 더 긴 것
        if(longest_str[bdnum].size() < dics[strnum].size()){
            longest_str[bdnum] = dics[strnum];
        }
        // 길이가 같다면, 사전순으로 앞서는 것
        else if(longest_str[bdnum].size() == dics[strnum].size() && longest_str[bdnum] > dics[strnum]){
            longest_str[bdnum] = dics[strnum];
        }
        cnt[bdnum]++;
        isFind = true;
        return;
    }

    for(int i=0; i<8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < 4 && 0 <= nx && nx < 4){
            if(bd[bdnum][ny][nx] == dics[strnum][idx+1] && !visited[ny][nx]){
                visited[ny][nx] = true;
                dfs(strnum, bdnum, node(ny, nx, idx+1), visited);
                visited[ny][nx] = false;
            }
        }
        if(isFind) return;
    }
    return;
}

int getScore(const int length){
    if(3 <= length && length <= 4) return 1;
    else if(length == 5) return 2;
    else if(length == 6) return 3;
    else if(length == 7) return 5;
    else if(length == 8) return 11;

    else return 0;
}



int main()
{
    init();
    input();
    solve();
    return 0;
}