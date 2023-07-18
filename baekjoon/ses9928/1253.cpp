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

int n;
vector<int> v;
unordered_map<int, int> uom; // 합이 존재하는 개수
unordered_map<int, int> cnt;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }

}

void solve()
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            uom[v[i] + v[j]]++;
        }
    }

    // uom[sum] = 합으로 등장할 수 있는 수의 개수
    int answer = 0;

    for(int num: v){
        if(num == 0 && uom[num] >= cnt[0]) answer++;
        else if(uom[num] > cnt[0]) answer++;
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