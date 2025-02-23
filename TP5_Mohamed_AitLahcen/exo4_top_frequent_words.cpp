#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

void top_frequent_words(const std::string& text, int n) {
    std::unordered_map<std::string, int> freq;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        ++freq[word];
    }

    std::vector<std::pair<std::string, int>> sorted_words(freq.begin(), freq.end());
    std::sort(sorted_words.begin(), sorted_words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::cout << "Top " << n << " mots les plus frequents :" << std::endl;
    for (int i = 0; i < n && i < sorted_words.size(); ++i) {
        std::cout << i + 1 << ". " << sorted_words[i].first << " -> " << sorted_words[i].second << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Texte : ";
    std::getline(std::cin, input);

    top_frequent_words(input, 3);

    return 0;
}
