// based problem:
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100001
#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void init();
void input();
void solve();
void dfs(vector<int>& v, int idx);

vector<int> heights;
bool isFind = false;

void init()
{
    FAST
}

void input()
{
    for(int i=0; i<9; i++){
        int tmp;
        cin >> tmp;
        heights.push_back(tmp);
    }
}

void solve()
{
    vector<int> a;
    dfs(a, 0);
    return;
}

void dfs(vector<int>& v, int idx){
    if(isFind) return;

    if(v.size() == 7){
        int sum = 0;
        for(int num: v) sum += num;
        if(sum == 100){
            isFind = true;
            sort(v.begin(), v.end());
            for(int num: v) cout << num << endl;
        }
        return;
    }

    if(idx == 9){
        return;
    }

    v.push_back(heights[idx]);
    dfs(v, idx + 1);
    v.pop_back();
    dfs(v, idx + 1);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}