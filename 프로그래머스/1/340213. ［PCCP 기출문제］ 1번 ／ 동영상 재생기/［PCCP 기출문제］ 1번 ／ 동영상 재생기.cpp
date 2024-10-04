#include <bits/stdc++.h>

using namespace std;

int v_len_min, v_len_sec; // 비디오 위치
int p_min, p_sec; // 현재 위치
int op_st_min, op_st_sec; // 오프닝 시작 위치
int op_en_min, op_en_sec; // 오프닝 끝 위치

void cross();

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    string temp;
    vector<string> v_temp;
    
    istringstream iss(video_len);
    // video 위치 숫자로 저장
    while (getline(iss, temp, ':'))
        v_temp.push_back(temp);
    v_len_min = stoi(v_temp[0]);
    v_len_sec = stoi(v_temp[1]);
    v_temp.clear();
    
    istringstream oss(pos);
    // 현재위치 숫자로 저장
    while(getline(oss, temp, ':'))
        v_temp.push_back(temp);
    p_min = stoi(v_temp[0]);
    p_sec = stoi(v_temp[1]);
    v_temp.clear();
    
    istringstream pss(op_start);
    // 오프닝 시작위치 숫자로 저장
    while(getline(pss, temp, ':'))
        v_temp.push_back(temp);
    op_st_min = stoi(v_temp[0]);
    op_st_sec = stoi(v_temp[1]);
    v_temp.clear();
    
    istringstream uss(op_end);
    // 오프닝 끝 위치 숫자로 저장
    while(getline(uss, temp, ':'))
        v_temp.push_back(temp);
    op_en_min = stoi(v_temp[0]);
    op_en_sec = stoi(v_temp[1]);
    v_temp.clear();
    
    
    cross();
        
    // for문으로 명령 읽고 수행
    for(int i=0;i<commands.size();i++){
        // 시간 전후로 이동하는 것
        if(commands[i] == "next"){
            p_sec += 10;
            if(p_sec >= 60){
                p_sec %= 60;
                p_min++;
            }
            if(p_min > v_len_min){
                p_min = v_len_min;
                p_sec = v_len_sec;
            }
            else if(p_min == v_len_min){
                if(p_sec>v_len_sec) p_sec = v_len_sec;
            }
        }
        else{
            p_sec -= 10;
            if(p_sec < 0){
                p_sec = 60 + p_sec;
                p_min--;
                if(p_min < 0){
                    p_min = 0;
                    p_sec = 0;
                }
            }
        }
        cross();
    }
    cross();
        
    if(p_min<10 && p_sec<10){
        answer = '0' +to_string(p_min) + ":" + '0' +to_string(p_sec);
    }
    else if(p_min >= 10 && p_sec<10){
        answer = to_string(p_min) + ":" + '0' +to_string(p_sec);
    }
    else if(p_min<10 && p_sec >= 10){
        answer = '0' +to_string(p_min) + ":" + to_string(p_sec);
    }
    else answer = to_string(p_min) + ":" + to_string(p_sec);
    
    return answer;
}


void cross(){
    if(op_st_min<p_min && p_min<op_en_min){
        p_min = op_en_min;
        p_sec = op_en_sec;
    }
    else if(op_st_min == p_min && p_min == op_en_min){
        if(op_st_sec<= p_sec && p_sec<op_en_sec) p_sec = op_en_sec;
    }
    else if(op_st_min == p_min){
        if(op_st_sec <= p_sec){
            p_min = op_en_min;
            p_sec = op_en_sec;
        }
    }
    else if(p_min == op_en_min){
        if(p_sec < op_en_sec){
            p_sec = op_en_sec;
        }
    }
}