#include "Fileread.h"

int main(int argc, char *argv[]) {
    filereader a(argv[1]);
    a.ReadFile();
    std::cin.get();
    return 0;
}
