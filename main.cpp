#include <iostream>
#define BYTE_SIZE 6
#define MEM_SIZE 4000

struct Word {
    unsigned char bytes[5];
    bool sign;
};

struct ShortWord {
    unsigned char bytes[2];
    bool sign;
};

enum CompState {GREATER, EQUAL, LESS};

long int interpret(Word word) {
    long int out = 0;
    int i = 0;
    for (int byte : word.bytes) {
        out += (long int) byte << (BYTE_SIZE*i);
        i++;
    }
    if (word.sign) {out *= -1;}
    return out;
}

long int interpret(ShortWord word) {
    long int out = 0;
    int i = 0;
    for (int byte : word.bytes) {
        out += (long int) byte << (BYTE_SIZE*i);
        i++;
    }
    if (word.sign) {out *= -1;}
    return out;
}

int main() {
    Word memory[MEM_SIZE];
    CompState comp_ind;
    bool overflow;
    Word rA;
    Word rX;
    ShortWord rI[6];
    ShortWord rJ;

    int pointer = 0;
    unsigned char C, I, F;
    int M;
    while (pointer > MEM_SIZE) {
        C = memory[pointer].bytes[4];
        F = memory[pointer].bytes[3];
        I = memory[pointer].bytes[2];
        M = memory[pointer].bytes[0] << BYTE_SIZE + memory[pointer].bytes[1];
        if (memory[pointer].sign) {M *= -1;}

        if (I != 0) {
            M += interpret(rI[I-1]);
        }
    }
    memory[0] = {{12, 1, 0, 0, 0}, true};
    std::cout << "memory 0: " << interpret(memory[0]) << "\n";
    std::cout << "rJ sign state: " << rJ.sign << "\n";
    return 0;
}
