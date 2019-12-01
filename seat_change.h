#ifndef SLX_SEAT_CHANGE

#define SLX_SEAT_CHANGE

#include<vector>
#include<string>
#include<cstdlib>
#include<utility>
#include<ctime>
#include<cstdio>

namespace SeatChangeProcessor{
    typedef std::vector<std::string> NameList;
    typedef std::vector< std::pair<std::string,std::string> > PairedNameList;
    typedef std::vector<int> IntegerList;

    /**
     * @brief Generates a random permutation (starts from 0)
     * @param __num length of the permutation
     * @return permutation
     */
    IntegerList __randPermutation(int);

    /**
     * @brief Shuffle a vector
     * @param __list vector
     * @return Nothing
     */
    template<typename T>
    void __shuffle(std::vector<T>&);

    /**
     * @brief Handle an exception when the number of female students is greater than thie number of male students
     * @todo wanna try C++ exception throw/try/catch but CRS gugu it. :-)
     * @param __num_f Number of female students
     * @param __num_m Number of male students
     * @return Never
     */
    void __throw_unexpected_amount(size_t,size_t);

    /**
     * @brief Process of seat change (Only suitable for DL24 where the number of male students is far more than the number of female students.)
     * @param __list_female names female students
     * @param __list_male_a names of male students that are allowed to seat beside female students
     * @param __list_male_b names of male students that are not allowed to seat beside female students
     * @return Seat arrangement table
     */
    PairedNameList seatChange(NameList&,NameList&,NameList);


    
    IntegerList __randPermutation(int __num){
        srand((unsigned)time(NULL));
        IntegerList numList(__num);
        for(IntegerList::iterator __p = numList.begin();__p < numList.end();__p++){
            *__p = __p - numList.begin();
        }
        for(IntegerList::iterator __p = numList.begin();__p < numList.end();__p++){
            std::swap(*__p,numList[rand()%__num]);
        }
        return numList;
    }

    template<typename T>
    void __shuffle(std::vector<T>& __list){
        const IntegerList __permu = __randPermutation(__list.size());
        for(typename std::vector<T>::iterator __p = __list.begin();__p < __list.end();__p++){
            std::swap(*__p,__list[__permu[__p - __list.begin()]]);
        }
    }

    void __throw_unexpected_amount(size_t __num_f,size_t __num_m){
        fprintf(stderr,"The number of female students(%ld) is greater than the number of male students(%ld).\nSuch condition shouldn't happen in DL24 senior high\n",__num_f,__num_m);
        exit(1);
    }

    PairedNameList seatChange(NameList& __list_female,NameList& __list_male_a,NameList __list_male_b){
        if(__list_female.size() > __list_male_a.size()){
            __throw_unexpected_amount(__list_female.size(),__list_male_a.size());
        }
        __shuffle(__list_female);
        __shuffle(__list_male_a);
        PairedNameList __res_list;
        NameList::iterator __p_female = __list_female.begin();
        NameList::iterator __p_male_a = __list_male_a.begin();
        for(;__p_female < __list_female.end() && __p_male_a < __list_male_a.end();__p_female++,__p_male_a++){
            __res_list.push_back(std::make_pair(*__p_male_a,*__p_female));
        }
        //Combinate unpaired male students into list B
        for(;__p_male_a < __list_male_a.end();__p_male_a++){
            __list_male_b.push_back(*__p_male_a);
        }
        if(__list_male_b.size() & 1){
            __list_male_b.push_back("NULL");
        }
        __shuffle(__list_male_b);
        NameList::iterator __p_l = __list_male_b.begin();
        NameList::iterator __p_r = __list_male_b.end()-1;
        for(;__p_l<__p_r;__p_l++,__p_r--){
            __res_list.push_back(std::make_pair(*__p_l,*__p_r));
        }
        __shuffle(__res_list);
        return __res_list;
    }
}
#endif