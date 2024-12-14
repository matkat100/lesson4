#include "PlainText.h"

int PlainText::numOfTexts = 0;

PlainText::PlainText(const std::string& text) : text(text), isEnc(false) 
{
    ++numOfTexts;
}

PlainText::~PlainText() {}

int PlainText::getNumOfTexts() 
{
    return numOfTexts;
}

bool PlainText::isEncrypted() const 
{
    return isEnc;
}

std::string PlainText::getText() const 
{
    return text;
}
