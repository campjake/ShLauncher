#ifndef GAMEDIR_HPP
#define GAMEDIR_HPP
#include "Game.hpp"
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

namespace GameDir {


class GameDir {
public:
    friend std::ostream& operator<<(std::ostream& os, const GameDir& gameDir);

    GameDir(const std::string& path);
    GameDir(const fs::path& path);
    GameDir(const fs::directory_entry& path);

    ~GameDir();

// ACCESSORS
    const std::vector<Game::Game>& getGames() const;
    Game::Platform getPlatform() const;

// OPERATORS
    bool operator==(const GameDir& rhs) const;


private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // GAMEDIR_HPP