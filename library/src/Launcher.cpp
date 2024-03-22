// TODO - Configure CMake for Launcher Class
#include "Launcher.hpp"
namespace fs = std::filesystem;

namespace Launcher {

struct Launcher::Impl {
    fs::directory_entry romsDir;
    std::vector<GameDir::GameDir> gameDirs;

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

Launcher::Launcher(const fs::path& path) 
: pImpl(std::make_unique<Impl>(path))
{}

Launcher::~Launcher() = default;

const GameDir::GameDir& Launcher::getGameDir(const std::string& gameDir) {
    const Game::Platform platform = Game::strToPlatform.at(gameDir); 
    for(auto& gd : pImpl->gameDirs) {
        if(gd.getPlatform() == platform) {
            return gd;
        }
    }
}

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
}