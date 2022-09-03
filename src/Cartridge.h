//
// Created by junior1407 on 31/08/22.
//

#ifndef YETANOTHERGBEMU_CARTRIDGE_H
#define YETANOTHERGBEMU_CARTRIDGE_H


#include "Definitions.h"

class Cartridge {
public:
    enum CartridgeTypes
    {
        CartridgeNoMBC,
        CartridgeMBC1,
        CartridgeMBC2,
        CartridgeMBC3,
        CartridgeMBC5,
        CartridgeMBC1Multi,
        CartridgeNotSupported
    };
    Cartridge(char * path);
    void parseMetadata();
    enum BackwardsCompatibility {
        BACKWARDS_COMPATIBLE_CGB,
        CGB_ONLY,
        OTHER
    };
    static const u8 BACKWARDS_COMPATIBLE_CGB_FLAG = 0x80;
    static const u8 CGB_ONLY_FLAG = 0xC0;
    static const int GAME_NAME_START_POS = 0x134;
    static const int GAME_NAME_END_POS = 0x142;
private:
    char mPath[512];
    u8 * mRawRom;
    int mRomFileSize;
    //Metadata
    char mGameName[15];
    bool mNintendoLogPresent;
    BackwardsCompatibility mBackWardsCompatibility;
    bool mSuperGameBoy;
    void storeRawRom();

    CartridgeTypes identifyCartridgeType(u8 i);

    CartridgeTypes mCartridgeType;
    u8 mRomSize;
    u8 mRamSize;
    u8 mMaskRomVersion;
};


#endif //YETANOTHERGBEMU_CARTRIDGE_H
