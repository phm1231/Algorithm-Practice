// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n;
int answer;
vector<bool> isBroken;
vector<pair<int, int> > eggs;
void dfs(int);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    isBroken.resize(n, false);

    for(int i=0; i<n; i++){
        int d, w;
        cin >> d >> w;
        eggs.push_back(make_pair(d, w));
    }
}

void solve()
{
    dfs(0);
    cout << answer;
}

void dfs(int hitter){

    if(hitter == n){
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(isBroken[i]) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }

    if(isBroken[hitter]){
        dfs(hitter+1);
    }
    else{
        for(int target=0; target<n; target++){
            if(target == hitter) continue;
            if(isBroken[target]) continue;

            // target이 꺠지지 않은 계란이라면
            eggs[hitter].first -= eggs[target].second;
            eggs[target].first -= eggs[hitter].second;

            if(eggs[hitter].first <= 0) isBroken[hitter] = true;
            if(eggs[target].first <= 0) isBroken[target] = true;

            // 타격 후에,
            dfs(hitter + 1);

            // 다음 타격을 위해 원상복구.
            eggs[hitter].first += eggs[target].second;
            eggs[target].first += eggs[hitter].second;

            if(eggs[hitter].first > 0) isBroken[hitter] = false;
            if(eggs[target].first > 0) isBroken[target] = false;
        }

        if(hitter == n-1){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(isBroken[i]) cnt++;
            }
            answer = max(answer, cnt);
            return;
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