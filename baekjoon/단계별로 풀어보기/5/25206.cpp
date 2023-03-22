#include <iostream>
#include <string>

using namespace std;

void init();
void input();
void solve();
double getScore(string);

int main(){
    init();
    input();
    solve();
    return 0;
}

void init(){

}

void input(){

}

void solve(){
    string subject;
    double score;
    string grade;
    double sum = 0.0;
    double sumofscore = 0.0;

    for(int i=0; i<20; i++){
        cin >> subject >> score >> grade;
        if(grade.compare("P") != 0){
            sum += getScore(grade) * score; // 과목평점 * 학점
            sumofscore += score;
        }
    }
    printf("%lf", sum / sumofscore);
}

double getScore(string s){
    if(s.compare("A+") == 0)
        return 4.5;
    else if(s.compare("A0") == 0)
            return 4.0;
    else if(s.compare("B+") == 0)
            return 3.5;
    else if(s.compare("B0") == 0)
            return 3.0;
    else if(s.compare("C+") == 0)
            return 2.5;
    else if(s.compare("C0") == 0)
            return 2.0;
    else if(s.compare("D+") == 0)
            return 1.5;
    else if(s.compare("D0") == 0)
            return 1.0;
    else if(s.compare("F") == 0)
            return 0.0;
    else
            return 0.0;
}