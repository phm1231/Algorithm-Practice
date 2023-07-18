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

int n, d, k, c; // 접시 수, 가짓 수, 연속 수, 쿠폰 번호
vector<int> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> d >> k >> c;
    v.resize(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
}

void solve()
{
    int answer = 0;
    unordered_map<int, int> uom;
    uom[c]++;
    for(int i=0; i<k; i++) uom[v[i]]++;
    answer = uom.size();

    int current = answer;
    for(int i=k; i<n+k; i++){
        int removed = v[i-k];
        int added = v[i%n];
        if(removed == added) continue;
        if(removed != c) uom[removed]--;

        if(uom[added] == 0) current++;
        uom[added]++;

        if(uom[removed] == 0) current--;

        answer = max(answer, current);
    }
    cout << answer;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}