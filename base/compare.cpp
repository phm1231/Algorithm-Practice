#include <iostream>
#include <queue>

using namespace std;

void init();
void input();
void solve();

struct compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
//        return a.first > b.first; // 오름차순
//        return a.first < b.first; // 내림차순
        return a.second < b.second;
    }
};

priority_queue< pair<int, int>, vector<pair<int, int> >, compare> pq;

int main(){
    init();
    input();
    solve();
    return 0;
}

void init(){
    pq.push(make_pair(1, 10));
    pq.push(make_pair(2, 9));
    pq.push(make_pair(3, 8));
    pq.push(make_pair(4, 7));
    pq.push(make_pair(5, 6));
}

void input(){

}

void solve(){
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
}