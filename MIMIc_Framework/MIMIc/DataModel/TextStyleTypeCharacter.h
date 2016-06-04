
#ifndef DATAMODEL_TEXTSTYLETYPECHARACTER_H
#define DATAMODEL_TEXTSTYLETYPECHARACTER_H

#define CHARACTERDATA unsigned


namespace MIMIc { namespace DataModel {

    class TextStyleTypeCharacter
    {
        public:
            TextStyleTypeCharacter();
            TextStyleTypeCharacter(CHARACTERDATA* const data, const unsigned characterWidth, const unsigned characterHeight, const unsigned x, const unsigned y);
            TextStyleTypeCharacter(const TextStyleTypeCharacter& rhs);
            ~TextStyleTypeCharacter();

            TextStyleTypeCharacter& operator=(const TextStyleTypeCharacter& rhs);
            
            const unsigned X() const;
            const unsigned Y() const;
            const unsigned GetCharacterWidth() const;
            const unsigned GetCharacterHeight() const;
            const unsigned GetDataLength() const;
            const CHARACTERDATA* const GetData() const;
            CHARACTERDATA* GetDataForEditing();

        private:
            CHARACTERDATA* m_data;
            unsigned m_x,
                     m_y,
                     m_characterWidth,
                     m_characterHeight;
            bool m_edited;

            void SetData(CHARACTERDATA* const texture, const unsigned textureWidth, const unsigned textureHeight, const bool edited);
            void DeleteData();
    };

} }

#endif
