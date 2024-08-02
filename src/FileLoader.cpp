#include "FileLoader.h"
#include <filesystem>

FileLoader::FileLoader(const std::string& directory, const std::string& extension)
    : directory_(directory), extension_(extension) {
    validate();
}

std::vector<std::string> FileLoader::loadFiles() const {
    std::vector<std::string> files;
    for (const auto& entry : std::filesystem::directory_iterator(directory_)) {
        if (entry.path().extension() == extension_) {
            files.push_back(entry.path().string());
        }
    }
    return files;
}

void FileLoader::validate() const {
    if (!std::filesystem::exists(directory_)) {
        throw std::invalid_argument("Directory does not exist: " + directory_);
    }
    if (extension_.empty() || extension_[0] != '.') {
        throw std::invalid_argument("Invalid file extension: " + extension_);
    }
}
