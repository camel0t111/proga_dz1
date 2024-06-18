#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void generateStatistics(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    std::string line;
    while (std::getline(inFile, line)) {
        lineCount++;
        for (char c : line) {
            charCount++;
            if (std::isdigit(c)) {
                digitCount++;
            }
            else if (std::isalpha(c)) {
                c = std::tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowelCount++;
                }
                else {
                    consonantCount++;
                }
            }
        }
    }

    outFile << "Number of characters: " << charCount << std::endl;
    outFile << "Number of lines: " << lineCount << std::endl;
    outFile << "Number of vowels: " << vowelCount << std::endl;
    outFile << "Number of consonants: " << consonantCount << std::endl;
    outFile << "Number of digits: " << digitCount << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";
    generateStatistics(inputFile, outputFile);
    return 0;
}
