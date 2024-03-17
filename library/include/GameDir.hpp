#ifndef GAMEDIR_HPP
#define GAMEDIR_HPP
#include "Game.hpp"
#include <filesystem>
#include <vector>

namespace GameDir {

class GameDir {
public:
    GameDir(const std::string& path);

    const std::vector<Game::Game>& getGames() const;


private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // GAMEDIR_HPP