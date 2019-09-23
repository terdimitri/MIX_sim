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

struct Field {
    unsigned char start;
    unsigned char stop;
    bool has_sign;
};

Field fromF(unsigned char F) {
    // Knuth's Word |1|2|3|4|5|
    // My Word      |4|3|2|1|0|
    Field out;
    out.start = 5 - F % 8;
    unsigned char stop = 5 - F / 8;
    if (stop == 5) {
        out.has_sign = true;
        stop = 4;
    }
    out.stop = stop;
    return out;
}

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

    Field field;
    int r_num;
    int i, j;

    while (pointer > MEM_SIZE) {
        break;
        C = memory[pointer].bytes[4];
        F = memory[pointer].bytes[3];
        I = memory[pointer].bytes[2];
        M = (int) memory[pointer].bytes[0] << BYTE_SIZE + memory[pointer].bytes[1];
        if (memory[pointer].sign) {M *= -1;}

        if (I != 0) {
            M += interpret(rI[I-1]);
        }

        switch (C) {
            case 0:
                break;
            case 1:
                // add
                break;
            case 2:
                // sub
                break;
            case 3:
                // mul
                break;
            case 4:
                // div
                break;
            case 5:
                if (F == 0) {
                    // num
                } else if (F == 1) {
                    // char
                } else if (F == 2) {
                    // hlt
                }
                break;
            case 6:
                // shifts
                break;
            case 7:
                // move
                break;
            case 32:
                // STJ
                break;
            case 33:
                // STZ
                break;
            case 34:
                // JBUS
                break;
            case 35:
                // IOC
                break;
            case 36:
                // IN
                break;
            case 37:
                // OUT
                break;
            case 38:
                // JRED
                break;
            case 39:
                // J[*]
                break;
            default:
                r_num = C % 8;
                if (8 <= C && C <= 23) {
                    // Load
                    for ()
                } else if (24 <= C && C <= 31) {
                    // Store
                } else if (40 <= C && C <= 32) {
                    // Jump
                } else if (48 <= C && C <= 55) {
                    // Inc and Ent
                } else if (56 <= C && C <= 63) {
                    // Compare
                }
                break;
        }
    }
    
    Field f = fromF(13);
    std::cout << "start: " << (int) f.start << "\nstop: " << (int) f.stop << "\nsign: " << f.has_sign << "\n";

    memory[0].bytes[2] = 1;
    rA = memory[0];
    memory[0] = {{12, 1, 0, 0, 0}, true};
    std::cout << "memory 0: " << interpret(memory[0]) << "\n";
    std::cout << "register A: " << interpret(rA) << "\n";
    return 0;
}
