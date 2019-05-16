#ifndef TI_ITERATOR_H
#define TI_ITERATOR_H


template <class T,class P=T*>
class Iterator{
private:
    P cursor;

protected:

    P getCursor() const{
        return cursor;
    }

    void setCursor(const P& cursor){
        this->cursor = cursor;
    }

public:

    Iterator(){}
    Iterator(const P& cursor):cursor(cursor) {}
    Iterator(const Iterator& it):cursor(it.getCursor()) {}

    Iterator<T,P>&operator=(const Iterator<T,P> it){
        setCursor(it.getCursor());
        return *this;
    }


    bool operator==(const Iterator<T,P>& other) const{
        return (other.getCursor() == getCursor());
    }

    bool operator!=(const Iterator<T,P>& other) const{
        return !(*this == other);
    }

    T& get() const{
      return *getCursor();
    }

    T&operator*() const{
        return get();
    }


};
#endif //TI_ITERATOR_H
