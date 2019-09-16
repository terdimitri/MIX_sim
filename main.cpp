#include <iostream>
#define BYTE_SIZE 6

struct Word {
    unsigned char bytes[5];
    bool sign;
};

struct ShortWord {
    unsigned char bytes[2];
    bool sign;
};

Word memory[4000];

long int interpret(Word word) {
    long int out = 0;
    int i = 0;
    for (int byte : word.bytes) {
        out += (long int) byte << (BYTE_SIZE*i);
        std::cout << out << "\n";
        i++;
    }
    if (word.sign) {out *= -1;}
    return out;
}

int main() {
    Word word = {{12, 1, 0, 0, 0}, true};
    std::cout << interpret(word) << "\n";
    return 0;
}
