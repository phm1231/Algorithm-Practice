// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct load{
    int src, dst, weight;
    load(int s, int d, int w): src(s), dst(d), weight(w) {}
}load;


void init();
void input();
void solve();
void dfs(int here, int num, int sum);
bool cmp(const load& a, const load& b);

int n, d;
int answer = 987654321;
vector<load> v;

bool cmp(const load& a, const load& b){
    return a.src < b.src;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> d;
    for(int i=0; i<n; i++){
        int s, d, w;
        cin >> s >> d >> w;
        v.push_back(load(s, d, w));
    }
    sort(v.begin(), v.end(), cmp);
}

void solve()
{
    dfs(0, 0, 0);
    cout << answer;
}

void dfs(int here, int num, int sum){
    // 도착
    if(here == d){
        answer = min(answer, sum);
        return;
    }
    // 목적지를 넘어가서 도착
    if(here > d) return;

    // 고속도로 번호
    for(int i=num; i<n; i++){
        int src = v[i].src;
        int dst = v[i].dst;
        int weight = v[i].weight;

        // i번 지름길을 이용할 수 있다면, 지름길 앞으로 이동한다.
        if(here < src){
            dfs(src, i, sum + src - here);
        }
        // i번 지름길을 이용한다
        else if(here == src){
            dfs(dst, i+1, sum + weight);
        }
    }
    // 
    dfs(d, n, sum + (d - here));
}


int main()
{
    init();
    input();
    solve();
    return 0;
}