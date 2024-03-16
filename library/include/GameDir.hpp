#ifndef GAMEDIR_HPP
#define GAMEDIR_HPP
#include "Game.hpp"
#include "boost/filesystem.hpp"
#include <vector>

namespace GameDir {

class GameDir {
public:
    GameDir(const std::string& path);


private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // GAMEDIR_HPP