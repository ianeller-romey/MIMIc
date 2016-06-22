
// Behaviors
#include "BehaviorsManager.h"

// Graphics
#include "GraphicsManager.h"


namespace MIMIc { namespace Behaviors { namespace Managers {

    BehaviorsManager* BehaviorsManager::s_instance = 0;


    BehaviorsManager& BehaviorsManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new BehaviorsManager();

        return *s_instance;
    }


    BehaviorsManager::BehaviorsManager()
    {
    }


    bool BehaviorsManager::Initialize()
    {
        return true;
    }


    void BehaviorsManager::Update()
    {
    }


    bool BehaviorsManager::Shutdown()
    {
        return true;
    }

} } }
