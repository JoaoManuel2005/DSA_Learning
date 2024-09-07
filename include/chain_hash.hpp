#ifndef CHAIN_HASH_HPP
#define CHAIN_HASH__HPP

#include "mapping.hpp"
#include "linked_lists/single_linked_list.hpp"

template <typename T, typename U>
class chainHash {

    private:
        singly_linked_list<mapping<T, U>> array[2];
        int capacity = 2;
        int current_size = 0;

    public:
        chainHash();
        int hash(T key);
        int hash(char key);
        int hash(std::string key);
        int hash(int key);
        void rehash();
        U getValue(T key);
        void put(mapping<T,U> mapping);
        void remove(T key);
        bool search();
        void print();

};

#include "chain_hash.tpp"

#endif // CHAIN_HASH_HPP