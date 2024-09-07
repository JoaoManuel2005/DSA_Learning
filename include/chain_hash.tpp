#include "chain_hash.hpp"
#include <string>
#include <functional>

template <typename T, typename U>
chainHash<T,U>::chainHash() {}

template <typename T, typename U>
int chainHash<T,U>::hash(T key) {
    return std::hash<T>()(key) % capacity;
}

template <typename T, typenameU>
int chainHash<char, U>::hash(char key) {
    int index = static_cast<int>(key);
    return index % capacity;
}+

template <typename T, typenameU>
int chainHash<std::string, U>::hash(std::string key) {
    int index = 0;
    for (char ch : key) {
        index += static_cast<int>(ch);
    }
    return index % capacity;
}

template <typename T, typenameU>
int chainHash<int, U>::hash(int key) {
    return key % capacity;
}

template <typename T, typename U>
void chainHash<T,U>::rehash() {
    
}

template <typename T, typename U>
U chainHash<T,U>::getValue(T key) {
    int index = hash(key);
    
}

template <typename T, typename U>
void chainHash<T,U>::put(mapping<T, U> mapping) {
    
}

template <typename T, typename U>
void chainHash<T,U>::remove(T key) {
    
}

template <typename T, typename U>
bool chainHash<T,U>::search() {
    
}

template <typename T, typename U>
void chainHash<T,U>::print() {
    
}