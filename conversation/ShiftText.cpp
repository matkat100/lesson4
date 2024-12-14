#include "ShiftText.h"

ShiftText::ShiftText(const std::string& text, int key) : PlainText(text), key(key) 
{
    this->text = encrypt();
    isEnc = true;
}

ShiftText::~ShiftText() {}

std::string ShiftText::encrypt() 
{
    return encrypt(text, key);
}

std::string ShiftText::decrypt() 
{
    return decrypt(text, key);
}

std::string ShiftText::encrypt(const std::string& text, int key)
{
    std::string encrypted = text;
    for (char& c : encrypted)
    {
        if (isalpha(c)) 
        {
            c = ((c - 'a' + key) % 26) + 'a';
        }
    }
    return encrypted;
}

std::string ShiftText::decrypt(const std::string& text, int key)
{
    return encrypt(text, 26 - key);
}
