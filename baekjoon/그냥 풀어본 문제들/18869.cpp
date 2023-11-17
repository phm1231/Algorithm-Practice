#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define endl "\n";

using namespace std;

void Init();
void Input();
void Solve();

const int MAX = 1e9;
vector<vector<pair<int, int> > > planets;
int n, m;

void Init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void Input()
{
    cin >> n >> m;
    planets.resize(n, vector<pair<int, int> >());
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int planet;
            cin >> planet;
            planets[i].push_back({planet, j});
        }
        sort(planets[i].begin(), planets[i].end());
    }
}

void Solve()
{
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bool is_equal = true;
            for(int k=0; k<m; k++){
                if(planets[i][k].second != planets[j][k].second){
                    is_equal = false;
                    break;
                }
                else{
                    if(k < m-1){
                        if(planets[i][k].first < planets[i][k+1].first != planets[j][k].first < planets[j][k+1].first){
                            is_equal = false;
                            break;
                        }
                    }
                }
            }
            if(is_equal) answer++;
        }
    }
    cout << answer;
}


int main()
{
    Init();
    Input();
    Solve();
    return 0;
}