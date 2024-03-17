#include "GameDir.hpp"

namespace fs = std::filesystem;

namespace GameDir {
struct GameDir::Impl {
    fs::path dirPath;
    std::vector<Game::Game> gameFiles;
    Game::Platform platform;
    
    Impl(const std::string& dirPath)
    : dirPath(dirPath)
    {
        
        for(const auto& file : fs::directory_iterator(dirPath)) {
            if(fs::is_regular_file(file)) {
                gameFiles.emplace_back(file.path());
            }
        }

        platform = gameFiles.at(0).getReleasePlatform();
    }

    Impl(const fs::path& dirPath)
    : dirPath(dirPath)
    {
        
        for(const auto& file : fs::directory_iterator(dirPath)) {
            if(fs::is_regular_file(file)) {
                gameFiles.emplace_back(file.path());
            }
        }

        platform = gameFiles.at(0).getReleasePlatform();
    }
};

/** GameDir Constructor (String Path)
 * Preconditions    : An std::string that matches the path
 * Postconditions   : Constructs a valid GameDir object
*/
GameDir::GameDir(const std::string& path) 
: pImpl(std::make_unique<Impl>(path))
{}

/** GameDir Constructor (Path Object)
 * Preconditions    : An std::filestream::path object
 * Postconditions   : Constructs a valid GameDir object
*/
GameDir::GameDir(const fs::path& path)
: pImpl(std::make_unique<Impl>(path))
{}

/** Default Destructor
 * Preconditions    : N/A
 * Postconditions   : Does nothing
*/
GameDir::~GameDir() = default;

/** GetGames
 * Preconditions    : N/A
 * Postconditions   : Returns a vector of Game objects
*/
const std::vector<Game::Game>& GameDir::getGames() const {
    return pImpl->gameFiles;
}

/** GetPlatform
 * Preconditions    : N/A
 * Postconditions   : Returns Platform enum
*/
Game::Platform GameDir::getPlatform() const {
    return pImpl->platform;
}

/** Operator<< Overload
 * Preconditions    : An ostream object, and a GameDir object
 * Postconditions   : Reutrns an ostream object for the caller to use
*/
std::ostream& operator<<(std::ostream& os, const GameDir& gameDir) {
    // Formatting for Heading
    os  << std::setw(Game::f.NAME_WIDTH) << std::left << "NAME"
        << std::setw(Game::f.PLATFORM_WIDTH)   << std::left << "PLATFORM"
        << std::endl;
    os  << std::setfill('-') << std::setw(Game::f.NAME_WIDTH + Game::f.PLATFORM_WIDTH)
        << "" << std::endl; 
    os  << std::setfill(' ');   // Return to default (space)
    
    // Add game titles to output stream
    for(const auto& game : gameDir.getGames()) {
        os << game;
    }

    return os;
}


}

