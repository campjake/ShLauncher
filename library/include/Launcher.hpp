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
    Launcher();
    Launcher(const fs::path& path);

    ~Launcher();

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
}

}

#endif // LAUNCHER_HPP