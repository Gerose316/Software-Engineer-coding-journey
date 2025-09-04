#include <iostream>
#include <vector>
#include <string>

int checkGrade(int same,int  diff,int  news, int pos, int correct){
    if (correct <= same){
        pos = pos + correct;
    }else{
        pos = pos + same;
    }
    if(news <= diff){
        pos = pos + news;
    }else{
        pos = pos + diff;
    }
    std::cout << pos << std::endl;
    return 0;   

}

int main(){
    int correct;
    int pos;
    std::string me;
    std::string friendly;
    std::cin>> correct;
    std::cin >> me;
    std::cin >> friendly;

    int same = 0;
    int diff = 0;
    for(int i = 0; i < me.size(); i++){
        if(me[i] == friendly[i]){
            same++;
        }else{
            diff++;
        }
    }
    int news = me.size() - correct;

    checkGrade(same, diff, news, pos, correct);


    


    







}