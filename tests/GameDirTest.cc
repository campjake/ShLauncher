#include <gtest/gtest.h>
#include "GameDir.hpp"


TEST(DirPathCtor, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);
}

TEST(GetGames, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);
}