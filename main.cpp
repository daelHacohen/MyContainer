//dael12345@gmail.com
#include "MyContainer.hpp"
#include <iostream>
#include <string>
using namespace dael_containers;

int main() {

//--------------example for container-----------------------------
//----------------String----------------------------------------
     std::cout << "--------containerString------------\n";
    MyContainer<std::string> containerString;
    containerString.add("dael");
    containerString.add("shirelle");
    containerString.add("dael");

    std::cout << "Before remove: " << containerString << "\n";
    std::cout << "size of the container: " << containerString.size() << "\n";
    containerString.remove("dael");
    std::cout << "After remove: " << containerString << "\n";
    std::cout << "size of the container: " << containerString.size() << "\n";

    try {
        containerString.remove("raz");  // Will throw
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

//----------------double----------------------------------------
    MyContainer<double> containerdouble;
    containerdouble.add(5.5);
    containerdouble.add(3.1);
    containerdouble.add(5.5);

    std::cout << "\n----------containerdouble----------------\n";
    std::cout << "Before remove: " << containerdouble << "\n";
    std::cout << "size of the container: " << containerdouble.size() << "\n";
    containerdouble.remove(5.5);
    std::cout << "After remove: " << containerdouble << "\n";
    std::cout << "size of the container: " << containerdouble.size() << "\n";

    try {
        containerdouble.remove(100.1234);  // Will throw
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

//----------------int----------------------------------------
    MyContainer<> containerInt;
    containerInt.add(5);
    containerInt.add(3);
    containerInt.add(5);

    std::cout << "\n----------containerInt----------------\n";
    std::cout << "Before remove: " << containerInt << "\n";
    std::cout << "size of the container: " << containerInt.size() << "\n";
    containerInt.remove(5);
    std::cout << "After remove: " << containerInt << "\n";
    std::cout << "size of the container: " << containerInt.size() << "\n";

    try {
        containerInt.remove(100);  // Will throw
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

//--------------example for Ascending iterator-----------------------
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

//-----------------AscendingOrder-----------------------------------
    std::cout << "\n----------AscendingOrder Iterator----------------\n";
    std::cout << "\nwithout iterator: " << c << "\n";
    std::cout << "Ascending: ";
    for (auto it = c.beginAscending(); it != c.endAscending(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";

//------------------DescendingOrder-----------------------------------
    std::cout << "\n----------DescendingOrder Iterator----------------\n";
    std::cout << "\nwithout iterator: " << c << "\n";
    std::cout << "Descending: ";
    for (auto it = c.beginDescending(); it != c.endDescending(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";

//------------------SideCrossOrder-----------------------------------
    std::cout << "\n----------SideCrossOrder Iterator----------------\n";
    std::cout << "\nwithout iterator: " << c << "\n";
    std::cout << "SideCross: ";
    for (auto it = c.beginSideCross(); it != c.endSideCross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";

//-------------------ReverseOrder-----------------------------------
    std::cout << "\n----------ReverseOrder Iterator----------------\n";
    std::cout << "\nwithout iterator: " << c << "\n";
    std::cout << "ReverseOrder: ";
    for (auto it = c.beginReverse(); it != c.endReverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";    

//------------------------Order-----------------------------------
    std::cout << "\n----------Order Iterator----------------\n";
    std::cout << "\nwithout iterator: " << c << "\n";
    std::cout << "Order: ";
    for (auto it = c.beginOrder(); it != c.endOrder(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";   
    
//------------------------MiddleOutOrder-----------------------------------
    std::cout << "\n----------MiddleOutOrder Iterator----------------\n";
    std::cout << "\nwithout iterator: " << c << "\n";
    std::cout << "MiddleOutOrder: ";
    for (auto it = c.beginMiddleOut(); it != c.endMiddleOut(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<"\n";     

    return 0;
}
