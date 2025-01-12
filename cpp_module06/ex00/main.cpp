#include "Convert.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "One parameter required" << std::endl;
        return 1;
    }
    
    Convert c(argv[1]);
    
    try {
        c.printOutput();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
