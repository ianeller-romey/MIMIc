
#ifndef DATAMODEL_WORDDESCRIPTOR_H
#define DATAMODEL_WORDDESCRIPTOR_H

// Utilities
#include <NTuple.h>

// std
#include <vector>
#include <string>


namespace MIMIc { namespace DataModel {


    class WordDescriptor
    {
        public:
            WordDescriptor();
            WordDescriptor(const char* const style, const char* const word);

            const bool IsNewline() const;
            const Utilities::NTuple<unsigned, 2> GetDimensions() const;

            std::string m_style;
            std::string m_word;

            static std::vector<WordDescriptor> ParseStringForWords(const char* const string);

        private:
            static void ParseStringForWords(std::vector<WordDescriptor>& words, std::string currentStyle, const char* const string, const unsigned strlen, unsigned& index);
            static std::string ParseStringForStyle(const char* const string, const unsigned strlen, unsigned& index);
    };

} }

#endif
