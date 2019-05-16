#ifndef TI_FORWARDITERABLE_H
#define TI_FORWARDITERABLE_H

template <typename It /*Extends ForwardIterator?*/>
class Iterable {
public:

    virtual It begin() =0;

    virtual It end() =0;

    virtual It last() = 0;

};
#endif //TI_FORWARDITERABLE_H
