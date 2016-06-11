
#ifndef ENTITIES_ENTITIESMANAGER_H
#define ENTITIES_ENTITIESMANAGER_H

// Components
#include "TransformationComponent.h"

// Entities
#include "TextEntity.h"

// Math
#include "Vector2D.h"

// std
#include <list>


#define ENTITIESMANAGERINSTANCE MIMIc::Entities::Managers::EntitiesManager::INSTANCE()


namespace MIMIc { namespace Entities { namespace Managers {

    class EntitiesManager
    {
        public:
            static EntitiesManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();

            TextEntity* const CreateTextEntity(const char* const style, const char character, const int renderPassId);
            TextEntity* const CreateTextEntity(const Math::Vector2D& position, 
                                               const float rotation, 
                                               const Math::Vector2D& scale,
                                               const Math::Vector2D& velocity, 
                                               const char* const style,
                                               const char character,
                                               const int renderPassId);
            
        private:
            EntitiesManager();
            EntitiesManager(const EntitiesManager& rhs); // undefined; singleton
            EntitiesManager& operator=(const EntitiesManager& rhs); // undefined; singleton

            template <typename T>
            struct EntityAndTransformation
            {
                char m_entity[sizeof(T)];
                Components::TransformationComponent m_transformationComponent;
            };

            static EntitiesManager* s_instance;
            std::list<EntityAndTransformation<TextEntity>> m_textEntities;
    };
    
} } }

#include "EntitiesManager.inl"

#endif
