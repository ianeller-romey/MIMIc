
#ifndef BEHAVIORS_BEHAVIORSMANAGER_H
#define BEHAVIORS_BEHAVIORSMANAGER_H

// Components
#include "TransformationComponent.h"

// Messages
#include "MessageTypes.h"
#include "MessageListener.h"

// std
#include <list>


#define BEHAVIORSMANAGERINSTANCE MIMIc::Behaviors::Managers::BehaviorsManager::INSTANCE()


namespace MIMIc { namespace Behaviors { namespace Managers {

    class BehaviorsManager : public Messages::MessageListener
    {
        public:
            static BehaviorsManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();
            
        private:
            BehaviorsManager();
            BehaviorsManager(const BehaviorsManager& rhs); // undefined; singleton
            BehaviorsManager& operator=(const BehaviorsManager& rhs); // undefined; singleton

            static BehaviorsManager* s_instance;
    };
    
} } }

#include "BehaviorsManager.inl"

#endif
