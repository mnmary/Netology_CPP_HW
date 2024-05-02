//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>

//проверяемая функция
#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

//юнит-тест
TEST_CASE( "List test", "[List]" ) {
    int retValue = 0;
    List myList;
    //section 1
    SECTION("list empty test")
    {
        CHECK(myList.Empty() == true);
    }
    SECTION("list empty size test")
    {
        CHECK(myList.Size() == 0);
    }
    SECTION("List clear test")
    {
        myList.Clear();
        CHECK(myList.Empty() == true);
    }
    SECTION("List pushFront test") 
    {
        myList.Clear();
        myList.PushFront(1);
        CHECK(myList.Empty() == false);
        CHECK(myList.Size() == 1);
    }
    SECTION("List pushBack test")
    {
        myList.Clear();
        myList.PushBack(10);
        CHECK(myList.Empty() == false);
        CHECK(myList.Size() == 1);
    }
    SECTION("List popBack test(empty list)")
    {
        myList.Clear();
        CHECK_THROWS_AS(myList.PopBack(),std::runtime_error);
        CHECK(myList.Empty() == true);
    }
    SECTION("List popFront test(empty list)")
    {
        myList.Clear();
        CHECK_THROWS_AS(myList.PopFront(), std::runtime_error);
        CHECK(myList.Empty() == true);
    }
    SECTION("List pushBack test")
    {
        myList.PushBack(10);
        myList.PushBack(20);
        CHECK(myList.Size() == 2);
    }
    SECTION("List popBack test")
    {
        myList.PushBack(10);
        myList.PushBack(20);
        retValue = myList.PopBack();
        CHECK(myList.Size() == 1);
        CHECK(retValue == 20);
        retValue = myList.PopBack();
        CHECK(retValue == 10);
        CHECK(myList.Empty() == true);
    }
    SECTION("List pushFront test")
    {
        myList.Clear();
        myList.PushFront(30);
        myList.PushFront(40);
        CHECK(myList.Size() == 2);
    }
    SECTION("List popFront test")
    {
        myList.PushFront(30);
        myList.PushFront(40);
        retValue = myList.PopFront();
        CHECK(myList.Size() == 1);
        CHECK(retValue == 40);
        retValue = myList.PopFront();
        CHECK(myList.Empty() == true);
        CHECK(retValue == 20);
    }
}