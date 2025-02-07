#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(1){
        int big_wallet = max(wallet[0], wallet[1]);
        int small_wallet = min(wallet[0], wallet[1]);
        int big_bill = max(bill[0], bill[1]);
        int small_bill = min(bill[0], bill[1]);
        if(big_wallet >= big_bill && small_wallet >= small_bill){
            return answer;
        }
        else if(big_wallet < big_bill || small_wallet < small_bill){
            bill[0] = big_bill/2;
            bill[1] = small_bill;
            answer++;
        }
    }
    
}