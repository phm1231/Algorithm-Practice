#include <iostream>
#include <vector>

#define ll long long
#define MAX 100001
#define endl "\n";

using namespace std;

typedef struct lectangle{
    int y1, x1, y2, x2;
    lectangle(int y1, int x1, int y2, int x2): y1(y1), x1(x1), y2(y2), x2(x2) {}
}lectangle;

void init();
void input();
void solve();
bool needUp(const lectangle& a, const lectangle& b);
int getParent(int a);
void merge(int a, int b);

bool canStartZero = false;
int n;
vector<lectangle> v;
vector<int> parent;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    parent.resize(n, 0);
    for(int i=0; i<n; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        v.push_back(lectangle(y1, x1, y2, x2));
        parent[i] = i;

        // (0, 0)에서 출발할 수 있음.
        if(!canStartZero){
            if(y1 == 0 && y2 == 0) canStartZero = true;
            else if(x1 == 0 && x2 == 0) canStartZero = true;
            else if(x1 == 0 && y1 == 0) canStartZero = true;
            else if(x2 == 0 && y2 == 0) canStartZero = true;
            else if(x1 == 0 && y1 <= 0 && y2 >= 0) canStartZero = true;
            else if(y1 == 0 && x1 <= 0 && x2 >= 0) canStartZero = true;
            else if(x2 == 0 && y2 >= 0 && y1 <= 0) canStartZero = true;
            else if(y2 == 0 && x2 >= 0 && x1 <= 0) canStartZero = true;
        }
    }

}

void solve()
{
    for(int a=0; a<n; a++){
        for(int b=a+1; b<n; b++){
            int pa = getParent(a);
            int pb = getParent(b);
            if(pa == pb) continue;

            // a와 b가 겹친다면
            if(needUp(v[a], v[b])) merge(a, b);
        }
    }

    int union_cnt = 0;
    // 집합의 개수
    for(int i=0; i<n; i++){
        if(parent[i] == i) union_cnt++;
    }
    // 0에서 시작할 수 있으면, 집합의 개수 - 1;
    if(canStartZero) cout << union_cnt - 1;
    else cout << union_cnt;
}

int getParent(int a){
    if(a == parent[a]) return a;
    else return parent[a] = getParent(parent[a]);
}

void merge(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);

    if(pa > pb) parent[pa] = pb;
    else parent[pb] = pa;
}


bool needUp(const lectangle& a, const lectangle& b){
    // a 안에 b가 있다.
    if(a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2) return false;
    // b 안에 a이 있다.
    if(b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2) return false;
    // a이 b 보다 위에 있다.
    if(a.y2 < b.y1) return false;
    // b가 a 보다 위에 있다.
    if(b.y2 < a.y1) return false;
    // a이 b 보다 좌측에 있다.
    if(a.x2 < b.x1) return false;
    // b가 a 보다 좌측에 있다.
    if(b.x2 < a.x1) return false;
    
    return true;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}