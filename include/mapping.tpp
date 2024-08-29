#include "mapping.hpp"

template <typename T, typename U>
mapping<T, U>::mapping(T key, U value) : key(key), value(value) {};

template <typename T, typename U>
void mapping<T, U>::setValue(U value) {
    this->value = value;
}

template <typename T, typename U>
U mapping<T, U>::getValue() {
    return value;
}

template <typename T, typename U>
T mapping<T, U>::getKey() {
    return key;
}