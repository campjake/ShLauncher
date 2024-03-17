// TODO - Configure CMake for Launcher Class
#include "Launcher.hpp"
namespace fs = std::filesystem;

namespace Launcher {

struct Impl {
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

static const fs::path& init() {
    std::string cache("data/.cache/roms.txt");
    std::ifstream file(cache);

    if(!file.is_open() || !(std::getline(file))) {
        promptAndCreateCache();
    }

    const fs::path romsDir(std::getline(file));

    return romsDir;
}

}