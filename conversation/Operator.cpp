#include "Operator.h"

std::ostream& operator<<(std::ostream& os, const PlainText& obj) 
{
    os << obj.getText();
    return os;
}
