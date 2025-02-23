#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

void word_frequency(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        ++freq[word];
    }

    std::cout << "Fréquence des mots :" << std::endl;
    for (const auto& pair : freq) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Entrez une phrase : ";
    std::getline(std::cin, input);

    word_frequency(input);

    return 0;
}
