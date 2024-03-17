#ifndef GAMEDIR_HPP
#define GAMEDIR_HPP
#include "Game.hpp"
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

namespace GameDir {

class GameDir {
public:
    GameDir(const std::string& path);
    GameDir(const fs::path& path);

    ~GameDir();

    const std::vector<Game::Game>& getGames() const;
    Game::Platform getPlatform() const;


private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // GAMEDIR_HPP