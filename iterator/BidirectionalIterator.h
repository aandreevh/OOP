
#ifndef TI_BIDIRECTIONALITERATOR_H
#define TI_BIDIRECTIONALITERATOR_H

#include "ForwardIterator.h"
#include "BackwardIterator.h"

template <typename T,typename P = T*>
class BidirectionalIterator : public ForwardIterator<T,P>,public BackwardIterator<T,P>{

public:

    BidirectionalIterator(){}
    BidirectionalIterator(const P& cursor):Iterator<T,P>(cursor){}
    BidirectionalIterator(const Iterator<T,P>& it):Iterator<T,P>(it){}


    BidirectionalIterator<T,P>&operator=(const Iterator<T,P>& o){
        Iterator<T,P>::operator=(o);
        return *this;
    }


};
#endif //TI_BIDIRECTIONALITERATOR_H
