#include "chain_hash.hpp"
#include <iostream>
#include <string>
#include <functional>
#include <type_traits>

bool is_prime(int n) {
    for (int i = 0; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

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

template <typename T, typename U>
chainHash<T,U>::chainHash() {}

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

template <typename T, typename U>
void chainHash<T,U>::put(mapping<T, U> mapping) {
    T key = mapping.getKey();
    int index = hash(key);
    array[index].push(mapping);
    current_size++;

}

template <typename T, typename U>
void chainHash<T,U>::remove(T key) {
    if (!search(key)) {
        return;
    }
    U value = getValue(key);
    int index = hash(key);
    array[index].remove(mapping<T,U>(key, value));
}

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

template <typename T, typename U>
singly_linked_list<mapping<T, U>>* chainHash<T,U>::getArrayPointer() {
    return array;
}

template <typename T, typename U>
int chainHash<T,U>::getCapacity() {
    return capacity;
}

int hash_char(char key, int capacity) {
    int index = static_cast<int>(key);
    return index % capacity;
}

int hash_str(std::string key, int capacity) {
    int index = 0;
    for (char ch : key) {
        index += static_cast<int>(ch);
    }
    return index % capacity;
}

int hash_int(int key, int capacity) {
    return key % capacity;
}