#include "GameDir.hpp"

namespace GameDir {
struct GameDir::Impl {
    std::string dirPath;
    std::vector<Game::Game> gameFiles;
    

    Impl(const std::string& dirPath)
    : dirPath(dirPath)
    {
        
        for(const auto& file : boost::filesystem::directory_iterator(dirPath)) {
            if(boost::filesystem::is_regular_file(file)) {
                gameFiles.emplace_back(file.path().filename().string());
            }
        }
    }
};

GameDir::GameDir(const std::string& path) 
: pImpl(std::make_unique<Impl>(path))
{}

}

