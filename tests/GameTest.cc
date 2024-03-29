#include <gtest/gtest.h>
#include "Game.hpp"

namespace fs = std::filesystem;


TEST(PathStrCtor, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);
}

TEST(PathCtor, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string pathString = "/d/Games/nds/" + file;
    Game::Game pkmnMDStr(pathString);

    fs::path pathObject(pathString);
    Game::Game pkmnMDPath(pathObject);

    ASSERT_EQ(pkmnMDStr, pkmnMDPath);
}

TEST(DirEntry, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string pathString = "/d/Games/nds/" + file;
    fs::path pathObject(pathString);
    Game::Game pkmnMDPath(pathObject);

    fs::directory_entry dirEntryObject(pathObject);
    Game::Game pkmnMDDirEntry(dirEntryObject);


    ASSERT_EQ(pkmnMDPath, pkmnMDDirEntry);
}

TEST(GamePrint, BasicAssertions) {
    // Redirect stdout to a stringstream
    std::stringstream buffer;
    std::streambuf* old_stdout = std::cout.rdbuf(buffer.rdbuf());    

    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);

    std::cout << pkmnMD; 
    std::cout.rdbuf(old_stdout);

    // Check the contents of the buffer
    std::string printedOutput = buffer.str();
    // ASSERT_EQ(printedOutput, "Jake Game                     FBNeo               \n");
}

TEST(PlatformToString, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);

    std::string s = pkmnMD.platformToString();

    ASSERT_EQ(s, "Nintendo DS");
}

TEST(GameName, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);

    ASSERT_EQ(pkmnMD.getGameName(), "Pokemon Mystery Dungeon - Explorers of Time (USA)");
}

TEST(Platform, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);

    ASSERT_EQ(Game::Platform::_NDS, pkmnMD.getReleasePlatform());
}

TEST(FilePath, BasicAssertions) {
    std::string file = "Pokemon Mystery Dungeon - Explorers of Time (USA).nds";
    std::string path = "/d/Games/nds/" + file;
    Game::Game pkmnMD(path);

    ASSERT_EQ(path, pkmnMD.getPath());
}