#ifndef SLX_FILE_IO

#define SLX_FILE_IO

#include"seat_change.h"
#include<cstdio>
#include<cstdlib>
#include<string>

namespace SeatChangeProcessor{

    struct TriPair{
        NameList female,male1,male2;
    };

    /**
     * @brief width of classroom
     */
    int __width;

    /**
     * @brief Read data from file (as csv format)
     * @param __file input file
     * @return Name lists of female students, male students that are allowed to sit beside female students and male students that are not allowed to sit beside female students
     */
    TriPair read_file(FILE* __file);

    /**
     * @brief Write result to file (as csv format)
     * @param __file output file
     * @param __res_list seat arrangement list
     * @return Nothing
     */
    void write_file(FILE* __file,PairedNameList& __res_list);

    TriPair read_file(FILE* __file){
        fscanf(__file,"%d",&__width);
        TriPair __grp;
        char *__tmp_name;
        int __tmp_sex;
        __tmp_name = (char*)malloc(sizeof(char)*30);
        while(~fscanf(__file,"%d,%s",&__tmp_sex,__tmp_name)){
            if(__tmp_sex == 0){
                __grp.female.push_back(std::string(__tmp_name));
            }else if(__tmp_sex == 1){
                __grp.male1.push_back(std::string(__tmp_name));
            }else{
                __grp.male2.push_back(std::string(__tmp_name));
            }
        }
        return __grp;
    }

    void write_file(FILE* __file,PairedNameList& __res_list){
        for(PairedNameList::iterator __p = __res_list.begin();__p < __res_list.end();__p++){
            fprintf(__file,"%s,%s",__p->second.c_str(),__p->first.c_str());
            if((__p-__res_list.begin()+1)%__width == 0){
                fprintf(__file,"\n");
            }else{
                fprintf(__file,",,");
            }
        }
    }
}

#endif