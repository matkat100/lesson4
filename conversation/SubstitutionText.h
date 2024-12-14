#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

#include "PlainText.h"
#include <unordered_map>
#include <string>

class SubstitutionText : public PlainText
{
    std::unordered_map<char, char> dictionary;

    void loadDictionary(const std::string& fileName);

public:
    SubstitutionText(const std::string& text, const std::string& dictionaryFileName);
    ~SubstitutionText();

    std::string encrypt();
    std::string decrypt();

    static std::string encrypt(const std::string& text, const std::unordered_map<char, char>& dictionary);
    static std::string decrypt(const std::string& text, const std::unordered_map<char, char>& dictionary);
};

#endif 
