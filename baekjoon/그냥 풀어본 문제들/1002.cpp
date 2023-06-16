// based problem:
#include <iostream>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int x1, y1, x2, y2, r1, r2, t;

void init()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void input()
{
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
}

void solve()
{
    int d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    int sub = (r1-r2)*(r1-r2);
    int add = (r1+r2)*(r1+r2);

    // 두 원의 중심이 같을 때
    if(d == 0){
        // 반지름이 같다면
        if(r1 == r2) cout << -1 << endl;
        // 반지름이 다르다면
        else cout << 0 << endl;
    }
    // 두 원의 중심이 다를 때
    else{
        // 멀리 떨어져서 접점이 없다면, -> r1+r2 < d
        if(add < d){
            cout << 0 << endl;
        }
        // 외접하여 접점이 1개라면, -> r1+r2 == d
        else if(add == d){
            cout << 1 << endl;
        }
        // 두 원의 접점이 2개라면, -> r1-r2<d<r1+r2
        else if(sub < d && d < add){
            cout << 2 << endl;
        }
        // 내접하여 접점이 1개라면, ->
        else if(sub == d){
            cout << 1 << endl;
        }
        // 원 안에 원이 있지만 만나지 않는다면, -> d < r1 - r2
        else if(d < sub){
            cout << 0 << endl;
        }
    }
}

int main()
{
    init();
    cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}