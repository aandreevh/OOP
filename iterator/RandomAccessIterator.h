#ifndef TI_RANDOMACCESSITERATOR_H
#define TI_RANDOMACCESSITERATOR_H

#include "BidirectionalIterator.h"

template <typename T,typename P =T*>
class RandomAccessIterator : public BidirectionalIterator<T,P>{

public:

    RandomAccessIterator(){}
    RandomAccessIterator(const P& cursor):Iterator<T,P>(cursor){}
    RandomAccessIterator(const Iterator<T,P>& it):Iterator<T,P>(it){}

    RandomAccessIterator<T,P>&operator=(const Iterator<T,P>& o){
        Iterator<T,P>::operator=(o);
        return *this;
    }

    T& operator[](long long mv) const{
        return (Iterator<T,P>::getCursor()[mv]);
    }




};
#endif //TI_RANDOMACCESSITERATOR_H
