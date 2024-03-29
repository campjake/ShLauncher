#include <gtest/gtest.h>
#include "GameDir.hpp"

namespace fs = std::filesystem;

TEST(DirPathCtor, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);
}

TEST(DirPathCtor2, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string pathStr = "/d/Games/nds/" + file;
    fs::path path(pathStr);
    Game::Game pkmnMD(path);
}

TEST(DirEntryCtor, BasicAssertions) {
    std::string pathString = "/home/jacoblc/ShLauncher/data/nes";
    fs::path pathObject(pathString);
    GameDir::GameDir ndsPathEntry(pathObject);

    fs::directory_entry dirEntryObject(pathObject);
    GameDir::GameDir ndsDirEntry(dirEntryObject);

    ASSERT_EQ(ndsPathEntry, ndsDirEntry);
}

TEST(PrintGames, BasicAssertions) {
    std::string dirPath = "/home/jacoblc/ShLauncher/data/nes/";
    fs::path path(dirPath);
    GameDir::GameDir gba(path);

    std::cout << gba;    

}

TEST(DirSize, BasicAssertions) {
    std::string dirPath = "/home/jacoblc/ShLauncher/data/nes/";
    fs::path path(dirPath);
    GameDir::GameDir gba(path);

    ASSERT_EQ(gba.size(), 29);
}

TEST(GetConsole, BasicAssertions) {
    std::string dirPath = "/home/jacoblc/ShLauncher/data/nes";
    fs::path path(dirPath);
    GameDir::GameDir gba(path);

    ASSERT_EQ(gba.getPlatform(), Game::Platform::_NES);
}