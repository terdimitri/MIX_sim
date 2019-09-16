#include <iostream>

struct Word {
    unsigned char bytes[5];
    bool sign;
}

struct ShortWord {
    unsigned char bytes[2];
    bool sign;
}


int main() {
    if (1 << 4 > 15) {
        std::cout << "he is big\n";
    } else {
        std::cout << "he is not\n";
    }

    return 0;
}
