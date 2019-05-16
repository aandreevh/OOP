
#ifndef TI_BACKWARDITERATOR_H
#define TI_BACKWARDITERATOR_H
#include "Iterator.h"
#include <cstddef>

template <typename T, typename P=T*>
class BackwardIterator : virtual public Iterator<T,P>{

public:


    BackwardIterator(){}
    BackwardIterator(const P& cursor):Iterator<T,P>(cursor){}
    BackwardIterator(const Iterator<T,P>& it):Iterator<T,P>(it){}

    BackwardIterator<T,P>&operator=(const Iterator<T,P>& o){
        Iterator<T,P>::operator=(o);
        return *this;
    }

    BackwardIterator<T,P>&operator--(){
        return *this -= 1;
    }

    BackwardIterator<T,P> operator--(int){
        BackwardIterator<T,P> it = *this;
         this->operator++();

         return it;
    }


    BackwardIterator<T,P>operator-(std::size_t mv) const{
        return BackwardIterator<T,P>(BackwardIterator<T,P>::getCursor()-mv);
    }


    BackwardIterator<T,P>&operator-=(std::size_t mv){
        return *this = *this - mv;
    }

};

#endif //TI_BACKWARDITERATOR_H
