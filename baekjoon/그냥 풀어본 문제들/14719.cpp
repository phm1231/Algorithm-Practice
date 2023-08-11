// based problem:
#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int n, m;
vector<int> h, saveh;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n >> m;
    h.resize(m, 0);
    for(int i=0; i<m; i++) cin >> h[i];
    saveh = h;
}

void solve()
{
    for(int here=0; here<m; here++){
        int lx, ly, rx, ry;
        lx = ly = rx = ry = -1;

        for(int left=here-1; left>=0; left--){
            if(h[left] > h[here]){
                ly = h[left];
                lx = left;
                break;
            }
        }
        for(int right=here+1; right<m; right++){
            if(h[right] > h[here]){
                ry = h[right];
                rx = right;
                break;
            }
        }
        // 물이 고이지 못함
        if(ly == -1 || ry == -1) continue;
        // 물이 고일 수 있음
        int height = min(ly, ry);
        for(int left=here; left>lx; left--) h[left] = height;
        for(int right=here+1; right<rx; right++) h[right] = height;

    }

    int answer = 0;
    for(int i=0; i<m; i++){
        cout << h[i] << ' ';
        answer += abs(h[i] - saveh[i]);
    }
    cout << "\n" << answer;
}


int main()
{
    init();
    input();
    solve();
    return 0;
}