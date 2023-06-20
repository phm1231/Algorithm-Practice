// based problem:
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MAX 100001

void init();
void input();
void solve();

int h, w;
vector<int> heights;
vector<int> tmp_heights;

void init()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
}

void input()
{
    cin >> h >> w;
    for(int i=0; i<w; i++){
        int tmp;
        cin >> tmp;
        heights.push_back(tmp);
    }
    tmp_heights = heights;
}

void solve()
{
    int answer = 0;
    for(int i=1; i<heights.size() - 1; i++){
        int left = -1;
        int right = -1;

        for(int j=i-1; j>=0; j--){
            left = max(heights[j], left);
        }
        for(int j=i+1; j<heights.size(); j++){
            right = max(heights[j], right);
        }
        int H = min(left, right);
        if(H > heights[i]) answer += H - heights[i];
    }
    cout << answer << endl;
}

int main()
{
    init();
    input();
    solve();
    return 0;
}