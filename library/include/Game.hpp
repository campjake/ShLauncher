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
    _AMSTRACPC,
    _C16,
    _C64,
    _VIC20,
    _DOS,
    _PC98,
    _X86000,
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
};

static struct PrintFormat {
    const int NAME_WIDTH        = 30;
    const int PLATFORM_WIDTH    = 20;
    const int DATE_WIDTH        = 12;
    const int DESCR_WIDTH       = 50;
}f;

} // end namespace Game

#endif // GAM_HPP