// based problem:
#include <iostream>
#include <vector>
#include <set>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void dfs(int, char);

int n, k, answer;
vector<bool> isLearn(26, false);
vector<string> vs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        vs.push_back(tmp);
    }
}

void solve()
{
    if(k < 5){
        cout << 0;
        return;
    }

    vector<int> targets;
    answer = -987654321;
    isLearn['a' - 'a'] = true;
    isLearn['n' - 'a'] = true;
    isLearn['t' - 'a'] = true;
    isLearn['i' - 'a'] = true;
    isLearn['c' - 'a'] = true;
    dfs(5, 'b');
    cout << answer;
}

void dfs(int cnt, char alpha){
    
    // k개를 배움
    if(cnt == k){
        int cnt = 0;
        for(int i=0; i<vs.size(); i++){
            bool canRead = true;
            for(int j=0; j<vs[i].size(); j++){
                if(!isLearn[vs[i][j] - 'a']){
                    canRead = false;
                    break;
                }
            }
            if(canRead) cnt++;
        }
        answer = max(cnt, answer);
        return;
    }

    if(alpha > 'z') return;

    // 이미 배운 것이라면
    if(alpha == 'a' || alpha == 'n' || alpha == 't' || alpha == 'i' || alpha == 'c'){
        dfs(cnt, alpha + 1);
    }
    else{
        isLearn[alpha - 'a'] = true;
        dfs(cnt + 1, alpha + 1);
        isLearn[alpha - 'a'] = false;
        dfs(cnt, alpha + 1);
    }
}

int main()
{
    init();
    input();
    solve();
    return 0;
}