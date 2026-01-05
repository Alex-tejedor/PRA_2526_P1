#include <iostream>
#include "ListArray.h"

int main() {
    ListArray<int> l;

    std::cout << "List => []" << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;
    std::cout << std::endl;

    l.append(10);
    l.prepend(5);
    l.insert(0, -5);
    l.insert(1, 0);

    std::cout << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "l.get(0) => " << l.get(0) << "; l[0] => " << l[0] << std::endl;
    std::cout << "l.get(3) => " << l.get(3) << "; l[3] => " << l[3] << std::endl;
    std::cout << std::endl;

    std::cout << "l.remove(3) => " << l.remove(3) << ": " << std::endl;
    std::cout << "l.remove(1) => " << l.remove(1) << ": " << std::endl;
    std::cout << "l.remove(0) => " << l.remove(0) << ": " << std::endl;
    std::cout << std::endl;

    std::cout << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;
    std::cout << std::endl;

    l.insert(0, 33);
    l.insert(2, 14);
    
    std::cout << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "l.search(14) => " << l.search(14) << std::endl;
    std::cout << "l.search(55) => " << l.search(55) << std::endl;

    try{
        l.insert(-1, 99);
    } catch(std::out_of_range &e){
        std::cout << "l.insert(-1, 99) => std::out_of_range: " << e.what() << std::endl;
    }

    try{
        l.insert(4, 99);
    } catch(std::out_of_range &e){
        std::cout << "l.insert(4, 99) => std::out_of_range: " << e.what() << std::endl;
    }

    try{
        l.get(-1);
    } catch(std::out_of_range &e){
        std::cout << "l.get(-1) => std::out_of_range: " << e.what() << std::endl;
    }

    try{
        l.get(3);
    } catch(std::out_of_range &e){
        std::cout << "l.get(3) => std::out_of_range: " << e.what() << std::endl;
    }

    try{
        l.remove(-1);
    } catch(std::out_of_range &e){
        std::cout << "l.remove(-1) => std::out_of_range: " << e.what() << std::endl;
    }

    try{
        l.remove(3);
    } catch(std::out_of_range &e){
        std::cout << "l.remove(3) => std::out_of_range: " << e.what() << std::endl;
    }
}
