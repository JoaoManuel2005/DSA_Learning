#include "btree.hpp"
#include "mapping.hpp"

// Explicitly instantiate the template with specific map node type
template class BinaryTree<mapping<char, int>>;