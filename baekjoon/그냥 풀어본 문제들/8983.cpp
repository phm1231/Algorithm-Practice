// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int m, n, l; // 사대, 동물, 사거리
vector<int> guns; // 사대 위치
vector<pair<int, int> > animals; // 동물 위치

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> m >> n >> l;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        guns.push_back(x);
    }
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        animals.push_back(make_pair(x, y));
    }
}

void solve()
{
    sort(guns.begin(), guns.end());
    int answer = 0;
    for(int i=0; i<animals.size(); i++){
        int x = animals[i].first;
        int y = animals[i].second;
        int idx = lower_bound(guns.begin(), guns.end(), x) - guns.begin(); // 동물과 가장 가까운 사대의 좌표

        if(idx != guns.size()){
            int g = guns[idx];
            if(abs(g-x)+y <= l){
                answer++;
                continue;
            }
        }
        if(idx > 0){
            int g = guns[idx-1];
            if(abs(g-x)+y <= l){
                answer++;
                continue;
            }
        }
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