
#ifndef DATAMODEL_CHARACTERXYDICTIONARY_H
#define DATAMODEL_CHARACTERXYDICTIONARY_H

// DataModel
#include "CharacterXYDescriptor.h"

// std
#include <map>


#define CHARACTERXYDICTIONARYINSTANCE MIMIc::DataModel::CharacterXYDictionary::INSTANCE()


namespace MIMIc { namespace DataModel {

    class CharacterXYDictionary
    {
        public:
            static CharacterXYDictionary& INSTANCE();

            ~CharacterXYDictionary();

            CharacterXYDescriptor GetXYFromCharacter(const char character) const;

        private:
            CharacterXYDictionary();
            CharacterXYDictionary(const CharacterXYDictionary& rhs); // undefined; singleton
            CharacterXYDictionary& operator=(const CharacterXYDictionary& rhs); // undefined; singleton
            
            static CharacterXYDictionary* s_instance;

            std::map<const char, CharacterXYDescriptor> m_dictionary;
    };

} }

#endif
