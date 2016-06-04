
// Entities
#include "EntitiesManager.h"

// Graphics
#include "GraphicsManager.h"


namespace MIMIc { namespace Entities { namespace Managers {

    EntitiesManager* EntitiesManager::s_instance = NULL;


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
    }


    bool EntitiesManager::Shutdown()
    {
        for(auto begin = m_textEntities.begin(), end = m_textEntities.end(); begin != end; ++begin)
        {
            auto et = *begin;
            delete (TextEntity*)(et.m_entity);
        }

        return true;
    }


    TextEntity* const EntitiesManager::CreateTextEntity(const char* const textTexture, const int renderPassId)
    {
        m_textEntities.push_back(EntityAndTransformation<TextEntity>());
        auto et = m_textEntities.back();

        auto graphicsComponent = GRAPHICSMANAGERINSTANCE.CreateTextTextureGraphicsComponent(&et.m_transformationComponent, textTexture, renderPassId);

        new (et.m_entity) TextEntity(&et.m_transformationComponent, graphicsComponent);

        return (TextEntity*)(&et.m_entity);
    }


    TextEntity* const EntitiesManager::CreateTextEntity(const Math::Vector2D& position, 
                                                        const float rotation, 
                                                        const Math::Vector2D& scale,
                                                        const Math::Vector2D& velocity, 
                                                        const char* const textTexture, 
                                                        const int renderPassId)
    {
        m_textEntities.push_back(EntityAndTransformation<TextEntity>());
        auto et = m_textEntities.back();

        et.m_transformationComponent = Components::TransformationComponent(position, rotation, scale, velocity);

        auto graphicsComponent = GRAPHICSMANAGERINSTANCE.CreateTextTextureGraphicsComponent(&et.m_transformationComponent, textTexture, renderPassId);

        new (et.m_entity) TextEntity(&et.m_transformationComponent, graphicsComponent);

        return (TextEntity*)(&et.m_entity);
    }

} } }
