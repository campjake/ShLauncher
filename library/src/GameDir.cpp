#include "GameDir.hpp"

namespace fs = std::filesystem; // ignore intellisense errors for fs

namespace GameDir {
struct GameDir::Impl {
    std::string dirPath;
    std::vector<Game::Game> gameFiles;
    

    Impl(const std::string& dirPath)
    : dirPath(dirPath)
    {
        
        for(const auto& file : fs::directory_iterator(dirPath)) {
            if(fs::is_regular_file(file)) {
                gameFiles.emplace_back(file.path().filename().string());
            }
        }
    }
};

GameDir::GameDir(const std::string& path) 
: pImpl(std::make_unique<Impl>(path))
{}

}

