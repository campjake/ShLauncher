#include "GameDir.hpp"

namespace fs = std::filesystem;

namespace GameDir {
struct GameDir::Impl {
    fs::path dirPath;
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

    Impl(const fs::path& dirPath)
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

GameDir::GameDir(const fs::path& path)
: pImpl(std::make_unique<Impl>(path))
{}

const std::vector<Game::Game>& GameDir::getGames() const {
    return pImpl->gameFiles;
}

}

