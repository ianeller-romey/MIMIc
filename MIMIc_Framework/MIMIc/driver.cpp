
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


void init()
{
    WINDOWMANAGERINSTANCE.Initialize();
    GRAPHICSMANAGERINSTANCE.Initialize();

    auto window = WINDOWMANAGERINSTANCE.CreateWindow("TEST", 100, 100, 640, 480);
    auto renderPass = GRAPHICSMANAGERINSTANCE.CreateRenderPass<MIMIc::Graphics::TextRenderPass>(window);
    auto renderPassId = renderPass->GetId();

    auto entity = ENTITIESMANAGERINSTANCE.CreateTextEntity("C:\\Users\\v-iaelle\\Documents\\GitHub\\MIMIc\\data\\dat\\text_0_0.dat", renderPassId);
}


void update()
{
    while(true)
    {
        WINDOWMANAGERINSTANCE.Update();
        GRAPHICSMANAGERINSTANCE.Update();
    }
}


int main()
{
    init();

    update();
}