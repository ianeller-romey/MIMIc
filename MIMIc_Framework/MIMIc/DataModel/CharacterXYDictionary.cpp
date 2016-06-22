
// DataModel
#include "CharacterXYDictionary.h"


namespace MIMIc { namespace DataModel {

    CharacterXYDictionary* CharacterXYDictionary::s_instance = 0;


    CharacterXYDictionary& CharacterXYDictionary::INSTANCE()
    {
        if(!s_instance)
            s_instance = new CharacterXYDictionary();

        return *s_instance;
    }


    CharacterXYDictionary::~CharacterXYDictionary()
    {
    }
    
    
    CharacterXYDictionary::CharacterXYDictionary()
    {
        // TODO:
        // Load dynamically
        const char *const typeText = "text",
                   *const typeLines = "lines";
        char values[2];

        // 'a'
        values[0] = 0; values[1] = 0;
        m_dictionary['a'] = CharacterXYDescriptor(typeText, values);

        // 'b'
        values[0] = 1; values[1] = 0;
        m_dictionary['b'] = CharacterXYDescriptor(typeText, values);

        // 'c'
        values[0] = 2; values[1] = 0;
        m_dictionary['c'] = CharacterXYDescriptor(typeText, values);

        // 'd'
        values[0] = 3; values[1] = 0;
        m_dictionary['d'] = CharacterXYDescriptor(typeText, values);

        // 'e'
        values[0] = 4; values[1] = 0;
        m_dictionary['e'] = CharacterXYDescriptor(typeText, values);

        // 'f'
        values[0] = 5; values[1] = 0;
        m_dictionary['f'] = CharacterXYDescriptor(typeText, values);

        // 'g'
        values[0] = 6; values[1] = 0;
        m_dictionary['g'] = CharacterXYDescriptor(typeText, values);

        // 'h'
        values[0] = 7; values[1] = 0;
        m_dictionary['h'] = CharacterXYDescriptor(typeText, values);

        // 'i'
        values[0] = 8; values[1] = 0;
        m_dictionary['i'] = CharacterXYDescriptor(typeText, values);

        // 'j'
        values[0] = 9; values[1] = 0;
        m_dictionary['j'] = CharacterXYDescriptor(typeText, values);

        // 'k'
        values[0] = 10; values[1] = 0;
        m_dictionary['k'] = CharacterXYDescriptor(typeText, values);

        // 'l'
        values[0] = 11; values[1] = 0;
        m_dictionary['l'] = CharacterXYDescriptor(typeText, values);

        // 'm'
        values[0] = 12; values[1] = 0;
        m_dictionary['m'] = CharacterXYDescriptor(typeText, values);

        // 'n'
        values[0] = 13; values[1] = 0;
        m_dictionary['n'] = CharacterXYDescriptor(typeText, values);

        // 'o'
        values[0] = 14; values[1] = 0;
        m_dictionary['o'] = CharacterXYDescriptor(typeText, values);

        // 'p'
        values[0] = 15; values[1] = 0;
        m_dictionary['p'] = CharacterXYDescriptor(typeText, values);

        // 'q'
        values[0] = 16; values[1] = 0;
        m_dictionary['q'] = CharacterXYDescriptor(typeText, values);

        // 'r'
        values[0] = 17; values[1] = 0;
        m_dictionary['r'] = CharacterXYDescriptor(typeText, values);

        // 's'
        values[0] = 18; values[1] = 0;
        m_dictionary['s'] = CharacterXYDescriptor(typeText, values);

        // 't'
        values[0] = 19; values[1] = 0;
        m_dictionary['t'] = CharacterXYDescriptor(typeText, values);

        // 'u'
        values[0] = 20; values[1] = 0;
        m_dictionary['u'] = CharacterXYDescriptor(typeText, values);

        // 'v'
        values[0] = 21; values[1] = 0;
        m_dictionary['v'] = CharacterXYDescriptor(typeText, values);

        // 'w'
        values[0] = 22; values[1] = 0;
        m_dictionary['w'] = CharacterXYDescriptor(typeText, values);

        // 'x'
        values[0] = 23; values[1] = 0;
        m_dictionary['x'] = CharacterXYDescriptor(typeText, values);

        // 'y'
        values[0] = 24; values[1] = 0;
        m_dictionary['y'] = CharacterXYDescriptor(typeText, values);

        // 'z'
        values[0] = 25; values[1] = 0;
        m_dictionary['z'] = CharacterXYDescriptor(typeText, values);

        // 'A'
        values[0] = 0; values[1] = 1;
        m_dictionary['A'] = CharacterXYDescriptor(typeText, values);

        // 'B'
        values[0] = 1; values[1] = 1;
        m_dictionary['B'] = CharacterXYDescriptor(typeText, values);

        // 'C'
        values[0] = 2; values[1] = 1;
        m_dictionary['C'] = CharacterXYDescriptor(typeText, values);

        // 'D'
        values[0] = 3; values[1] = 1;
        m_dictionary['D'] = CharacterXYDescriptor(typeText, values);

        // 'E'
        values[0] = 4; values[1] = 1;
        m_dictionary['E'] = CharacterXYDescriptor(typeText, values);

        // 'F'
        values[0] = 5; values[1] = 1;
        m_dictionary['F'] = CharacterXYDescriptor(typeText, values);

        // 'G'
        values[0] = 6; values[1] = 1;
        m_dictionary['G'] = CharacterXYDescriptor(typeText, values);

        // 'H'
        values[0] = 7; values[1] = 1;
        m_dictionary['H'] = CharacterXYDescriptor(typeText, values);

        // 'I'
        values[0] = 8; values[1] = 1;
        m_dictionary['I'] = CharacterXYDescriptor(typeText, values);

        // 'J'
        values[0] = 9; values[1] = 1;
        m_dictionary['J'] = CharacterXYDescriptor(typeText, values);

        // 'K'
        values[0] = 10; values[1] = 1;
        m_dictionary['K'] = CharacterXYDescriptor(typeText, values);

        // 'L'
        values[0] = 11; values[1] = 1;
        m_dictionary['L'] = CharacterXYDescriptor(typeText, values);

        // 'M'
        values[0] = 12; values[1] = 1;
        m_dictionary['M'] = CharacterXYDescriptor(typeText, values);

        // 'N'
        values[0] = 13; values[1] = 1;
        m_dictionary['N'] = CharacterXYDescriptor(typeText, values);

        // 'O'
        values[0] = 14; values[1] = 1;
        m_dictionary['O'] = CharacterXYDescriptor(typeText, values);

        // 'P'
        values[0] = 15; values[1] = 1;
        m_dictionary['P'] = CharacterXYDescriptor(typeText, values);

        // 'Q'
        values[0] = 16; values[1] = 1;
        m_dictionary['Q'] = CharacterXYDescriptor(typeText, values);

        // 'R'
        values[0] = 17; values[1] = 1;
        m_dictionary['R'] = CharacterXYDescriptor(typeText, values);

        // 'S'
        values[0] = 18; values[1] = 1;
        m_dictionary['S'] = CharacterXYDescriptor(typeText, values);

        // 'T'
        values[0] = 19; values[1] = 1;
        m_dictionary['T'] = CharacterXYDescriptor(typeText, values);

        // 'U'
        values[0] = 20; values[1] = 1;
        m_dictionary['U'] = CharacterXYDescriptor(typeText, values);

        // 'V'
        values[0] = 21; values[1] = 1;
        m_dictionary['V'] = CharacterXYDescriptor(typeText, values);

        // 'W'
        values[0] = 22; values[1] = 1;
        m_dictionary['W'] = CharacterXYDescriptor(typeText, values);

        // 'X'
        values[0] = 23; values[1] = 1;
        m_dictionary['X'] = CharacterXYDescriptor(typeText, values);

        // 'Y'
        values[0] = 24; values[1] = 1;
        m_dictionary['Y'] = CharacterXYDescriptor(typeText, values);

        // 'Z'
        values[0] = 25; values[1] = 1;
        m_dictionary['Z'] = CharacterXYDescriptor(typeText, values);

        // '0'
        values[0] = 0; values[1] = 2;
        m_dictionary['0'] = CharacterXYDescriptor(typeText, values);

        // '1'
        values[0] = 1; values[1] = 2;
        m_dictionary['1'] = CharacterXYDescriptor(typeText, values);

        // '2'
        values[0] = 2; values[1] = 2;
        m_dictionary['2'] = CharacterXYDescriptor(typeText, values);

        // '3'
        values[0] = 3; values[1] = 2;
        m_dictionary['3'] = CharacterXYDescriptor(typeText, values);

        // '4'
        values[0] = 4; values[1] = 2;
        m_dictionary['4'] = CharacterXYDescriptor(typeText, values);

        // '5'
        values[0] = 5; values[1] = 2;
        m_dictionary['5'] = CharacterXYDescriptor(typeText, values);

        // '6'
        values[0] = 6; values[1] = 2;
        m_dictionary['6'] = CharacterXYDescriptor(typeText, values);

        // '7'
        values[0] = 7; values[1] = 2;
        m_dictionary['7'] = CharacterXYDescriptor(typeText, values);

        // '8'
        values[0] = 8; values[1] = 2;
        m_dictionary['8'] = CharacterXYDescriptor(typeText, values);

        // '9'
        values[0] = 9; values[1] = 2;
        m_dictionary['9'] = CharacterXYDescriptor(typeText, values);

        // '.'
        values[0] = 0; values[1] = 3;
        m_dictionary['.'] = CharacterXYDescriptor(typeText, values);

        // '!'
        values[0] = 1; values[1] = 3;
        m_dictionary['!'] = CharacterXYDescriptor(typeText, values);

        // '?'
        values[0] = 2; values[1] = 3;
        m_dictionary['?'] = CharacterXYDescriptor(typeText, values);

        // ','
        values[0] = 3; values[1] = 3;
        m_dictionary[','] = CharacterXYDescriptor(typeText, values);

        // ';'
        values[0] = 4; values[1] = 3;
        m_dictionary[';'] = CharacterXYDescriptor(typeText, values);

        // ':'
        values[0] = 5; values[1] = 3;
        m_dictionary[':'] = CharacterXYDescriptor(typeText, values);

        // '''
        values[0] = 6; values[1] = 3;
        m_dictionary['\''] = CharacterXYDescriptor(typeText, values);

        // '"'
        values[0] = 7; values[1] = 3;
        m_dictionary['"'] = CharacterXYDescriptor(typeText, values);

        // '_'
        values[0] = 8; values[1] = 3;
        m_dictionary['_'] = CharacterXYDescriptor(typeText, values);

        // '('
        values[0] = 9; values[1] = 3;
        m_dictionary['('] = CharacterXYDescriptor(typeText, values);

        // ')'
        values[0] = 10; values[1] = 3;
        m_dictionary[')'] = CharacterXYDescriptor(typeText, values);

        // '['
        values[0] = 11; values[1] = 3;
        m_dictionary['['] = CharacterXYDescriptor(typeText, values);

        // ']'
        values[0] = 12; values[1] = 3;
        m_dictionary[']'] = CharacterXYDescriptor(typeText, values);

        // '{'
        values[0] = 13; values[1] = 3;
        m_dictionary['{'] = CharacterXYDescriptor(typeText, values);

        // '}
        values[0] = 14; values[1] = 3;
        m_dictionary['}'] = CharacterXYDescriptor(typeText, values);

        // '/'
        values[0] = 15; values[1] = 3;
        m_dictionary['/'] = CharacterXYDescriptor(typeText, values);

        // '\'
        values[0] = 16; values[1] = 3;
        m_dictionary['\\'] = CharacterXYDescriptor(typeText, values);

        // '|'
        values[0] = 17; values[1] = 3;
        m_dictionary['|'] = CharacterXYDescriptor(typeText, values);

        // '+'
        values[0] = 18; values[1] = 3;
        m_dictionary['+'] = CharacterXYDescriptor(typeText, values);

        // '-'
        values[0] = 19; values[1] = 3;
        m_dictionary['-'] = CharacterXYDescriptor(typeText, values);

        // '='
        values[0] = 20; values[1] = 3;
        m_dictionary['='] = CharacterXYDescriptor(typeText, values);

        // '`'
        values[0] = 0; values[1] = 4;
        m_dictionary['`'] = CharacterXYDescriptor(typeText, values);

        // '~'
        values[0] = 1; values[1] = 4;
        m_dictionary['~'] = CharacterXYDescriptor(typeText, values);

        // '@'
        values[0] = 2; values[1] = 4;
        m_dictionary['@'] = CharacterXYDescriptor(typeText, values);

        // '#'
        values[0] = 3; values[1] = 4;
        m_dictionary['#'] = CharacterXYDescriptor(typeText, values);

        // '$'
        values[0] = 4; values[1] = 4;
        m_dictionary['$'] = CharacterXYDescriptor(typeText, values);

        // '%'
        values[0] = 5; values[1] = 4;
        m_dictionary['%'] = CharacterXYDescriptor(typeText, values);

        // '^'
        values[0] = 6; values[1] = 4;
        m_dictionary['^'] = CharacterXYDescriptor(typeText, values);

        // '&'
        values[0] = 7; values[1] = 4;
        m_dictionary['&'] = CharacterXYDescriptor(typeText, values);

        // '*'
        values[0] = 8; values[1] = 4;
        m_dictionary['*'] = CharacterXYDescriptor(typeText, values);

        // '│'
        values[0] = 3; values[1] = 0;
        m_dictionary['│'] = CharacterXYDescriptor(typeLines, values);

        // '┤'
        values[0] = 4; values[1] = 0;
        m_dictionary['┤'] = CharacterXYDescriptor(typeLines, values);

        // '╡'
        values[0] = 5; values[1] = 0;
        m_dictionary['╡'] = CharacterXYDescriptor(typeLines, values);

        // '╢'
        values[0] = 6; values[1] = 0;
        m_dictionary['╢'] = CharacterXYDescriptor(typeLines, values);

        // '╖'
        values[0] = 7; values[1] = 0;
        m_dictionary['╖'] = CharacterXYDescriptor(typeLines, values);

        // '╕'
        values[0] = 8; values[1] = 0;
        m_dictionary['╕'] = CharacterXYDescriptor(typeLines, values);

        // '╣'
        values[0] = 9; values[1] = 0;
        m_dictionary['╣'] = CharacterXYDescriptor(typeLines, values);

        // '║'
        values[0] = 10; values[1] = 0;
        m_dictionary['║'] = CharacterXYDescriptor(typeLines, values);

        // '╗'
        values[0] = 11; values[1] = 0;
        m_dictionary['╗'] = CharacterXYDescriptor(typeLines, values);

        // '╝'
        values[0] = 12; values[1] = 0;
        m_dictionary['╝'] = CharacterXYDescriptor(typeLines, values);

        // '╜'
        values[0] = 13; values[1] = 0;
        m_dictionary['╜'] = CharacterXYDescriptor(typeLines, values);

        // '╛'
        values[0] = 14; values[1] = 0;
        m_dictionary['╛'] = CharacterXYDescriptor(typeLines, values);

        // '┐'
        values[0] = 15; values[1] = 0;
        m_dictionary['┐'] = CharacterXYDescriptor(typeLines, values);

        // '└'
        values[0] = 0; values[1] = 1;
        m_dictionary['└'] = CharacterXYDescriptor(typeLines, values);

        // '┴'
        values[0] = 1; values[1] = 1;
        m_dictionary['┴'] = CharacterXYDescriptor(typeLines, values);

        // '┬'
        values[0] = 2; values[1] = 1;
        m_dictionary['┬'] = CharacterXYDescriptor(typeLines, values);

        // '├'
        values[0] = 3; values[1] = 1;
        m_dictionary['├'] = CharacterXYDescriptor(typeLines, values);

        // '─'
        values[0] = 4; values[1] = 1;
        m_dictionary['─'] = CharacterXYDescriptor(typeLines, values);

        // '┼'
        values[0] = 5; values[1] = 1;
        m_dictionary['┼'] = CharacterXYDescriptor(typeLines, values);

        // '╞'
        values[0] = 6; values[1] = 1;
        m_dictionary['╞'] = CharacterXYDescriptor(typeLines, values);

        // '╟'
        values[0] = 7; values[1] = 1;
        m_dictionary['╟'] = CharacterXYDescriptor(typeLines, values);

        // '╚'
        values[0] = 8; values[1] = 1;
        m_dictionary['╚'] = CharacterXYDescriptor(typeLines, values);

        // '╔'
        values[0] = 9; values[1] = 1;
        m_dictionary['╔'] = CharacterXYDescriptor(typeLines, values);

        // '╩'
        values[0] = 10; values[1] = 1;
        m_dictionary['╩'] = CharacterXYDescriptor(typeLines, values);

        // '╦'
        values[0] = 11; values[1] = 1;
        m_dictionary['╦'] = CharacterXYDescriptor(typeLines, values);

        // '╠'
        values[0] = 12; values[1] = 1;
        m_dictionary['╠'] = CharacterXYDescriptor(typeLines, values);

        // '═'
        values[0] = 13; values[1] = 1;
        m_dictionary['═'] = CharacterXYDescriptor(typeLines, values);

        // '╬'
        values[0] = 14; values[1] = 1;
        m_dictionary['╬'] = CharacterXYDescriptor(typeLines, values);

        // '╧'
        values[0] = 15; values[1] = 1;
        m_dictionary['╧'] = CharacterXYDescriptor(typeLines, values);

        // '╨'
        values[0] = 0; values[1] = 2;
        m_dictionary['╨'] = CharacterXYDescriptor(typeLines, values);

        // '╤'
        values[0] = 1; values[1] = 2;
        m_dictionary['╤'] = CharacterXYDescriptor(typeLines, values);

        // '╥'
        values[0] = 2; values[1] = 2;
        m_dictionary['╥'] = CharacterXYDescriptor(typeLines, values);

        // '╙'
        values[0] = 3; values[1] = 2;
        m_dictionary['╙'] = CharacterXYDescriptor(typeLines, values);

        // '╘'
        values[0] = 4; values[1] = 2;
        m_dictionary['╘'] = CharacterXYDescriptor(typeLines, values);

        // '╒'
        values[0] = 5; values[1] = 2;
        m_dictionary['╒'] = CharacterXYDescriptor(typeLines, values);

        // '╓'
        values[0] = 6; values[1] = 2;
        m_dictionary['╓'] = CharacterXYDescriptor(typeLines, values);

        // '╫'
        values[0] = 7; values[1] = 2;
        m_dictionary['╫'] = CharacterXYDescriptor(typeLines, values);

        // '╪'
        values[0] = 8; values[1] = 2;
        m_dictionary['╪'] = CharacterXYDescriptor(typeLines, values);

        // '┘'
        values[0] = 9; values[1] = 2;
        m_dictionary['┘'] = CharacterXYDescriptor(typeLines, values);

        // '┌'
        values[0] = 10; values[1] = 2;
        m_dictionary['┌'] = CharacterXYDescriptor(typeLines, values);
    }


    CharacterXYDescriptor CharacterXYDictionary::GetXYFromCharacter(const char character) const
    {
        return m_dictionary.at(character);
    }

} }
