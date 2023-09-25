#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map with string keys and int values
    std::unordered_map<std::string, int> myMap;

    // Insert key-value pairs
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 22;

    // Access values using keys
    std::cout << "Alice's age is " << myMap["Alice"] << " years." << std::endl;

    // Check if a key exists
    if (myMap.find("David") != myMap.end()) {
        std::cout << "David's age is " << myMap["David"] << " years." << std::endl;
    }
    else {
        std::cout << "David's age is not in the map." << std::endl;
    }

    // Iterate through the map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " years" << std::endl;
    }

    return 0;
}
