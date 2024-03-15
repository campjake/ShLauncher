#include "Game.hpp"

namespace Game {

/** Implementation for Game Member Variables
 * Used for Pointer to Implementation (pImpl),
 * which will manage this object for its lifetime
*/
struct Game::Impl {
    std::string name;           // Title of Game
    Date releaseDate;           // Date of Release
    int userRating;             // User's Rating (unset by default)
    std::string description;    // Brief description
    Platform releasePlatform;   // Platform/Version of Game
    std::string fileName;       // Absolute path to Game File


    Impl(std::string name, Date releaseDate,
        std::string description, Platform releasePlatform, 
        std::string fileName)
        :   name(name), releaseDate(releaseDate),
            description(description), releasePlatform(releasePlatform),
            fileName(fileName)
    {}

    Impl(std::string path) {
        
    }

    ~Impl(){}
};


/** Game Constructor (Full Details) 
 * Preconditions    : Must be constructed from predefined game
 * Postconditions   : Creates a game with valid state, no user rating.
*/
Game::Game(std::string gameName, Date releaseDate,
    std::string description, Platform releasePlatform, std::string fileName)
: pImpl(std::make_unique<Impl>( gameName, releaseDate, description,
                                releasePlatform, fileName))
{}

/** Game Constructor (Path Only) 
 * Preconditions    : File path must exist
 * Postconditions   : Creates a game with valid state.
*/
Game::Game(std::string path) 
: pImpl
{

}


Game::~Game(){}

/** getGameName
 * Preconditions    : N/A
 * Postconditions   : Returns a string that maps the the Game's name
*/
std::string Game::getGameName() const {
    return pImpl->name;
}

/** getReleaseDate
 * Preconditions    : N/A
 * Postconditions   : Returns a Date that maps the the Game's release Date
*/
Date Game::getReleaseDate() const {
    return pImpl->releaseDate;
}

/** getDescription
 * Preconditions    : N/A
 * Postconditions   : Returns a Date that maps the the Game's release Date
*/
std::string Game::getDescription() const {
    return pImpl->description;
}

/** getReleasePlatform
 * Preconditions    : N/A
 * Postconditions   : Returns a Platform that maps the the Game's Platform
*/
Platform Game::getReleasePlatform() const {
    return pImpl->releasePlatform;
}

/** getPath
 * Preconditions    : N/A
 * Postconditions   : Returns a string that maps the the Game's file path
*/
std::string Game::getPath() const {
    return pImpl->fileName;
}


/** platformToString
 * Preconditions    : N/A
 * Postconditions   : Returns a string that maps to the Game's platform
*/
std::string Game::platformToString() const{
    switch (pImpl->releasePlatform) {
        case Platform::_FBNEO:
            return "FBNeo";
        case Platform::_MAME2003:
            return "MAME 2003";
        case Platform::_MAME2010:
            return "MAME 2010";
        case Platform::_ARCADE:
            return "Arcade";
        case Platform::_NGP:
            return "Neo Geo Pocket";
        case Platform::_CDIMONO1:
            return "CDi Mono 1";
        case Platform::_ATARI2600:
            return "Atari2600";
        case Platform::_LYNX:
            return "Atari Lynx";
        case Platform::_DOOM:
            return "Game Engine - DOOM";
        case Platform::_EASYRPG:
            return "Game Engine - EasyRPG";
        case Platform::_PICO8:
            return "Game Engine - PICO-8";
        case Platform::_SCUMMVM:
            return "Game Engine - SCUMMVM";
        case Platform::_XBOX:
            return "Xbox";
        case Platform::_XBOX360_ROMS:
            return "Xbox 360";
        case Platform::_XBOX360_ROMS_XBLA:
            return "Xbox 360 (XBLA)";
        case Platform::_3D0:
            return "3DO";
        case Platform::_TG16:
            return "TurboGrafx-16";
        case Platform::_PCENGINE:
            return "PC Engine";
        case Platform::_TGCD:
            return "TurboGrafx-CD";
        case Platform::_PCENGINECD:
            return "PC Engine CD";
        case Platform::_WONDERSWAN:
            return "WonderSwan";
        case Platform::_3DS:
            return "3DS";
        case Platform::_N3DS:
            return "New 3DS";
        case Platform::_N64:
            return "Nintendo 64";
        case Platform::_N64DD:
            return "Nintendo 64DD";
        case Platform::_NDS:
            return "Nintendo DS";
        case Platform::_GB:
            return "Game Boy";
        case Platform::_GBA:
            return "Game Boy Advance";
        case Platform::_GBC:
            return "Game Boy Color";
        case Platform::_GC:
            return "GameCube";
        case Platform::_GAMECUBE:
            return "GameCube";
        case Platform::_NES:
            return "NES";
        case Platform::_FAMICOM:
            return "Famicom";
        case Platform::_SNES:
            return "SNES";
        case Platform::_SNESNA:
            return "SNES (NA)";
        case Platform::_SNESHD:
            return "SNES (HD)";
        case Platform::_PRIMEHACKS:
            return "PrimeHacks";
        case Platform::_SWITCH:
            return "Switch";
        case Platform::_WII:
            return "Wii";
        case Platform::_WIIU_ROMS:
            return "Wii U ROMs";
        case Platform::_AMIGA:
            return "Amiga";
        case Platform::_AMIGA600:
            return "Amiga 600";
        case Platform::_AMIGA1200:
            return "Amiga 1200";
        case Platform::_AMIGACD32:
            return "Amiga CD32";
        case Platform::_AMSTRACPC:
            return "Amstrad CPC";
        case Platform::_C16:
            return "Commodore 16";
        case Platform::_C64:
            return "Commodore 64";
        case Platform::_VIC20:
            return "VIC-20";
        case Platform::_DOS:
            return "DOS";
        case Platform::_PC98:
            return "PC-98";
        case Platform::_X86000:
            return "X68000";
        case Platform::_ZXSPECTRUM:
            return "ZX Spectrum";
        case Platform::_SEGA32X:
            return "32X";
        case Platform::_SEGACD:
            return "Sega CD";
        case Platform::_MEGACD:
            return "Mega CD";
        case Platform::_DREAMCAST:
            return "Dreamcast";
        case Platform::_GAMEGEAR:
            return "Game Gear";
        case Platform::_GENESIS:
            return "Genesis";
        case Platform::_MEGADRIVE:
            return "Mega Drive";
        case Platform::_GENESISWIDE:
            return "Genesis (Wide)";
        case Platform::_MASTERSYSTEM:
            return "Master System";
        case Platform::_SATURN:
            return "Saturn";
        case Platform::_PSX:
            return "PlayStation";
        case Platform::_PS2:
            return "PlayStation 2";
        case Platform::_PS3:
            return "PlayStation 3";
        case Platform::_PSP:
            return "PSP";
        case Platform::_PSVITA:
            return "PS Vita";
        default:
            return "Unknown Platform";
    }
}


std::ostream& operator<<(std::ostream& os, const Game& game) {
    const std::string platform = game.platformToString();
    os  << std::setw(f.NAME_WIDTH)     << std::left << game.pImpl->name
        << std::setw(f.PLATFORM_WIDTH) << std::left << platform
        << std::endl;
    return os;
}

} // end namespace Game