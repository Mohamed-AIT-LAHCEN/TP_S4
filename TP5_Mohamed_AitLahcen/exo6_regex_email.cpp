#include <iostream>
#include <string>
#include <regex>

bool contains_email(const std::string& text) {
    std::regex email_regex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");
    std::smatch match;

    if (std::regex_search(text, match, email_regex)) {
        std::cout << "Adresse email détectée : " << match.str() << std::endl;
        return true;
    } else {
        std::cout << "Aucune adresse email détectée." << std::endl;
        return false;
    }
}

int main() {
    std::string input;
    std::cout << "Phrase : ";
    std::getline(std::cin, input);

    contains_email(input);

    return 0;
}
