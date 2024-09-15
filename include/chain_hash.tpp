#include "chain_hash.hpp"
#include <iostream>
#include <string>
#include <functional>
#include <type_traits>

/**
 * Helper function to determine if number is prime
*/
bool is_prime(int n) {
    for (int i = 0; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * Helper function
 * @return next number greater than 2*n which is prime
*/
int next_double_prime(int n) {
    int candidate = n * 2;
    bool found = false;
    while (!found) {
        if (is_prime(candidate)) {
            found = true;
        }
        else {
            candidate++;
        }
    }
    return candidate;
}

/**
 * Constructor for hashmap
*/
template <typename T, typename U>
chainHash<T,U>::chainHash() {}

/**
 * Hash function
 * @param key key of mapping we want to add to the hashmap
 * @return integer hashing of the key of mapping we want to add
*/
template <typename T, typename U>
int chainHash<T,U>::hash(T key) {
    if constexpr (std::is_same<T, char>::value) {
        return hash_char(key, capacity);
    } 
    else if constexpr (std::is_same<T, std::string>::value) {
        return hash_str(key, capacity);
    } 
    else if constexpr (std::is_same<T, int>::value) {
        return hash_int(key, capacity);
    }   
    else {
        return std::hash<T>()(key) % capacity;
    } 
}

/**
 * Rehashing function
 * @brief Takes old hashmap. Increases its size to next prime double the size of its current size
 * Then recalculates the hashing of the mappings already in the hashmap according to the new size
*/
template <typename T, typename U>
void chainHash<T,U>::rehash() {
    int old_capacity = capacity;
    capacity = next_double_prime(capacity);
    singly_linked_list<mapping<T, U>> newArray[capacity];
    singly_linked_list<mapping<T, U>>oldArray[old_capacity] = array;
    array = newArray;
    for (int i = 0; i < old_capacity; i++) {
        node<mapping<T,U>>* current = oldArray[i].get_header_node();
        while (current != nullptr) {
            put(current->getValue());
            current = current->getNext();
        }
    }
}

/**
 * Getter for values of mappings in hashmap
 * @param key of mapping whose value we want to get
 * @brief Access linked list of mappings which corresponds to hash of key parameter
 * Iterates through this linked list until we find the key. then returns its value
 * @return value of mapping corresponding to key parameter passed
*/
template <typename T, typename U>
U chainHash<T,U>::getValue(T key) {
    int index = hash(key);
    node<mapping<T,U>>* current = array[index].get_header_node();
    while (current != nullptr) {
        if (key == current->getValue().getKey()) {
            return current->getValue().getValue();
        }
        else {
            current = current->getNext();
        }
    }
    throw std::runtime_error("Key not found");
}

/**
 * Adds mappings to hashmap
 * @param mapping we want to add to the hashmap
 * @brief calculates hash corresponding to mappings key
 * pushes mapping to the underlying linked list corresponding to the hash
*/
template <typename T, typename U>
void chainHash<T,U>::put(mapping<T, U> mapping) {
    T key = mapping.getKey();
    int index = hash(key);
    array[index].push(mapping);
    current_size++;

}

/**
 * Removes mappings from hashmap
 * @param key of mapping we want to remove
 * @brief calculates hash corresponding to mappings key
 * removes mapping from the underlying linked list corresponding to the hash
 * uses linked lists remove function 
*/
template <typename T, typename U>
void chainHash<T,U>::remove(T key) {
    if (!search(key)) {
        return;
    }
    U value = getValue(key);
    int index = hash(key);
    array[index].remove(mapping<T,U>(key, value));
}

/**
 * Searcher for mappings in hashmap
 * @param key of mapping were searching for
 * @brief Access linked list of mappings which corresponds to hash of key parameter
 * Iterates through this linked list until we find the key of the mapping or not
 * @return true if we found mapping, else false
*/
template <typename T, typename U>
bool chainHash<T,U>::search(T key) {
    int index = hash(key);
    node<mapping<T,U>>* current = array[index].get_header_node();
    while (current != nullptr) {
        if (key == current->getValue().getKey()) {
            return true;
        }
        else {
            current = current->getNext();
        }
    }
    return false;
}

/**
 * Prints key and value pair of every mapping in hashmap
 * @brief Iterates through underlying array 
 * for each iteration iterates through linked list at each arrray index 
 * printing key and values of mappings in linked list
*/
template <typename T, typename U>
void chainHash<T,U>::print() {
    for (int i = 0; i < capacity; i++) {
        if (array[i].get_length() > 0) {
            node<mapping<T,U>>* current = array[i].get_header_node();
            while (current != nullptr) {
                std::cout << "Key: " << current->getValue().getKey() << " Value: " << current->getValue().getValue() << std::endl;
                current = current->getNext();
            }
        }
    }
}

/**
 * Getter for underlying array
*/
template <typename T, typename U>
singly_linked_list<mapping<T, U>>* chainHash<T,U>::getArrayPointer() {
    return array;
}

/**
 * Getter for hashmap capacity
*/
template <typename T, typename U>
int chainHash<T,U>::getCapacity() {
    return capacity;
}

/**
 * Hash function for char data type
 * @param key key of mapping we want to add to the hashmap
 * @return integer hashing of the key of mapping we want to add
*/
int hash_char(char key, int capacity) {
    int index = static_cast<int>(key);
    return index % capacity;
}
/**
 * Hash function for string data type
 * @brief hashes each char in string and adds them up
 * @param key key of mapping we want to add to the hashmap
 * @return integer hashing of the key of mapping we want to add
*/
int hash_str(std::string key, int capacity) {
    int index = 0;
    for (char ch : key) {
        index += static_cast<int>(ch);
    }
    return index % capacity;
}

/**
 * Hash function for int data type
 * @param key key of mapping we want to add to the hashmap
 * @return integer hashing of the key of mapping we want to add
*/
int hash_int(int key, int capacity) {
    return key % capacity;
}