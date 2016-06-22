
#ifndef COMPONENTS_COMPONENT_H
#define COMPONENTS_COMPONENT_H


namespace MIMIc { namespace Components {

    class Component
    {
        public:
            Component(const long entityId);
            Component(const Component& rhs);
            virtual ~Component();
            
            virtual void Update() = 0;

            const long GetEntityId() const;

        protected:
            const long m_entityId;

        private:
    };

} }

#endif
