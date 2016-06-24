
#ifndef ENTITIES_ENTITIESMANAGER_H
#define ENTITIES_ENTITIESMANAGER_H

// DataModel
#include "WordDescriptor.h"

// Components
#include "TransformationComponent.h"

// Messages
#include "MessageListener.h"

// Entities
#include "Entity.h"

// Math
#include "Vector2D.h"

// std
#include <list>


#define ENTITIESMANAGERINSTANCE MIMIc::Entities::Managers::EntitiesManager::INSTANCE()


namespace MIMIc { namespace Entities { namespace Managers {

    class EntitiesManager : public Messages::MessageListener
    {
        public:
            static EntitiesManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();
            
            virtual void Process(Messages::Types::CreateTextEntity* message) override;
            Entity* const CreateTextEntity(const Math::Vector2D& position, 
                                           const float rotation, 
                                           const Math::Vector2D& scale,
                                           const Math::Vector2D& velocity, 
                                           const DataModel::WordDescriptor& text,
                                           const int renderPassId);
            
        private:
            EntitiesManager();
            EntitiesManager(const EntitiesManager& rhs); // undefined; singleton
            EntitiesManager& operator=(const EntitiesManager& rhs); // undefined; singleton

            static EntitiesManager* s_instance;

            template <typename T>
            struct EntityAndTransformation
            {
                char m_entity[sizeof(T)];
                char m_transformationComponent[sizeof(Components::TransformationComponent)];
            };

            std::list<EntityAndTransformation<Entity>> m_textEntities;
    };
    
} } }

#include "EntitiesManager.inl"

#endif
