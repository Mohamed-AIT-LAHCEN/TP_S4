#include <iostream>
#include <string>
#include <map>
#include <sstream>

void sort_by_length(const std::string& text) {
    std::multimap<int, std::string> word_map;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        word_map.insert({word.length(), word});
    }

    std::cout << "Trie par longueur : ";
    for (const auto& pair : word_map) {
        std::cout << pair.second << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string input;
    std::cout << "Phrase : ";
    std::getline(std::cin, input);

    sort_by_length(input);

    return 0;
}
