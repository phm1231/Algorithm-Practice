#include <string>
#include <vector>
#include <map>
#include <iostream>
#define MAX 1000001

using namespace std;

int solution(vector<int>);

int main(){
    vector<int> topping;
    topping.push_back(1);
    topping.push_back(2);
    topping.push_back(1);
    topping.push_back(3);
    topping.push_back(1);
    topping.push_back(4);
    topping.push_back(1);
    topping.push_back(2);
    solution(topping);
    return 0;
}
 
int solution(vector<int> topping) {
    int answer = 0;
    // 토핑의 개수 파악
    // 토핑이 처음과 마지막으로 등장하는 번호 정리
    int siz = topping.size();
    int numberOfTopping = 0;
    map<int, int> m_first;
    map<int, int> m_last;
    for(int i=0; i<siz; i++){
        m_first.insert(make_pair(topping[i], i));
        //m_first[topping[i]] = i;
    }
    for(int i=siz-1; i>=0; i--){
        m_last.insert(make_pair(topping[i], i));
        //m_last[topping[i]] = i;
    }
    numberOfTopping = m_first.size();
    cout << "numberofTopping: " << numberOfTopping << endl;
    for(auto iter: m_first){
        cout << iter.first << ", " << iter.second << endl;
    }
    // dp[i] = i번째 칸을 잘랐을 때, 나뉘어지는 pair
    vector<pair<int, int> > dp;
    dp.push_back(make_pair(0, numberOfTopping));
    
    // 자르기
    for(int i=1; i<siz; i++){
        pair<int, int> before = dp[i-1];
        
        if(m_first[i]){ // 처음 등장하는 토핑이 있다면 
            if(m_first[i] == m_last[i]){ // 토핑 i가 처음이자 마지막으로 등장하는 토핑이라면
                dp.push_back(make_pair(before.first + 1, before.second - 1));
            }
            else{ // 나중에 또 등장하는 토핑이라면
                dp.push_back(make_pair(before.first + 1, before.second));
            }
        }
        else if(m_last[i]){ // 마지막으로 등장하는 토핑이 있다면
            dp.push_back(make_pair(before.first, before.second - 1));
        } // 아니라면
        else{
            dp.push_back(make_pair(before.first, before.second));
        }
    }
    
  	// 확인
    for(int i=0; i<siz; i++){
        cout << dp[i].first << ", " << dp[i].second << endl;
    }
    return answer;
}