#include"seat_change.h"
#include"file_io.h"
#include<stdio.h>
#include<iostream>
using namespace SeatChangeProcessor;
int main(){
    FILE* in = fopen("in.csv","rb");
    FILE* out = fopen("out.csv","wb");
    TriPair grp = read_file(in);
    PairedNameList pl = seatChange(grp.female,grp.male1,grp.male2);
    write_file(out,pl);
    return 0;
}