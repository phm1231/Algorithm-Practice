#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

void init();
void input();
void solve();
void dfs(int idx, vector<int>& D);

int n, answer;
vector<int> weights;
vector<int> durability;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int d, w;
        cin >> d >> w;
        durability.push_back(d);
        weights.push_back(w);
    }
}

void solve()
{
    dfs(0, durability); // 가장 왼쪽의 계란을 든다.
    cout << answer;
}

void dfs(int idx, vector<int>& D){
    if(idx == n){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(D[i] <= 0) cnt++;
        }
        answer = max(cnt, answer);
        return;
    }

    // 손에 든 계란이 깨졌으면
    if(D[idx] <= 0){
        dfs(idx + 1, D);
        return;
    }
    
    // 다른 계란을 친다.
    bool hitOther = false;
    for(int i=0; i<n; i++){
        // 손에 든 계란이면 패스
        if(i == idx) continue;
        // 이미 깨진 계란이면 패스
        if(D[i] <= 0) continue;

        hitOther = true;
        // idx 계란으로 i번 계란을 침.
        D[i] -= weights[idx];
        D[idx] -= weights[i];
        // 손에 든 계란을 내려놓고 다음 계란을 든다.
        dfs(idx+1, D);
        D[i] += weights[idx];
        D[idx] += weights[i];
    }

    if(!hitOther){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(D[i] <= 0) cnt++;
        }
        answer = max(cnt, answer);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}