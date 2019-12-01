#include"seat_change.h"
#include<stdio.h>
#include<iostream>
using namespace SeatChangeProcessor;
int main(){
    NameList f({"f-a","f-b","f-c"});
    NameList m({"m-a","m-b","m-c","m-d","m-e","m-f"});
    NameList m2({"2-a","2-b","2-c","2-d"});
    PairedNameList pl = seatChange(f,m,m2);
    for(int i = 0;i<pl.size();i++){
        std::cout<<pl[i].first<<" "<<pl[i].second<<"\n";
    }
    return 0;
}