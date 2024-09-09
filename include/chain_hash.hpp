#ifndef CHAIN_HASH_HPP
#define CHAIN_HASH_HPP

#include "mapping.hpp"
#include "linked_lists/single_linked_list.hpp"

bool is_prime(int n);
int next_double_prime(int n);

template <typename T, typename U>
class chainHash {

    private:
        singly_linked_list<mapping<T, U>> array[2];
        int capacity = 2;
        int current_size = 0;

    public:
        chainHash();
        int hash(T key);
        void rehash();
        U getValue(T key);
        void put(mapping<T,U> mapping);
        void remove(T key);
        bool search(T key);
        void print();

};

int hash_char(char key, int capacity);
int hash_str(std::string key, int capacity);
int hash_int(int key, int capacity);

#include "chain_hash.tpp"

#endif // CHAIN_HASH_HPP