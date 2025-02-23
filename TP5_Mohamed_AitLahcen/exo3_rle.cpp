#include <iostream>
#include <string>

std::string encode_rle(const std::string& text) {
    std::string encoded;
    int count = 1;

    for (size_t i = 0; i < text.length(); ++i) {
        if (i + 1 < text.length() && text[i] == text[i + 1]) {
            ++count;
        } else {
            encoded += text[i];
            encoded += std::to_string(count);
            count = 1;
        }
    }

    return encoded;
}

int main() {
    std::string input;
    std::cout << "Texte : ";
    std::getline(std::cin, input);

    std::string encoded = encode_rle(input);
    std::cout << "Encode : " << encoded << std::endl;

    return 0;
}
