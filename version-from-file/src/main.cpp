#include <iostream>
#include <version.hpp>

int main() {
    std::cout << "MAJOR version: " << VERSION_MAJOR << "\n";
    std::cout << "MINOR version: " << VERSION_MINOR << '\n';
    std::cout << "PATCH version: " << VERSION_PATCH << '\n';
    std::cout << "Software version: " << VERSION << std::endl;
    return 0;
}