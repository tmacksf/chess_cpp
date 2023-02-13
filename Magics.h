//
// Created by Thomas Mack on 29/01/2023.
//

#ifndef CHESS_CPP_MAGICS_H
#define CHESS_CPP_MAGICS_H
#include "Bitboard.h"

class Magics {
public:
// magic bitboard information
    static BB rookMask[64];
    static BB bishopMask[64];
    static BB rookMagics[64];
    static BB bishopMagics[64];

    // attack tables
    static BB bishopAttacks[64][512];
    static BB rookAttacks[64][4096];

    static constexpr int rookBitCounts[] = {
            12, 11, 11, 11, 11, 11, 11, 12,
            11, 10, 10, 10, 10, 10, 10, 11,
            11, 10, 10, 10, 10, 10, 10, 11,
            11, 10, 10, 10, 10, 10, 10, 11,
            11, 10, 10, 10, 10, 10, 10, 11,
            11, 10, 10, 10, 10, 10, 10, 11,
            11, 10, 10, 10, 10, 10, 10, 11,
            12, 11, 11, 11, 11, 11, 11, 12,
    };

    static constexpr int bishopBitCounts[] = {
            6, 5, 5, 5, 5, 5, 5, 6,
            5, 5, 5, 5, 5, 5, 5, 5,
            5, 5, 7, 7, 7, 7, 5, 5,
            5, 5, 7, 9, 9, 7, 5, 5,
            5, 5, 7, 9, 9, 7, 5, 5,
            5, 5, 7, 7, 7, 7, 5, 5,
            5, 5, 5, 5, 5, 5, 5, 5,
            6, 5, 5, 5, 5, 5, 5, 6,
    };

    static constexpr BB preCalcRookMagics[] {
        0xa8002c000108020, 0x6c00049b0002001, 0x100200010090040, 0x2480041000800801, 0x280028004000800, 0x900410008040022, 0x280020001001080, 0x2880002041000080,
        0xa000800080400034, 0x4808020004000, 0x2290802004801000, 0x411000d00100020, 0x402800800040080, 0xb000401004208, 0x2409000100040200, 0x1002100004082,
        0x1080004000200040, 0x1090810021004010, 0x801030040200012, 0x500808008001000, 0xa08018014000880, 0x8000808004000200, 0x201008080010200, 0x4801200004100a4,
        0x800080204005, 0x1040200040100048, 0x120200402082, 0xd14880480100080, 0x800040080800800, 0x100040080020080, 0x9020010080800200, 0x813241200148449,
        0x491604001800080, 0x100401000402001, 0x4820010021001040, 0x400402202000812, 0x8010080101001004, 0x1103000209000400, 0x20100804000201, 0x1000008042001114,
        0x8042004100820026, 0x430022012424000, 0xca114086020022, 0x448402200120008, 0x42000408220010, 0x88020004008080, 0x1011000200010004, 0x4204182000d,
        0x443060980a84200, 0x800a00240008280, 0x100801022004200, 0x100008008080, 0x8000400801980, 0x2000810040200, 0x8010100228810400, 0x2000009044210200,
        0x4080008040102101, 0x40002080411d01, 0x2005524060000901, 0x502001008400422, 0x489a000810200402, 0x1004400080a13, 0x4000011008020084, 0x26002114058042,
    };

    static constexpr BB preCalcBishopMagics[] {
        0x821041012004010, 0x80104040c4000, 0x10040048400400, 0x182060c1000418, 0x6a12021040000000, 0x6011421000440, 0x104008484208212, 0x80240200842021,
        0x20490420040400b0, 0x6120102108010050, 0x880a404e0420, 0x80508a082000000, 0x50401104005260c, 0x10090042104c8, 0x50c01200811, 0x4a00900813,
        0x20000408026800, 0xc074001009020432, 0x1109000448100, 0x8010809802014010, 0x804000880a03002, 0x34808808090840, 0x8294843410845010, 0xc00400082080108,
        0x8a0880004902400, 0x8204100645010808, 0x880030802400, 0x5040040102021004, 0x1001001004000, 0x1440900c1300202, 0xc409404020700, 0x10208500820c4a04,
        0x808201205040410, 0x21088204205400, 0x800820101208800, 0x8080020082280080, 0x464280200002008, 0x2100440860804, 0x604912200424804, 0x1004080020a00,
        0x484116029001000, 0x9020491010002802, 0x511804004800, 0x208002024208800, 0x80104008040, 0x5024090041002204, 0xe204902220410210, 0x4050840100200040,
        0x3011080804842828, 0xc4228208a04000, 0x420020207140200, 0x8008412242020802, 0x10c000a002540020, 0x8011109002482640, 0x600401c2040100, 0x402025822008002,
        0x104404044040, 0x812102402421000, 0x8002008a44044401, 0x113101608420210, 0x2008530400, 0x1000902284200, 0x100298410c00, 0x89a1121896040240,
    };

// methods
public:
    static BB setOccupancy(int index, BB attackMask);

    static void initBishopMasks();
    static void initRookMasks();

    static BB randomBBFewBits();
    static BB randomBB();

    static BB rookAttacksOnTheFly(int square, BB blockers);
    static BB bishopAttacksOnTheFly(int square, BB blockers);

    static BB findRookMagic(int sq, int numBits);
    static BB findBishopMagic(int sq, int numBits);

    static void generateMagicNumbers();

    static void initBishopAttacks();
    static void initRookAttacks();
    static void generateSlidingAttackTables();

    static inline BB getRookAttacks(int square, BB blockers) {
        blockers &= rookMask[square];
        blockers *= preCalcRookMagics[square];
        blockers >>= 64 - rookBitCounts[square];
        return rookAttacks[square][blockers];
    }

    static inline BB getBishopAttacks(int square, BB blockers) {
        blockers &= bishopMask[square];
        blockers *= preCalcBishopMagics[square];
        blockers >>= 64 - bishopBitCounts[square];
        return bishopAttacks[square][blockers];
    }

    static inline BB getQueenAttacks(int square, BB blockers) {
        return getBishopAttacks(square, blockers) | getRookAttacks(square, blockers);
    }
};


#endif //CHESS_CPP_MAGICS_H
