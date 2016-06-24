
// DataModel
#include "WordDescriptor.h"

// std
#include <cstdio>


namespace MIMIc { namespace DataModel {
    
    WordDescriptor::WordDescriptor()
    {
    }

    
    WordDescriptor::WordDescriptor(const char* const style, const char* const word) :
        m_style(style),
        m_word(word)
    {
    }


    const bool WordDescriptor::IsNewline() const
    {
        return m_word.size() == 1 && m_word[0] == '\n';
    }


    const Utilities::NTuple<unsigned, 2> WordDescriptor::GetDimensions() const
    {
        unsigned currentLength = 0,
                 maxWidth = currentLength,
                 maxHeight = 1;

        for(auto character : m_word)
        {
            // newline?
            if(character == '\n')
            {
                // only update maxWidth if necessary
                if(currentLength > maxWidth)
                    maxWidth = currentLength;

                // reset currentLength
                currentLength = 0;

                // always update maxHeight
                ++maxHeight;
            }
            else
                ++currentLength;
        }

        // one last check
        if(currentLength > maxWidth)
            maxWidth = currentLength;

        Utilities::NTuple<unsigned, 2> dimensions;
        dimensions.m_value = maxWidth;
        dimensions.m_next.m_value = maxHeight;
        return dimensions;
    }


    std::vector<WordDescriptor> WordDescriptor::ParseStringForWords(const char* const string)
    {
        std::vector<WordDescriptor> words;
        // TODO:
        // configure this, save in GameStateManager or something
        std::string defaultStyle = "default";
        auto length = strlen(string);
        unsigned index = 0;

        ParseStringForWords(words, defaultStyle, string, length, index);

        return words;
    }


    
    void WordDescriptor::ParseStringForWords(std::vector<WordDescriptor>& words, std::string currentStyle, const char* const string, const unsigned strlen, unsigned& index)
    {
        WordDescriptor word(currentStyle.c_str(), "");

        bool go = true;
        while(go)
        {
            auto character = string[index];
            
            // if we've found a new style marker ...
            if(character == '<')
            {
                auto nextCharacter = string[index + 1];
                
                auto style = ParseStringForStyle(string, strlen, index);

                // check to see if this is a closing style marker ...
                if(nextCharacter == '/')
                {
                    // (error checking)
                    if(style != currentStyle)
                        throw; // TODO

                    // if this is a closing style marker, we're done here
                    return;
                }
                else
                {
                    // if this is an opening style marker, recurse with the new style
                    ParseStringForWords(words, style, string, strlen, index);
                }
            }
            // if we've found a whitespace character ...
            else if(character == ' ' || character == '\n')
            {
                // push back our current word ...
                words.push_back(word);

                // ... AND push back the whitespace character ...
                word.m_word = character;
                words.push_back(word);

                // ... AND reset the word
                word.m_word.clear();
            }
            // otherwise, just add the character to the current word
            else
            {
                word.m_word += character;
            }

            if(++index >= strlen)
                go = false;
        }

        words.push_back(word);
    }


    std::string WordDescriptor::ParseStringForStyle(const char* const string, const unsigned strlen, unsigned& index)
    {
        std::string style;

        // we don't care if we have an opening or closing style marker;
        // we only want the style itself
        auto character = '0';
        while((character = string[index]) && (character == '<' || character == '/'))
        {
            ++index;
        }

        while(index < strlen && (character = string[index]) != '>')
        {
            style += character;
            ++index;
        }

        return style;
    }

} }
