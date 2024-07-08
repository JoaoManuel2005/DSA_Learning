#include <single_linked_list.h>
#include <single_linked_node.h>

int main() {

    singly_linked_list list;
    list.initialize();
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.remove(3);
    list.remove(2);
    list.print_list();
    list.insert(9, 6);
    list.remove(15);
    list.print_list();
}