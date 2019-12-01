
/**
 * Seat Change - for DL24 where the number of female students is far less than that of male students)
 * Copyright (c) Robertspot <slx031130@outlook.com>
 */

#include"src/command.h"
#include"src/seat_change.h"
#include"src/file_io.h"

using namespace SeatChangeProcessor;

int main(int argc,char** argv);

int main(int argc,char** argv){

    reg_cmd(argc,argv);

    TriPair grp = read_file(__in);
    PairedNameList pl = seatChange(grp.female,grp.male1,grp.male2);
    write_file(__out,pl);

    return 0;
}