
// Messages
#include "MessageManager.h";
#include "MessageMemoryManager.h";

// Framework
#include "WindowManager.h"

// Entities
#include "EntitiesManager.h"

// Graphics
#include "GraphicsManager.h"
#include "TextRenderPass.h"

// Math
#include "Vector2D.h"


using namespace MIMIc;


void test()
{
    auto window = WINDOWMANAGERINSTANCE.CreateWindow("TEST", 100, 100, 640, 480);
    auto renderPass = GRAPHICSMANAGERINSTANCE.CreateRenderPass<MIMIc::Graphics::TextRenderPass>(window);
    auto renderPassId = renderPass->GetId();

    auto transformation = TransformationDataForMessage();

    transformation.m_position.X(0);
    transformation.m_position.Y(0);
    auto message = new Messages::Types::CreateTextEntity("C:\\Users\\v-iaelle\\Documents\\GitHub\\MIMIc\\data\\dat\\default.dat", "a", transformation, renderPassId);
    MAILMAN.PostMessage(message);

    transformation.m_position.X(20);
    transformation.m_position.Y(20);
    message = new Messages::Types::CreateTextEntity("C:\\Users\\v-iaelle\\Documents\\GitHub\\MIMIc\\data\\dat\\default.dat", "b", transformation, renderPassId);
    MAILMAN.PostMessage(message);

    transformation.m_position.X(40);
    transformation.m_position.Y(40);
    message = new Messages::Types::CreateTextEntity("C:\\Users\\v-iaelle\\Documents\\GitHub\\MIMIc\\data\\dat\\default.dat", "c", transformation, renderPassId);
    MAILMAN.PostMessage(message);

    transformation.m_position.X(60);
    transformation.m_position.Y(60);
    message = new Messages::Types::CreateTextEntity("C:\\Users\\v-iaelle\\Documents\\GitHub\\MIMIc\\data\\dat\\default.dat", "d", transformation, renderPassId);
    MAILMAN.PostMessage(message);

    transformation.m_position.X(80);
    transformation.m_position.Y(80);
    message = new Messages::Types::CreateTextEntity("C:\\Users\\v-iaelle\\Documents\\GitHub\\MIMIc\\data\\dat\\default.dat", "e", transformation, renderPassId);
    MAILMAN.PostMessage(message);
}


void init()
{
    // Initialize Messages
    MESSAGEMEMORYMANAGERINSTANCE.Initialize();
    MAILMAN.Initialize();

    // Initialize Framework
    WINDOWMANAGERINSTANCE.Initialize();

    // Initialize Entities
    ENTITIESMANAGERINSTANCE.Initialize();

    // Initialize Graphics
    GRAPHICSMANAGERINSTANCE.Initialize();
}


void update()
{
    while(true)
    {
        MAILMAN.Update();
        WINDOWMANAGERINSTANCE.Update();
        ENTITIESMANAGERINSTANCE.Update();
        GRAPHICSMANAGERINSTANCE.Update();
    }
}


int main()
{
    init();

    test();

    update();
}