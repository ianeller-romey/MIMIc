
#ifndef MESSAGES_MESSAGEMEMORYMANAGER_H
#define MESSAGES_MESSAGEMEMORYMANAGER_H


#define MESSAGEMEMORYMANAGERINSTANCE MIMIc::Messages::Managers::MessageMemoryManager::INSTANCE()


namespace MIMIc { namespace Messages { namespace Managers {

    class MessageMemoryManager
    {
        public:
            static MessageMemoryManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();

            void* Allocate(size_t size);
            void FreeAll();

        private:
            static const unsigned c_pageSize;

            MessageMemoryManager();
            MessageMemoryManager(const MessageMemoryManager& rhs); // undefined; singleton
            MessageMemoryManager& operator=(const MessageMemoryManager& rhs); // undefined; singleton

            static MessageMemoryManager* s_instance;

            struct MemoryPage
            {
                MemoryPage* m_next;
                char *m_firstBlock,
                     *m_currentBlock;
            };
            MemoryPage* m_pages;

            MemoryPage* CreatePage();
            void InitializePage(MemoryPage* page);
            void* AllocateFromPage(MemoryPage* page, size_t size);
            void FreePage(MemoryPage* page);
            void ShutdownPage(MemoryPage* page);
    };

} } }

#endif
