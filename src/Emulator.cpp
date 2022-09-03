#include <iostream>
#include "Cartridge.h"

int run_emulator() {
    char * path = "/home/junior1407/YetAnotherGameBoyEmu/tetris.gb";
    auto * cartridge = new Cartridge(path);
    cartridge->parseMetadata();
    return 0;
}
