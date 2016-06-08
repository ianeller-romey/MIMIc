
#ifndef DATAMODEL_TEXTSTYLETYPECHARACTER_H
#define DATAMODEL_TEXTSTYLETYPECHARACTER_H

#define CHARACTERDATA char


namespace MIMIc { namespace DataModel {

    class TextStyleDeserializer;

} }


namespace MIMIc { namespace DataModel {

    class TextStyleTypeCharacter
    {
        friend TextStyleDeserializer;

        public:
            TextStyleTypeCharacter();
            TextStyleTypeCharacter(CHARACTERDATA* const data, const char characterWidth, const char characterHeight, const char x, const char y);
            TextStyleTypeCharacter(const TextStyleTypeCharacter& rhs);
            ~TextStyleTypeCharacter();

            TextStyleTypeCharacter& operator=(const TextStyleTypeCharacter& rhs);
            
            const char X() const;
            const char Y() const;
            const char GetCharacterWidth() const;
            const char GetCharacterHeight() const;
            const char GetDataLength() const;
            const CHARACTERDATA* const GetData() const;
            CHARACTERDATA* GetDataForEditing();

        private:
            CHARACTERDATA* m_data;
            char m_x,
                 m_y,
                 m_characterWidth,
                 m_characterHeight;
            bool m_edited;

            void SetData(CHARACTERDATA* const texture, const char textureWidth, const char textureHeight, const bool edited);
            void DeleteData();
    };

} }

#endif
