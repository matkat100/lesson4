#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <string>

class PlainText 
{
protected:
    std::string text;
    bool isEnc;
    static int numOfTexts;

public:
    PlainText(const std::string& text);
    virtual ~PlainText();

    static int getNumOfTexts();
    virtual bool isEncrypted() const;
    virtual std::string getText() const;
};

#endif 
