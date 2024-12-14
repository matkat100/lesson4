#include "SubstitutionText.h"
#include <fstream>
#include <stdexcept>


void SubstitutionText::loadDictionary(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Failed to open dictionary file: " + fileName);
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() >= 3 && line[1] == ',') 
        {
            char key = line[0];
            char value = line[2];
            dictionary[key] = value;
        }
    }
}


SubstitutionText::SubstitutionText(const std::string& text, const std::string& dictionaryFileName)
    : PlainText(text) 
{
    loadDictionary(dictionaryFileName);
    this->text = encrypt();
    isEnc = true;
}


SubstitutionText::~SubstitutionText() {}


std::string SubstitutionText::encrypt() 
{
    return encrypt(text, dictionary);
}


std::string SubstitutionText::decrypt() 
{
    return decrypt(text, dictionary);
}


std::string SubstitutionText::encrypt(const std::string& text, const std::unordered_map<char, char>& dictionary) 
{
    std::string encrypted = text;
    for (char& c : encrypted) 
    {
        if (dictionary.find(c) != dictionary.end()) 
        {
            c = dictionary.at(c);  
        }
    }
    return encrypted;
}


std::string SubstitutionText::decrypt(const std::string& text, const std::unordered_map<char, char>& dictionary) 
{
    std::unordered_map<char, char> reverseDict;
    for (const auto& pair : dictionary) 
    {
        reverseDict[pair.second] = pair.first;
    }

    std::string decrypted = text;
    for (char& c : decrypted) 
    {
        if (reverseDict.find(c) != reverseDict.end()) 
        {
            c = reverseDict.at(c);  
        }
    }
    return decrypted;
}
