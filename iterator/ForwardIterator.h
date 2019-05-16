#ifndef TI_FORWARDITERATOR_H
#define TI_FORWARDITERATOR_H

#include "Iterator.h"
#include <cstddef>

template <typename T, typename P=T*>
class ForwardIterator : virtual public Iterator<T,P>{

public:

    ForwardIterator(){}
    ForwardIterator(const P& cursor):Iterator<T,P>(cursor){}
    ForwardIterator(const Iterator<T,P>& it):Iterator<T,P>(it){}

    ForwardIterator<T,P>&operator=(const Iterator<T,P>& o){
        Iterator<T,P>::operator=(o);
        return *this;
    }

    ForwardIterator<T,P>&operator++(){
        return *this +=1;
    }
     ForwardIterator<T,P> operator++(int){
        ForwardIterator<T,P> it = *this;
         this->operator++();

         return it;
    }

    ForwardIterator<T,P>operator+(std::size_t mv) const{
        return ForwardIterator<T,P>(ForwardIterator<T,P>::getCursor()+mv);
    }


    ForwardIterator<T,P>&operator+=(std::size_t mv){
        return *this = *this +mv;
    }

};

#endif //TI_FORWARDITERATOR_H
