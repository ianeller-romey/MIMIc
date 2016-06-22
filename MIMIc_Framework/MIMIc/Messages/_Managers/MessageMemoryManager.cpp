
// Messages
#include "MessageMemoryManager.h"


namespace MIMIc { namespace Messages { namespace Managers {

    const unsigned MessageMemoryManager::c_pageSize = 1024;


    MessageMemoryManager* MessageMemoryManager::s_instance = 0;


    MessageMemoryManager& MessageMemoryManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new MessageMemoryManager();

        return *s_instance;
    }


    MessageMemoryManager::MessageMemoryManager() :
        m_pages(0)
    {
    }


    bool MessageMemoryManager::Initialize()
    {
        m_pages = CreatePage();
        return true;
    }


    void MessageMemoryManager::Update()
    {
    }


    bool MessageMemoryManager::Shutdown()
    {
        while(m_pages)
        {
            auto temp = m_pages->m_next;
            ShutdownPage(m_pages);
            m_pages = temp;
        }
        return true;
    }

    void* MessageMemoryManager::Allocate(size_t size)
    {
        return AllocateFromPage(m_pages, size);
    }


    void MessageMemoryManager::FreeAll()
    {
        auto temp = m_pages;
        while(temp)
        {
            FreePage(temp);
            temp = temp->m_next;
        }
    }


    MessageMemoryManager::MemoryPage* MessageMemoryManager::CreatePage()
    {
        auto page = new MemoryPage();
        InitializePage(page);
        return page;
    }


    void MessageMemoryManager::InitializePage(MemoryPage* page)
    {
        page->m_firstBlock = new char[c_pageSize];
        page->m_currentBlock = page->m_firstBlock;
        page->m_next = 0;
    }


    void* MessageMemoryManager::AllocateFromPage(MemoryPage* page, size_t size)
    {
        if(page->m_currentBlock + size > page->m_firstBlock + c_pageSize)
        {
            auto newPage = CreatePage();
            page->m_next = newPage;
            page = newPage;
        }

        auto block = page->m_currentBlock;
        page->m_currentBlock += size;
        return block;
    }


    void MessageMemoryManager::FreePage(MemoryPage* page)
    {
        page->m_currentBlock = page->m_firstBlock;
    }


    void MessageMemoryManager::ShutdownPage(MemoryPage* page)
    {
        delete [] page->m_firstBlock;
        page->m_firstBlock = 0;
        page->m_currentBlock = 0;
        page->m_next = 0;
    }

} } }
