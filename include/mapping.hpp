#ifndef MAPPING_H
#define MAPPING_H

template <typename T, typename U>
class mapping {
    public:
        mapping(T key, U value);
        void setValue(U value);
        U getValue();
        T getKey();
    private:
        T key;
        U value;
};

#include "mapping.tpp"

#endif // MAPPING_H