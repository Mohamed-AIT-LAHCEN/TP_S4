#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& text) {
    std::string cleaned_text;
    for (char ch : text) {
        if (!std::isspace(ch)) {
            cleaned_text += std::tolower(ch);
        }
    }
    std::string reversed_text = cleaned_text;
    std::reverse(reversed_text.begin(), reversed_text.end());
    return cleaned_text == reversed_text;
}

int main() {
    std::string input;
    std::cout << "Entrez un mot : ";
    std::getline(std::cin, input);

    if (is_palindrome(input)) {
        std::cout << "\"" << input << "\" est un palindrome." << std::endl;
    } else {
        std::cout << "\"" << input << "\" n'est pas un palindrome." << std::endl;
    }

    return 0;
}
