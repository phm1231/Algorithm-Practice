// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

typedef struct DragonCurve{
    int y, x, d, g;
    DragonCurve(int y, int x, int d, int g): y(y), x(x), d(d), g(g) {}
}DragonCurve;

void init();
void input();
void solve();
void drawDC(int stdY, int stdX, vector<pair<int, int> >& locs, int currentGeneration, int generation);
pair<int, int> rotate(int y, int x, int stdY, int stdX);

int n;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

vector<vector<bool> > isDragonCurve;
vector<DragonCurve> DCs;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> n;
    isDragonCurve.resize(101, vector<bool>(101, false));
    for(int i=0; i<n; i++){
        int y, x, d, g;
        cin >> x >> y >> d >> g;
        DCs.push_back(DragonCurve(y, x, d, g));
    }
}

void solve()
{
    for(DragonCurve DC: DCs){
        vector<pair<int, int> > locs;
        int hereY = DC.y;
        int hereX = DC.x;
        int dist = DC.d;
        int generation = DC.g;

        int nextY = hereY + dy[dist];
        int nextX = hereX + dx[dist]; 

        locs.push_back({hereY, hereX});
        isDragonCurve[hereY][hereX] = isDragonCurve[nextY][nextX] = true;;

        if(generation == 0) continue;
        else drawDC(nextY, nextX, locs, 1, generation);
    }

    int answer = 0;
    for(int i=0; i<=99; i++){
        for(int j=0; j<=99; j++){
            if(isDragonCurve[i][j] && isDragonCurve[i+1][j] && isDragonCurve[i][j+1] && isDragonCurve[i+1][j+1]) answer++;
        }
    }
    cout << answer;
}

void drawDC(int stdY, int stdX, vector<pair<int, int> >& locs, int currentGeneration, int generation){
    vector<pair<int, int> > newlocs = locs;
    newlocs.push_back({stdY, stdX});
    pair<int, int> next;
    for(int i=locs.size()-1; i>=0; i--){
        pair<int, int> loc = locs[i];
        next = rotate(loc.first, loc.second, stdY, stdX);
        if(i > 0) newlocs.push_back(next);
        isDragonCurve[next.first][next.second] = true;
    }
    if(currentGeneration == generation) return;
    drawDC(next.first, next.second, newlocs, currentGeneration+1, generation);
}

pair<int, int> rotate(int y, int x, int stdY, int stdX){
    int gapY = stdY - y;
    int gapX = stdX - x;
    return {stdY-gapX, stdX+gapY};
}

// 어떤 점을 기준으로 90도 회전시킨다.
// (1, -1) 을 기준으로 (0, 0) 을 90도 회전시키면 (0, -2)임

int main()
{
    init();
    input();
    solve();
    return 0;
}