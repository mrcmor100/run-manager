#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include <string>
#include <vector>
#include <stdexcept>

class FileLoader {
public:
    FileLoader(const std::string& directory, const std::string& extension);
    std::vector<std::string> loadFiles() const;

private:
    std::string directory_;
    std::string extension_;
    void validate() const;
};

#endif // FILE_LOADER_H
