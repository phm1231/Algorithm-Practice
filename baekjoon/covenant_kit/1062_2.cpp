// based problem:
#include <iostream>
#include <vector>

using namespace std;


#define ll long long
#define MAX 100001

void init();
void input();
void solve();
int check();
void dfs(char alpha, int cnt);

int n, k;
int answer = 0;
vector<string> v;
vector<bool> isLearned(27, false);

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
        v.push_back(tmp);
    }
}

void solve()
{
    if(k < 5){
        cout << 0;
        return;
    }
    isLearned['a' - 'a'] = true;
    isLearned['n' - 'a'] = true;
    isLearned['t' - 'a'] = true;
    isLearned['i' - 'a'] = true;
    isLearned['c' - 'a'] = true;

    dfs('b', 5);

    cout << answer << endl;

}

void dfs(char alpha, int cnt){ // 현재까지 배운 것은 cnt개. alpha를 배울지 말지 결정해야 한다.

    if(cnt == k){
        answer = max(answer, check());
        return;
    }
    if(alpha > 'z') return;

    if(alpha == 'a' || alpha == 'n' || alpha == 't' || alpha == 'i' || alpha == 'c'){
        dfs(alpha + 1, cnt);
    }
    else{
        isLearned[alpha - 'a'] = true;
        dfs(alpha + 1, cnt + 1);
        isLearned[alpha - 'a'] = false;
        dfs(alpha + 1, cnt);
    }

}

int check(){
    int _answer = 0;
    for(string str: v){
        bool canRead = true;
        for(int i=0; i<str.size(); i++){
            if(!isLearned[str[i] - 'a']){
                canRead = false;
                break;
            }
        }
        if(canRead) _answer++;
    }
    return _answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}