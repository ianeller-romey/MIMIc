
// Entities
#include "EntitiesManager.h"

// Graphics
#include "GraphicsManager.h"


namespace MIMIc { namespace Entities { namespace Managers {

    EntitiesManager* EntitiesManager::s_instance = 0;


    EntitiesManager& EntitiesManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new EntitiesManager();

        return *s_instance;
    }


    EntitiesManager::EntitiesManager()
    {
    }


    bool EntitiesManager::Initialize()
    {
        return true;
    }


    void EntitiesManager::Update()
    {
        for(auto begin = m_textEntities.begin(), end = m_textEntities.end(); begin != end; ++begin)
        {
            auto et = *begin;
            ((Components::TransformationComponent*)et.m_transformationComponent)->Update();
        }
    }


    bool EntitiesManager::Shutdown()
    {
        for(auto begin = m_textEntities.begin(), end = m_textEntities.end(); begin != end; ++begin)
        {
            auto et = *begin;
            delete (Entity*)(et.m_entity);
        }

        return true;
    }


    void EntitiesManager::Process(Messages::Types::CreateTextEntity* message)
    {
        CreateTextEntity(message->m_transformation.m_position, 
                         message->m_transformation.m_rotation, 
                         message->m_transformation.m_scale,
                         message->m_transformation.m_velocity,
                         message->m_style.c_str(),
                         message->m_text[0],
                         message->m_renderPassId);
    }


    Entity* const EntitiesManager::CreateTextEntity(const Math::Vector2D& position, 
                                                        const float rotation, 
                                                        const Math::Vector2D& scale,
                                                        const Math::Vector2D& velocity, 
                                                        const char* const style,
                                                        const char text,
                                                        const int renderPassId)
    {
        m_textEntities.push_back(EntityAndTransformation<Entity>());
        auto et = m_textEntities.back();

        auto entity = new (et.m_entity) Entity();
        auto transformation = new (et.m_transformationComponent) Components::TransformationComponent(entity->GetId(), position, rotation, scale, velocity);

        auto graphicsComponent = GRAPHICSMANAGERINSTANCE.CreateTextCharacterGraphicsComponent(entity->GetId(), transformation, style, text, renderPassId);
        entity->m_graphicsComponent = graphicsComponent;

        return (Entity*)(&et.m_entity);
    }

} } }
