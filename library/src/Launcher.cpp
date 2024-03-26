// TODO - Configure CMake for Launcher Class
#include "Launcher.hpp"
namespace fs = std::filesystem;

namespace Launcher {

struct Launcher::Impl {
    fs::directory_entry romsDir;                //!< Directoryt path containing platform subdirectories
    std::vector<GameDir::GameDir> gameDirs;     //!< Vector of GameDir objects

    /**
     * Constructor for initializing the Impl class with a given path.
     *
     * @param path the path to the directory
     *
     * @throws filesystem_error if there is an issue with the filesystem operations
     */
    Impl(const fs::path& path) 
    : romsDir(path)
    {
        for(const auto& dir : fs::directory_iterator(path)) {
            if(fs::is_directory(dir)) {
                gameDirs.emplace_back(dir);
            }
        }
    }
};

/**
 * Constructs a Launcher object with the specified path.
 *
 * @param path The path to the Launcher.
 *
 * @throws None
 */
Launcher::Launcher(const fs::path& path) 
: pImpl(std::make_unique<Impl>(path))
{}


Launcher::~Launcher() = default;


/**
 * Get a GameDir by its name.
 *
 * @param gameDir The name of the GameDir to get.
 *
 * @return The requested GameDir.
 *
 * @throws std::out_of_range if no GameDir with the given name exists.
 */
const GameDir::GameDir& Launcher::getGameDir(const std::string& gameDir) {
    const Game::Platform platform = Game::strToPlatform.at(gameDir); 
    for(auto& gd : pImpl->gameDirs) {
        if(gd.getPlatform() == platform) {
            return gd;
        }
    }
}


/**
 * @brief Get a Game by its name.
 *
 * @param gameName The name of the Game to get.
 *
 * @return A const reference to the Game with the given name.
 *
 * @throws std::runtime_error if no Game with the given name exists.
 */
const Game::Game& Launcher::getGame(const std::string& gameName) const {
    for(auto& gd : pImpl->gameDirs) {
        for(const auto& game : gd.getGames()) {
            if(game.getGameName() == gameName) {
                return game;
            }
        }
    }
    throw std::runtime_error("Game not found");
}
} // end namespace Launcher