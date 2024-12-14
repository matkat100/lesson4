#include "FileHelper.h"

std::string FileHelper::readFileToString(const std::string& fileName) 
{
    std::ifstream file(fileName);
    return { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
}

void FileHelper::writeWordsToFile(const std::string& inputFileName, const std::string& outputFileName) 
{
    std::ifstream input(inputFileName);
    std::ofstream output(outputFileName);
    std::string word;

    while (input >> word)
    {
        output << word << '\n';
    }
}

void FileHelper::saveTextInFile(const std::string& text, const std::string& outputFileName) 
{
    std::ofstream file(outputFileName);
    file << text;
}
