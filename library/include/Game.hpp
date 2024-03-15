#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <memory>

namespace Game {

// Definitions written below Game class
struct Date;                
enum class Platform;


/**
 * Game
 * Description: Plain old datatypes, contains a name, release date, brief description, and platform.
 * Notes:
 *      - Unsure if each platform release will have it's own Game object, or if a game object can have an array/list of platforms
*/

class Game {
public:
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

    Game(std::string gameName, Date releaseDate,
         std::string description, Platform releasePlatform, std::string fileName);
    Game(std::string path);
    ~Game();
    
    // Should never create copies of Games
    Game(Game& other) = delete;
    Game(const Game& other) = delete;
    Game& operator=(const Game& rhs) = delete;

    Game(Game&& other) noexcept;
    Game& operator=(Game&& rhs) noexcept;

    // ACCESSORS
    std::string getGameName() const;
    Date getReleaseDate() const;
    std::string getDescription() const;
    Platform getReleasePlatform() const;
    std::string getPath() const;
    std::string platformToString() const;

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;


};


struct Date {
    int year;
    enum class Month {
        JAN = 1,
        FEB,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUG,
        SEP,
        OCT,
        NOV,
        DEC
    }month;
    int day;

    Date(int year, Month month, int day)
    : year(year), month(month), day(day)
    {}

    bool operator==(const Date& rhs) {
        return  rhs.year  == year  &&
                rhs.month == month &&
                rhs.day   == day;
    }
};

/**
 * Currently using the EmuDeck wiki CheatSheet https://github.com/dragoonDorise/EmuDeck/wiki/Cheat-Sheet
 * May return to reorganize or pare down to rescope project. Not comprehensive list of every system ever released.
*/
enum class Platform {
// Unspecefied
    _NONE,

// Arcade and MAME
    _FBNEO,
    _MAME2003,
    _MAME2010,
    _ARCADE,
    _NGP,
    _CDIMONO1,

// Atari
    _ATARI2600,
    _LYNX,

// Game Engine Recreations
    _DOOM,
    _EASYRPG,
    _PICO8,
    _SCUMMVM,

// Microsoft
    _XBOX,
    _XBOX360_ROMS,
    _XBOX360_ROMS_XBLA,

// Miscellaneous
    _3D0,
    _TG16,
    _PCENGINE,  // ROMs can be in either directory
    _TGCD,
    _PCENGINECD,
    _WONDERSWAN,

// Nintendo
    _3DS,
    _N3DS,
    _N64,
    _N64DD,
    _NDS,
    _GB,
    _GBA,
    _GBC,
    _GC,
    _GAMECUBE,
    _NES,
    _FAMICOM,
    _SNES,
    _SNESNA,
    _SNESHD,
    _PRIMEHACKS,
    _SWITCH,
    _WII,
    _WIIU_ROMS,

// PC
    _AMIGA,
    _AMIGA600,
    _AMIGA1200,
    _AMIGACD32,
    _AMSTRADCPC,
    _C16,
    _C64,
    _VIC20,
    _DOS,
    _PC98,
    _X68000,
    _ZXSPECTRUM,

// Sega
    _SEGA32X,
    _SEGACD,
    _MEGACD,
    _DREAMCAST,
    _GAMEGEAR,
    _GENESIS,
    _MEGADRIVE,
    _GENESISWIDE,
    _MASTERSYSTEM,
    _SATURN,

// Sony
    _PSX,
    _PS2,
    _PS3,
    _PSP,
    _PSVITA,

// Other launchers
    _STEAM,
    _EPIC
};

static std::unordered_map<std::string, Platform> strToPlatform = 
{
// Arcade and MAME
    {"fbneo", Platform::_FBNEO},
    {"mame2003", Platform::_MAME2003},
    {"mame2010", Platform::_MAME2010},
    {"arcade", Platform::_ARCADE},
    {"ngp", Platform::_NGP},
    {"cdimono1", Platform::_CDIMONO1},

// Atari
    {"atari2600", Platform::_ATARI2600},
    {"lynx", Platform::_LYNX},

// Game Engine Recreations
    {"doom", Platform::_DOOM},
    {"easyrpg", Platform::_EASYRPG},
    {"pico8", Platform::_PICO8},
    {"scummvn", Platform::_SCUMMVM},

// Microsoft
    {"xbox", Platform::_XBOX},
    {"xbox360/roms", Platform::_XBOX360_ROMS},
    {"xbox360/roms/xbla", _XBOX360_ROMS_XBLA},

// Miscellaneous
    {"3do", Platform::_3D0},
    {"tg16", Platform::_TG16},
    {"pcengine", Platform::_PCENGINE},
    {"tg-cd", Platform::_TGCD},
    {"pcengingecd", Platform_PCENGINECD},
    {"wonderswan", Platform::_WONDERSWAN},

// Nintendo
    {"3ds", Platform::_3DS},
    {"n3ds", Platform::_N3DS},
    {"n64", Platform::_N64},
    {"n64dd", Platform::_N64DD},
    {"nds", Platform::_NDS},
    {"gb", Platform::_GB},
    {"gba", Platform::_GBA},
    {"gbc", Platform::_GBC},
    {"gc", Platform::_GC},
    {"gamecube", Platform::_GAMECUBE},
    {"nes", Platform::_NES},
    {"famicom", Platform::_FAMICOM},
    {"snes", Platform::_SNES},
    {"snesna", Platform::_SNESNA},
    {"sneshd", Platform::_SNESHD},
    {"primehacks", Platform::_PRIMEHACKS},
    {"switch", Platform::_SWITCH},
    {"wii", Platform::_WII},
    {"wiiu/roms", Platform::_WIIU_ROMS},

// PC
    {"amiga", Platform::_AMIGA},
    {"amiga600", Platform::_AMIGA600},
    {"amiga1200", Platform::_AMIGA1200},
    {"amigacd32", Platform::_AMIGACD32},
    {"amstradcpc", Platform::_AMSTRADCPC},
    {"c16", Platform::_C16},
    {"c64", Platform::_C64},
    {"vic20", Platform::_VIC20},
    {"dos", Platform::DOS},
    {"pc98", Platform::_PC98},
    {"x68000", Platform::_X68000},
    {"zxspectrum", Platform::_ZXSPECTRUM},

// Sega
    {"sega32x", Platform::_SEGA32X},
    {"segacd", Platform::_SEGACD},
    {"megacd", Platform::_MEGACD},
    {"dreamcast", Platform::_DREAMCAST},
    {"gamegear", Platform::_GAMEGEAR},
    {"genesis", Platform::_GENESIS},
    {"megadrive", Platform::_MEGADRIVE},
    {"genesiswide", Platform::_GENESISWIDE},
    {"mastersystem", Platform::_MASTERSYSTEM},
    {"saturn", Platform::_SATURN},

// Sony
    {"psx", Platform::_PSX},
    {"ps2", Platform::_PS2},
    {"ps3", Platform::_PS3},
    {"psp", Platform::_PSP},
    {"psvita", Platform::_PSVITA},

}

static struct PrintFormat {
    const int NAME_WIDTH        = 30;
    const int PLATFORM_WIDTH    = 20;
    const int DATE_WIDTH        = 12;
    const int DESCR_WIDTH       = 50;
}f;

} // end namespace Game

#endif // GAM_HPP