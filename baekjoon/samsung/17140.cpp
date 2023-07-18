// based problem:
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void R();
void C();

int r, c, k, n, m;
int bd[101][101];

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    memset(bd, 0, sizeof(bd));
    n = m = 3;
}

void input()
{
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            cin >> bd[i][j];
        }
    }
}


void solve()
{
    int t = 0;
    while(t <= 100){
        if(bd[r][c] == k) break;
        t++;
        if(n >= m) R();
        else C();
        
    }
    if(t == 101) cout << -1;
    else cout << t;
}

void R(){
    int newbd[101][101] = {0, };
    int beforeM = m; // 이전에 가장 큰 m 인덱스
    int newM = 0;
    // 모든 행에 대해서 검사.
    for(int i=1; i<=n; i++){
        priority_queue<pair<int, int> > pq;
        unordered_map<int, int> uom;
        // i행의 모든 값에 대해 카운트

        for(int j=1; j<=beforeM; j++){
            if(bd[i][j] == 0) continue;
            uom[bd[i][j]]++;
        }
        // 정렬
        for(auto iter = uom.begin(); iter != uom.end(); iter++){
            int num = iter->first; // 수
            int cnt = iter->second; // 등장횟수
            // 수의 등장횟수가 커지는 순으로, 수가 커지는 순으로 오름차순 정렬할 것.
            pq.push(make_pair(-cnt, -num));
        }
        // 저장
        int midx = 1;
        int tmpM =0;
        while(!pq.empty()){
            int cnt = -pq.top().first; // 등장횟수
            int num = -pq.top().second; // 수
            pq.pop();

            newbd[i][midx] = num;
            tmpM = max(tmpM, midx);
            midx++;
            if(midx > 100) break;

            newbd[i][midx] = cnt;
            tmpM = max(tmpM, midx);
            midx++;
            if(midx > 100) break;
        }
        newM = max(newM, tmpM);
    }

    memset(bd, 0, sizeof(bd));
    m = newM;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            bd[i][j] = newbd[i][j];
        }
    }
}

void C(){
    int newbd[101][101] = {0, };
    int beforeN = n;
    int newN = 0;
    // 모든 열에 대해서 검사.
    for(int j=1; j<=m; j++){

        priority_queue<pair<int, int> > pq; // 수의 등장횟수가 커지는 순으로, 수가 커지는 순으로 오름차순 정렬할 것.
        unordered_map<int, int> uom;
        // i행의 모든 값에 대해 카운트
        for(int i=1; i<=beforeN; i++){
            if(bd[i][j] == 0) continue;
            uom[bd[i][j]]++;
        }
        // 정렬
        for(auto iter = uom.begin(); iter != uom.end(); iter++){
            int num = iter->first; // 수
            int cnt = iter->second; // 등장횟수
            pq.push(make_pair(-cnt, -num));
        }
        // 저장
        int nidx = 1;
        int tmpN = 1;
        while(!pq.empty()){
            int cnt = -pq.top().first; // 등장횟수
            int num = -pq.top().second; // 수
            pq.pop();

            newbd[nidx][j] = num;
            tmpN = max(tmpN, nidx);
            nidx++;
            if(nidx > 100) break;

            newbd[nidx][j] = cnt;
            tmpN = max(tmpN, nidx);
            nidx++;
            if(nidx > 100) break;
        }
        newN = max(newN, tmpN);
    }
    n = newN;
    memset(bd, 0, sizeof(bd));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            bd[i][j] = newbd[i][j];
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