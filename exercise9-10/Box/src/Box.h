#ifndef BOX_H
#define BOX_H

template <typename T>
class Box{
    T object;

public:
    Box(){}
    Box(const T& o){
        setObject(o);
    }
    Box(const Box& other){
        setObject(other);
    }

    operator const T&() const{
        return getObject();
    }

    operator T&(){
        return getObject();
    };

    Box& operator=(const T& object){
        setObject(object);
        return *this;
    }

    Box& operator=(const Box& h){
        setObject(h);
    }

    void setObject(const T& o){
        this->object = o;
    }

    T getObject() const{
        return getObject();
    }


    T& getObject(){
        return this->object;
    }

};

#endif
