#include "mapping.hpp"

/**
 * Constructor for mapping
*/
template <typename T, typename U>
mapping<T, U>::mapping(T key, U value) : key(key), value(value) {};

/**
 * Value setter for mapping
*/
template <typename T, typename U>
void mapping<T, U>::setValue(U value) {
    this->value = value;
}

/**
 * Value getter for mapping
*/
template <typename T, typename U>
U mapping<T, U>::getValue() {
    return value;
}

/**
 * Key getter for mapping
*/
template <typename T, typename U>
T mapping<T, U>::getKey() {
    return key;
}