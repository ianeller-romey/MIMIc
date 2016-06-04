
#ifndef GRAPHICS_TEXTTEXTURE_H
#define GRAPHICS_TEXTTEXTURE_H

#define TEXTTEXTURECHAR unsigned


namespace MIMIc { namespace Graphics {

    class TextTexture
    {
        public:
            TextTexture();
            TextTexture(TEXTTEXTURECHAR* const texture, const unsigned textureWidth, const unsigned textureHeight);
            TextTexture(const TextTexture& rhs);
            ~TextTexture();

            TextTexture& operator=(const TextTexture& rhs);

            const unsigned GetTextureWidth() const;
            const unsigned GetTextureHeight() const;
            const unsigned GetTextureLength() const;
            const TEXTTEXTURECHAR* const GetTexture() const;
            TEXTTEXTURECHAR* GetTextureForEditing();

        private:
            TEXTTEXTURECHAR* m_texture;
            unsigned m_textureWidth,
                     m_textureHeight;
            bool m_edited;

            void SetTexture(TEXTTEXTURECHAR* const texture, const unsigned textureWidth, const unsigned textureHeight, const bool edited);
            void DeleteTexture();
    };

} }

#endif
