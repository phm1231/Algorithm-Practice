// based problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 100001

typedef struct node{
    int color, siz, idx;
    node(int c, int s, int i): color(c), siz(s), idx(i) {}
}node;

void init();
void input();
void solve();

int n;
vector<node> v;
vector<int> answer;
vector<int> color, siz;

bool cmp(const node& n1, const node& n2){
    if(n1.siz == n2.siz) return n1.color < n2.color;
    return n1.siz < n2.siz;
}

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    color.resize(n+1, 0);
    siz.resize(2001, 0);
    answer.resize(n, 0);

    for(int i=0; i<n; i++){
        int color, siz;
        cin >> color >> siz;
        v.push_back(node(color, siz, i));
    }
}

void solve()
{
    sort(v.begin(), v.end(), cmp);
    // 사이즈 순으로 오름차순 정렬
    int sum = 0;

    for(int i=0; i<n; i++){
        int c = v[i].color;
        int s = v[i].siz;
        int idx = v[i].idx;
        
        color[c] += s; // color c의 크기의 합
        siz[s] += s; // siz s의 크기의 합
        sum += s;

        // idx번 공이 사로잡을 수 있는 공들의 크기 합
        // 여태껏 공 크기들의 합 - idx번 공과 색이 같은 공들의 합 - idx번 공과 크기가 같은 공들의 합 + 자기자신 (color와 siz를 뻄으로써 2번 빠졌으므로.)
        answer[idx] = sum - color[c] - siz[s] + s;

        // 나와 크기도, 색도 동일하다면
        if(i != 0 && v[i-1].color == c && v[i-1].siz == s) answer[idx] = answer[v[i-1].idx];
    }

    for(int i=0; i<n; i++) cout << answer[i] << "\n";

}

int main()
{
    init();
    input();
    solve();
    return 0;
}