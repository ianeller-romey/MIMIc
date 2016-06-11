
// DataModel
#include "CharacterXYDescriptor.h"


namespace MIMIc { namespace DataModel {
    
    CharacterXYDescriptor::CharacterXYDescriptor()
    {
    }

    
    CharacterXYDescriptor::CharacterXYDescriptor(const char* const type, char* xy) :
        m_type(type),
        m_xy(xy)
    {
    }

} }
