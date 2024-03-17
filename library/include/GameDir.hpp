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

    const std::vector<Game::Game>& getGames() const;


private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // GAMEDIR_HPP