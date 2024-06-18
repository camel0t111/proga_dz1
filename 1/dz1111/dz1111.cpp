#include <iostream>
#include <fstream>
#include <string>

void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream inFile1(file1);
    std::ifstream inFile2(file2);

    if (!inFile1.is_open() || !inFile2.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    std::string line1, line2;
    int lineNumber = 1;
    while (std::getline(inFile1, line1) && std::getline(inFile2, line2)) {
        if (line1 != line2) {
            std::cout << "Line " << lineNumber << " does not match:" << std::endl;
            std::cout << "File 1: " << line1 << std::endl;
            std::cout << "File 2: " << line2 << std::endl;
        }
        lineNumber++;
    }

    inFile1.close();
    inFile2.close();
}

int main() {
    std::string file1 = "file1.txt";
    std::string file2 = "file2.txt";
    compareFiles(file1, file2);
    return 0;
}
