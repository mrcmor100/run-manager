#include "FileLoader.h"
#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

class FileLoaderTest : public ::testing::Test {
protected:
    std::string testDir = "test_directory";
    std::string testFile1 = "test_directory/file1.rl";
    std::string testFile2 = "test_directory/file2.rl";
    std::string invalidFile = "test_directory/file3.txt";

    void SetUp() override {
        std::filesystem::create_directory(testDir);
        std::ofstream(testFile1).close();
        std::ofstream(testFile2).close();
        std::ofstream(invalidFile).close();
    }

    void TearDown() override {
        std::filesystem::remove_all(testDir);
    }
};

TEST_F(FileLoaderTest, DirectoryDoesNotExist) {
    EXPECT_THROW(FileLoader loader("non_existent_directory", ".rl"), std::invalid_argument);
}

TEST_F(FileLoaderTest, InvalidExtension) {
    EXPECT_THROW(FileLoader loader(testDir, "rl"), std::invalid_argument);
    EXPECT_THROW(FileLoader loader(testDir, ""), std::invalid_argument);
}

TEST_F(FileLoaderTest, LoadFiles) {
    FileLoader loader(testDir, ".rl");
    auto files = loader.loadFiles();
    EXPECT_EQ(files.size(), 2);
    EXPECT_NE(std::find(files.begin(), files.end(), testFile1), files.end());
    EXPECT_NE(std::find(files.begin(), files.end(), testFile2), files.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
