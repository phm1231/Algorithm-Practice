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

int n;
vector<pair<int, int> > v;


void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
}

void solve()
{
    sort(v.begin(), v.end());
    int answer = 0;
    int left = 0, right = n-1;
    int lh = v[left].second;
    int rh = v[right].second;

    while(left != right){
        // 왼쪽이 더 작음
        if(lh < rh){
            int next = left + 1;
            int gap = v[next].first - v[left].first;
            answer += gap * lh;
            lh = max(lh, v[next].second);
            left = next;
        }
        else{
            int next = right - 1;
            int gap = v[right].first - v[next].first;
            answer += gap * rh;
            rh = max(rh, v[next].second);
            right = next;
        }
    }

    answer += v[left].second;
    cout << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}