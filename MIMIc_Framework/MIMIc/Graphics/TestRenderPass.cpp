
#include "TestRenderPass.h"

#include "SDL.h"
#include "glew.h"
#include "SDL_opengl.h"


namespace MIMIc { namespace Graphics {

    TestRenderPass::TestRenderPass() :
        RenderPass(),
        m_glProgramId(-1),
        m_glVBO(-1),
        m_glIBO(-1),
        m_glVertexAttribute_Position(-1)
    {
    }


    TestRenderPass::TestRenderPass(Framework::Window* window) :
        RenderPass(window),
        m_glProgramId(-1),
        m_glVBO(-1),
        m_glIBO(-1),
        m_glVertexAttribute_Position(-1)
    {
    }


    TestRenderPass::TestRenderPass(const TestRenderPass& rhs) :
        RenderPass(rhs),
        m_glProgramId(rhs.m_glProgramId),
        m_glVBO(rhs.m_glVBO),
        m_glIBO(rhs.m_glIBO),
        m_glVertexAttribute_Position(rhs.m_glVertexAttribute_Position)
    {
    }


    TestRenderPass::~TestRenderPass()
    {
    }


    TestRenderPass& TestRenderPass::operator=(const TestRenderPass& rhs)
    {
        m_window = rhs.m_window;
        m_glContext = rhs.m_glContext;
        m_glProgramId = rhs.m_glProgramId;
        m_glVBO = rhs.m_glVBO;
        m_glIBO = rhs.m_glIBO;
        m_glVertexAttribute_Position = rhs.m_glVertexAttribute_Position;
        m_initialized = rhs.m_initialized;
        m_referenceCounter = rhs.m_referenceCounter;

        if(m_initialized && m_referenceCounter)
            ++(*m_referenceCounter);

        return *this;
    }


    void TestRenderPass::Update()
    {
        //Clear color buffer
        glClear( GL_COLOR_BUFFER_BIT );
    
        //Bind program
        glUseProgram( m_glProgramId );

        //Enable vertex position
        glEnableVertexAttribArray( m_glVertexAttribute_Position );

        //Set vertex data
        glBindBuffer( GL_ARRAY_BUFFER, m_glVBO );
        glVertexAttribPointer( m_glVertexAttribute_Position, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL );

        //Set index data and render
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_glIBO );
        glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL );

        //Disable vertex position
        glDisableVertexAttribArray( m_glVertexAttribute_Position );

        //Unbind program
        glUseProgram( NULL );

        SDL_GL_SwapWindow((SDL_Window*)m_window->GetSDLWindow());
    }


    bool TestRenderPass::InitializeOpenGL()
    {
        bool success = true;

        m_glProgramId = glCreateProgram();

        //Create vertex shader
        GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

        //Get vertex source
        const GLchar* vertexShaderSource[] =
        {
            "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
        };

        //Set vertex source
        glShaderSource( vertexShader, 1, vertexShaderSource, NULL );

        //Compile vertex source
        glCompileShader( vertexShader );

        //Check vertex shader for errors
        GLint vShaderCompiled = GL_FALSE;
        glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
        if( vShaderCompiled != GL_TRUE )
        {
            printf( "Unable to compile vertex shader %d!\n", vertexShader );
            //printShaderLog( vertexShader );
            success = false;
        }
        else
        {
            //Attach vertex shader to program
            glAttachShader( m_glProgramId, vertexShader );


            //Create fragment shader
            GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );

            //Get fragment source
            const GLchar* fragmentShaderSource[] =
            {
                "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
            };

            //Set fragment source
            glShaderSource( fragmentShader, 1, fragmentShaderSource, NULL );

            //Compile fragment source
            glCompileShader( fragmentShader );

            //Check fragment shader for errors
            GLint fShaderCompiled = GL_FALSE;
            glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled );
            if( fShaderCompiled != GL_TRUE )
            {
                printf( "Unable to compile fragment shader %d!\n", fragmentShader );
                //printShaderLog( fragmentShader );
                success = false;
            }
            else
            {
                //Attach fragment shader to program
                glAttachShader( m_glProgramId, fragmentShader );


                //Link program
                glLinkProgram( m_glProgramId );

                //Check for errors
                GLint programSuccess = GL_TRUE;
                glGetProgramiv( m_glProgramId, GL_LINK_STATUS, &programSuccess );
                if( programSuccess != GL_TRUE )
                {
                    printf( "Error linking program %d!\n", m_glProgramId );
                    //printProgramLog( m_glProgramId );
                    success = false;
                }
                else
                {
                    //Get vertex attribute location
                    m_glVertexAttribute_Position = glGetAttribLocation( m_glProgramId, "LVertexPos2D" );
                    if( m_glVertexAttribute_Position == -1 )
                    {
                        printf( "LVertexPos2D is not a valid glsl program variable!\n" );
                        success = false;
                    }
                    else
                    {
                        //Initialize clear color
                        glClearColor( 0.f, 0.f, 0.f, 1.f );

                        //VBO data
                        GLfloat vertexData[] =
                        {
                            -0.5f, -0.5f,
                             0.5f, -0.5f,
                             0.5f,  0.5f,
                            -0.5f,  0.5f
                        };

                        //IBO data
                        GLuint indexData[] = { 0, 1, 2, 3 };

                        //Create VBO
                        glGenBuffers( 1, &m_glVBO );
                        glBindBuffer( GL_ARRAY_BUFFER, m_glVBO );
                        glBufferData( GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );

                        //Create IBO
                        glGenBuffers( 1, &m_glIBO );
                        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_glIBO );
                        glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW );
                    }
                }
            }
        }
    
        return success;
    }

} }
