// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();
void go(int, int);

int n, m, l, k, answer;
vector<pair<int, int> > stars;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    answer = 0;
}

void input()
{
    cin >> n >> m >> l >> k;
    for(int i=0; i<k; i++){
        int y, x;
        cin >> y >> x;
        stars.push_back(make_pair(y, x));
    }
}

void solve()
{
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            go(stars[i].first, stars[j].second);
        }
    }

    cout << k - answer;
}

void go(int ly, int lx){
    int cnt = 0;
    int ry = ly + l;
    int rx = lx + l;
    for(int i=0; i<k; i++){
        int y = stars[i].first;
        int x = stars[i].second;
        if(ly <= y && y <= ry && lx <= x && x <= rx) cnt++;
    }
    answer = max(cnt, answer);
}

int main()
{
    init();
    input();
    solve();
    return 0;
}