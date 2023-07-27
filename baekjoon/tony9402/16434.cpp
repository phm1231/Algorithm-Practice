// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct room{
    int type, a, h;
    room(int type, int a, int h): type(type), a(a), h(h) {}
}room;

void init();
void input();
void solve();

ll n, attack;
vector<room> v;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> attack;
    v.push_back(room(0, 0, 0));

    for(int i=1; i<=n; i++){
        int t, a, h;
        cin >> t >> a >> h;
        v.push_back(room(t, a, h));
    }
}

void solve()
{
    ll answer = 0;
    ll damage = 0;
    for(int i=1; i<=n; i++){
        int type = v[i].type;
        int a = v[i].a;
        int h = v[i].h;
        // 몬스터
        if(type == 1){
            // 용사가 몬스터를 무찌르기 위해 몇 턴이 필요한가?
            ll turn = h / attack + (h % attack != 0);
            damage += a * (turn - 1);
            answer = max(damage, answer);
        }
        // 포션
        else{
            attack += a;
            damage -= h;
            if(damage < 0) damage = 0;
        }
    }
    cout << answer + 1;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}