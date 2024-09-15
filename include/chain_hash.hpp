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
        singly_linked_list<mapping<T, U>>* getArrayPointer();
        int getCapacity();

        class Iterator {
            private:
                singly_linked_list<mapping<T, U>>* array_; 
                int capacity_; 
                int index_; 

            public:
                // typedefs to define iterator traits
                using value_type = singly_linked_list<mapping<T,U>>;
                using difference_type = std::ptrdiff_t;
                using pointer = singly_linked_list<mapping<T,U>>*;
                using reference = singly_linked_list<mapping<T,U>>&;
                using iterator_category = std::forward_iterator_tag;

                // constructor for iterator
                Iterator(singly_linked_list<mapping<T, U>>* array, int capacity, int index)
                : array_(array), capacity_(capacity), index_(index) {}

                // dereference operator to access linked list at each index of array
                reference operator*() {
                    return array_[index_];
                }

                // pre-incrememnt operator to move to the next index of array
                Iterator& operator++() {
                    ++index_;
                    return *this;
                }

                // two iterators are equal if they point to the same array index
                bool operator==(const Iterator& other) const {
                    return index_ == other.index_;
                }

                // two iterators are not equal if they point to different array index
                bool operator!=(const Iterator& other) const {
                    return index_ != other.index_;
                }
        
        };

        // return iterator whose index is the start of the array
        Iterator begin() {
            return Iterator(array, capacity, 0);
        }

        // return iterator whose index is past the end of the array
        Iterator end() {
            return Iterator(array, capacity, capacity);
        }
};


int hash_char(char key, int capacity);
int hash_str(std::string key, int capacity);
int hash_int(int key, int capacity);

#include "chain_hash.tpp"

#endif // CHAIN_HASH_HPP