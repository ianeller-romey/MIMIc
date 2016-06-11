
#ifndef DATAMODEL_CHARACTERXYDESCRIPTOR_H
#define DATAMODEL_CHARACTERXYDESCRIPTOR_H

// Utilities
#include "NTuple.h"

// std
#include <string>


namespace MIMIc { namespace DataModel {
    
    typedef MIMIc::Utilities::NTuple<char, 2> CharacterXY;


    struct CharacterXYDescriptor
    {
        CharacterXYDescriptor();
        CharacterXYDescriptor(const char* const type, char* xy);

        std::string m_type;
        CharacterXY m_xy;
    };

} }

#endif
