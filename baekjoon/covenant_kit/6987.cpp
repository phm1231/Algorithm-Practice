// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int);

const int n = 6;
int result = 0;
vector<vector<int> > results;
vector<vector<int> > scores;
vector<pair<int, int> > rounds;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            rounds.push_back(make_pair(i, j));
        }
    }
}

void input()
{
    results.clear(), results.resize(n, vector<int>(3, 0)); // 0 = win, 1 = draw, 2 = lose
    scores.clear(), scores.resize(n, vector<int>(3, 0));
    result = 0;
    for(int i=0; i<n; i++){
        cin >> results[i][0] >> results[i][1] >> results[i][2];
    }
}

void solve()
{
    dfs(0);
    cout << result << ' ';
}

void dfs(int round){
    if(round == 15){
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                if(scores[i][j] != results[i][j]){
                    return;
                }
            }
        }
        result = 1;
        return;
    }

    int t1 = rounds[round].first;
    int t2 = rounds[round].second;
    // t1승 t2패
    scores[t1][0]++;
    scores[t2][2]++;
    dfs(round+1);    
    scores[t1][0]--;
    scores[t2][2]--;

    // t1, t2 무승부
    scores[t1][1]++;
    scores[t2][1]++;
    dfs(round+1);    
    scores[t1][1]--;
    scores[t2][1]--;

    // t1 패, t2 승
    scores[t1][2]++;
    scores[t2][0]++;
    dfs(round+1);    
    scores[t1][2]--;
    scores[t2][0]--;
}

int main()
{
    init();
    for(int i=0; i<4; i++){
        input();
        solve();
    }
    return 0;
}