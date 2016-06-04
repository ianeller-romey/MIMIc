
#ifndef GRAPHICS_SHADER_H
#define GRAPHICS_SHADER_H


namespace MIMIc { namespace Graphics {

    class Shader
    {
        public:
            Shader();
            Shader(const char* content);
            Shader(const Shader& rhs);
            ~Shader();

            Shader& operator=(const Shader& rhs);

            const char* const GetContent() const;

        private:
            char* m_content;
            unsigned m_contentLength;

            void SetContent(const char* const content, const unsigned contentLength);
            void DeleteContent();
    };

} }

#endif
