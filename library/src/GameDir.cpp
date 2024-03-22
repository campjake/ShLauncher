#include "GameDir.hpp"

namespace fs = std::filesystem;

namespace GameDir {
struct GameDir::Impl {
    fs::directory_entry dirPath;
    std::vector<Game::Game> gameFiles;
    Game::Platform platform;
    
    Impl(const std::string& dirPath)
    : dirPath(dirPath)
    {
        
        for(const auto& file : fs::directory_iterator(dirPath)) {
            if(fs::is_regular_file(file)) {
                gameFiles.emplace_back(file.path().string());
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

    Impl(const fs::directory_entry& dirPath)
    : dirPath(dirPath)
    {
        
        for(const auto& file : fs::directory_iterator(dirPath)) {
            if(fs::is_regular_file(file)) {
                gameFiles.emplace_back(file);
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

/** GameDir Constructor (Directory Entry Object)
 * Preconditions    : An std::filestream::directory_entry object
 * Postconditions   : Constructs a valid GameDir object
*/
GameDir::GameDir(const fs::directory_entry& path)
: pImpl(std::make_unique<Impl>(path))
{}

/** Default Destructor
 * Preconditions    : N/A
 * Postconditions   : Does nothing
*/
GameDir::~GameDir() = default;

/** Move Constructor
 * Preconditions    : A GameDir object
 * Postconditions   : Leaves "other" in a valid & destructible state
*/
GameDir::GameDir(GameDir&& other) noexcept
: pImpl(std::move(other.pImpl))
{}

/** Move Assignment
 * Preconditions    : A GameDir object
 * Postconditions   : Leaves "other" in a valid & destructible state
*/
GameDir& GameDir::operator=(GameDir&& rhs) noexcept
{
    pImpl = std::move(rhs.pImpl);
    return *this;
}

/** GetGames
 * Preconditions    : N/A
 * Postconditions   : Returns a vector of Game objects
*/
const std::vector<Game::Game>& GameDir::getGames() const {
    return pImpl->gameFiles;
}

/** GetGame
 * Preconditions    : N/A
 * Postconditions   : Returns a Game object
*/
Game::Game& GameDir::getGame(const std::string& gameName) const {
    for(int i = 0; i < pImpl->gameFiles.size(); i++) {
        if(pImpl->gameFiles.at(i).getGameName() == gameName) {
            return pImpl->gameFiles.at(i);
        }
    }
}

/** GetPlatform
 * Preconditions    : N/A
 * Postconditions   : Returns Platform enum
*/
Game::Platform GameDir::getPlatform() const {
    return pImpl->platform;
}

/** Size
 * Preconditions    : N/A
 * Postconditions   : Returns an int
*/
const int GameDir::size() const {
    return pImpl->gameFiles.size();
}


/** Operator== Overload
 * Preconditions    : A GameDir object
 * Postconditions   : Reutrns true if structurally equivalent, else false
*/
bool GameDir::operator==(const GameDir& rhs) const {
    return pImpl->dirPath == rhs.pImpl->dirPath;
}


/** Operator<< Overload
 * Preconditions    : An ostream object, and a GameDir object
 * Postconditions   : Reutrns an ostream object for the caller to use
*/
std::ostream& operator<<(std::ostream& os, const GameDir& gameDir) {
    // Formatting for Heading
    os  << std::setw(Game::f.IDX_WIDTH)  << std::left << "INDEX"
        << std::setw(Game::f.NAME_WIDTH) << std::left << "NAME"
        << std::setw(Game::f.PLATFORM_WIDTH)   << std::left << "PLATFORM"
        << std::endl;
    os  << std::setfill('-') << std::setw(Game::f.IDX_WIDTH + Game::f.NAME_WIDTH + Game::f.PLATFORM_WIDTH)
        << "" << std::endl; 
    os  << std::setfill(' ');   // Return to default (space)
    
    int i = 1;
    // Add game titles to output stream
    for(const auto& game : gameDir.getGames()) {
        os << std::setw(3) << i++ << std::left << " -- " << game;
    }

    return os;
}


}

