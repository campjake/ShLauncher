#include <gtest/gtest.h>
#include "Game.hpp"
#include <iostream>

TEST(DefaultCtor, BasicAssertions) {
    Game::Date releaseDate(1994, Game::Date::Month::JUNE, 29);
    Game::Game myGame("Jake Game", releaseDate, "Jake's Cool RPG Game",
                    Game::Platform::_FBNEO, "Jake/Campbell/Game.bin"); 
}

TEST(GamePrint, BasicAssertions) {
    // Redirect stdout to a stringstream
    std::stringstream buffer;
    std::streambuf* old_stdout = std::cout.rdbuf(buffer.rdbuf());    

    Game::Date releaseDate(1994, Game::Date::Month::JUNE, 29);    
    Game::Game myGame("Jake Game", releaseDate, "Jake's Cool RPG Game",
                    Game::Platform::_FBNEO, "Jake/Campbell/Game.bin");

    std::cout << myGame; 
    std::cout.rdbuf(old_stdout);

    // Check the contents of the buffer
    std::string printedOutput = buffer.str();
    ASSERT_EQ(printedOutput, "Jake Game                     FBNeo               \n");
}

TEST(PlatformToString, BasicAssertions) {
    Game::Date releaseDate(1994, Game::Date::Month::JUNE, 29);    
    Game::Game myGame("Jake Game", releaseDate, "Jake's Cool RPG Game",
                    Game::Platform::_GBA, "Jake/Campbell/Game.bin");

    const std::string s = myGame.platformToString();

    ASSERT_EQ(s, "Game Boy Advance");
}

TEST(GameName, BasicAssertions) {
    Game::Date releaseDate(1994, Game::Date::Month::JUNE, 29);    
    Game::Game myGame("Jake Game", releaseDate, "Jake's Cool RPG Game",
                    Game::Platform::_GBA, "Jake/Campbell/Game.bin");

    std::string name = myGame.getGameName();

    ASSERT_EQ(name, "Jake Game");

}

TEST(ReleaseDate, BasicAssertions) {
    Game::Date releaseDate(1994, Game::Date::Month::JUNE, 29);  
    Game::Game myGame("Jake Game", releaseDate, "Jake's Cool RPG Game",
                    Game::Platform::_GBA, "Jake/Campbell/Game.bin");
    
    ASSERT_EQ(releaseDate.year, myGame.getReleaseDate().year);
}

TEST(Description, BasicAssertions) {
    Game::Date releaseDate(1994, Game::Date::Month::JUNE, 29);
    std::string description = "Jake's Cool RPG Game";
    Game::Game myGame("Jake Game", releaseDate, description,
                    Game::Platform::_GBA, "Jake/Campbell/Game.bin");

    ASSERT_EQ(description, myGame.getDescription());
}