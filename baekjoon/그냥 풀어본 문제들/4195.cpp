// based problem:
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
string getParent(string child);
void merge(string a, string b);

unordered_map<string, string> parent;
unordered_map<string, int> cnt;
string root = "";
int n;

string getParent(string);

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    parent.clear();
    cnt.clear();
    root = "";
}

void input()
{
    cin >> n;
}

void solve()
{
    while(n--){
        string f1, f2;
        cin >> f1 >> f2;
        if(root == "") root = f1;
        if(parent[f1] == "") parent[f1] = f1;
        if(parent[f2] == "") parent[f2] = f2;
        if(cnt[f1] == 0) cnt[f1]++;
        if(cnt[f2] == 0) cnt[f2]++;

        string pf1 = getParent(f1);
        string pf2 = getParent(f2);
        if(pf1 != pf2) merge(pf1, pf2);

        cout << max(cnt[getParent(pf1)], cnt[getParent(pf2)]) << "\n";
    }
}

string getParent(string child){
    if(child == parent[child]) return child;
    else return parent[child] = getParent(parent[child]);
}

void merge(string a, string b){
    string pa = getParent(a);
    string pb = getParent(b);
    if(pa == pb) return;
    // 큰 집합의 아래로 작은 집합이 들어가게.
    if(cnt[pa] < cnt[pb]){
        cnt[pb] += cnt[pa];
        cnt[pa] = 0;
        parent[pa] = pb;
    }
    else{
        cnt[pa] += cnt[pb];
        cnt[pb] = 0;
        parent[pb] = pa;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        init();
        input();
        solve();
    }
    return 0;
}