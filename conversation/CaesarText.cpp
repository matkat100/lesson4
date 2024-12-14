#include "CaesarText.h"

#define CAESAR_KEY 3

CaesarText::CaesarText(const std::string& text) : ShiftText(text, CAESAR_KEY) {}

CaesarText::~CaesarText() {}
