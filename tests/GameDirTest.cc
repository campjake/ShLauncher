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

TEST(GetGames, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);
}