#include "GameDir.hpp"

namespace fs = std::filesystem;

namespace GameDir {
struct GameDir::Impl {
    fs::directory_entry dirPath;        //!< The path to the directory containing the game files
    std::vector<Game::Game> gameFiles;  //!< Vector of Game objects
    Game::Platform platform;            //!< The platform of the game
    
    /**
     * @brief Constructor for the Impl class.
     *
     * @param dirPath The path to the directory containing the game files.
     *
     * @throws fs::filesystem_error If there is an error accessing the directory.
     */
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

    /**
     * @brief Constructor for initializing the Impl with a directory path.
     *
     * @param dirPath the path to the directory
     *
     * @throws std::filesystem::filesystem_error if there is an error accessing the file system
     */
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

    /**
     * @brief Constructor for the Impl class.
     *
     * @param dirPath the directory path
     *
     * @return N/A
     *
     * @throws N/A
     */
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

/**
 * @brief      Constructs a GameDir object from a directory path.
 *
 * @param[in]  path  The directory path as a string
 *
 * @pre        The directory at the specified path must exist.
 * @post       Creates a valid GameDir object.
 */
GameDir::GameDir(const std::string& path)
    : pImpl(std::make_unique<Impl>(path))
{
}

/**
 * @brief      Constructs a GameDir object from a std::filesystem::path object.
 *
 * @param[in]  path  The path as a std::filesystem::path object
 *
 * @pre        The directory at the specified path must exist.
 * @post       Creates a valid GameDir object.
 */
GameDir::GameDir(const fs::path& path)
    : pImpl(std::make_unique<Impl>(path))
{}


/**
 * @brief      Constructs a GameDir object from an std::filesystem::directory_entry object.
 *
 * @param[in]  path  The path as a std::filesystem::directory_entry object
 *
 * @pre        The directory at the specified path must exist.
 * @post       Creates a valid GameDir object.
 */
GameDir::GameDir(const fs::directory_entry& path)
    : pImpl(std::make_unique<Impl>(path))
{}

/**
 * @brief      Default destructor.
 *
 * @pre        N/A
 * @post       Does nothing.
 */
GameDir::~GameDir() = default;


/**
 * @brief      Move constructor.
 *
 * @param[in]  other  The other GameDir to move from
 *
 * @pre        The other GameDir is in a valid state.
 * @post       Leaves the other GameDir in a valid but unspecified state.
 */
GameDir::GameDir(GameDir&& other) noexcept
: pImpl(std::move(other.pImpl))
{}

/**
 * @brief      Move assignment operator.
 *
 * @param[in]  rhs  The other GameDir to move from
 *
 * @return     A reference to self.
 *
 * @pre        The other GameDir is in a valid state.
 * @post       Leaves "other" in a valid but unspecified state.
 */
GameDir& GameDir::operator=(GameDir&& rhs) noexcept
{
    pImpl = std::move(rhs.pImpl);
    return *this;
}

/**
 * @brief      Get the games.
 *
 * @pre        N/A
 * @post       Returns a vector of Game objects.
 *
 * @return     The games.
 */
const std::vector<Game::Game>& GameDir::getGames() const {
    return pImpl->gameFiles;
}


/**
 * GetGame
 *
 * @brief      Gets a game by its name.
 *
 * @param[in]  gameName  The game's name
 *
 * @pre        gameName is not empty
 * @post       Returns a reference to the Game object with the given name.
 *
 * @return     A reference to the Game object with the given name.
 *
 * @throws     std::out_of_range if no Game object with the given name exists.
 */
Game::Game& GameDir::getGame(const std::string& gameName) const {
    for(int i = 0; i < pImpl->gameFiles.size(); i++) {
        if(pImpl->gameFiles.at(i).getGameName() == gameName) {
            return pImpl->gameFiles.at(i);
        }
    }
}

/**
 * @brief      Gets the platform.
 *
 * @pre        N/A
 * @post       Returns the platform as a Platform enum.
 *
 * @return     The platform.
*/
Game::Platform GameDir::getPlatform() const {
    return pImpl->platform;
}

/**
 * Size
 *
 * @brief      Gets the number of games in the GameDir.
 *
 * @pre        N/A
 * @post       Returns an integer representing the number of games in the GameDir.
 *
 * @return     The number of games in the GameDir.
*/
const int GameDir::size() const {
    return pImpl->gameFiles.size();
}


/**
 * Operator== Overload
 *
 * @brief      Checks if two GameDir objects are structurally equal.
 *
 * @param      rhs  The right-hand side GameDir object to compare
 *
 * @return     true if the two GameDir objects have the same directory path,
 *             false otherwise.
 */
bool GameDir::operator==(const GameDir& rhs) const {
    return pImpl->dirPath == rhs.pImpl->dirPath;
}


/**
 * Operator<< Overload
 *
 * @brief      Generates an ostream object for the caller to use.
 *
 * @param      os    The ostream object to write to.
 * @param[in]  gameDir   The GameDir object to write to the stream.
 *
 * @return     The updated ostream object.
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

