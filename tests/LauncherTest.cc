#include <gtest/gtest.h>
#include "Game.hpp"
#include "GameDir.hpp"
#include "Launcher.hpp"

namespace fs = std::filesystem;

TEST(FindDirectory, BasicAssertions) {
    fs::path path("/home/jacoblc/ShLauncher/data/");
    Launcher::Launcher launcher(path);
    ASSERT_EQ(launcher.getGameDir("nes").size(), 29);
}

TEST(FindGame, BasicAssertions) {
    fs::path path("/home/jacoblc/ShLauncher/data");
    Launcher::Launcher launcher(path);

    ASSERT_NO_THROW(launcher.getGame("Batman - The Video Game (USA)"));
}

