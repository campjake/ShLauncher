#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP
#include "GameDir.hpp"
#include <filesystem>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
namespace fs = std::filesystem;

namespace Launcher {

class Launcher {
public:
    Launcher(const fs::path& path);
    ~Launcher();

    const Game::Game& getGame(const std::string& gameName) const;
    const GameDir::GameDir& getGameDir(const std::string& gameDir);
    void generateAutoComplete();
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // LAUNCHER_HPP