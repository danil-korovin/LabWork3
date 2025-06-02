/* Korovin Danil st128737@student.spbu.ru
   LabWork3
*/
#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <iterator>
#include <stdexcept>


template <typename T> class circ_list
{
private:
    struct node
    {
        T data;
        std::shared_ptr<node> next; //shared_ptr for memory management
        std::shared_ptr<node> prev;
        node(const T& value) : data(value), next(nullptr), prev(nullptr) {} // copy constructor
        node(T&& value) : data(std::move(value)), next(nullptr), prev(nullptr) {} // move constructor
    };
    std::shared_ptr<node> head; // pointer to the head of the list
    size_t lsize;

public:
    circ_list() : head(nullptr), lsize(0) {} // default constructor
    circ_list(std::initializer_list<T> init_list) : head(nullptr), lsize(0)   // constructor with initializer list
    {
        for (const auto& value : init_list)
        {
            push_back(value);
        }
    }
    circ_list(const circ_list& other) : head(nullptr), lsize(0)   // copy constructor
    {
        if (other.empty())
        {
            return;
        }
        std::shared_ptr<node> cur = other.head;
        do
        {
            push_back(cur->data);
            cur = cur->next;
        }
        while (cur != other.head);
    }
    circ_list(circ_list&& other) noexcept : head(std::move(other.head)), lsize(other.lsize)   // move constructor
    {
        other.lsize = 0;
    }
    ~circ_list()   // destructor
    {
        clear();
    }
    circ_list& operator=(const circ_list& other)   // copy assignment operator
    {
        if (this != &other)
        {
            circ_list temp(other);
            std::swap(head, temp.head);
            std::swap(lsize, temp.lsize);
        }
        return *this;
    }
    circ_list& operator=(circ_list&& other) noexcept   // move assignment operator
    {
        clear();
        head = std::move(other.head);
        lsize = other.lsize;
        other.lsize = 0;
        return *this;
    }
    T& front()   //reference to the first element
    {
        if (empty())
        {
            throw std::out_of_range("Error: front called empty list!");
        }
        return head->data;
    }
    const T& front() const   // const reference to the first element
    {
        if (empty())
        {
            throw std::out_of_range("Error: front called empty list!");
        }
        return head->data;
    }
    T& back()    // reference to the last element
    {
        if (empty())
        {
            throw std::out_of_range("Error: back called empty list!");
        }
        return head->prev->data;
    }
    const T& back() const   // const reference to the last element
    {
        if (empty())
        {
            throw std::out_of_range("Error: back called empty list!");
        }
        return head->prev->data;
    }
    bool empty() const   // check for empty
    {
        return lsize == 0;
    }
    size_t size() const   // size
    {
        return lsize;
    }
    void clear()   // removes all elements
    {
        if (empty())
        {
            return;
        }
        std::shared_ptr<node> cur = head;
        std::shared_ptr<node> next;
        for (size_t i = 0; i < lsize; ++i)
        {
            next = cur->next;
            cur = next;
        }
        head = nullptr;
        lsize = 0;
    }
    void push_back(const T& value)   // add element to the end
    {
        auto s = std::make_shared<node>(value);
        if (empty())
        {
            head = s;
            head->next = head;
            head->prev = head;
        }
        else
        {
            s->next = head;
            s->prev = head->prev;
            head->prev->next = s;
            head->prev = s;
        }
        ++lsize;
    }
    void push_back(T&& value)    // move adds element to the end of the list ( version)
    {
        auto s = std::make_shared<node>(std::move(value));
        if (empty())
        {
            head = s;
            head->next = head;
            head->prev = head;
        }
        else
        {
            s->next = head;
            s->prev = head->prev;
            head->prev->next = s;
            head->prev = s;
        }

        ++lsize;
    }
    void push_front(const T& value)   // adds an element to the beginning
    {
        auto s = std::make_shared<node>(value);
        if (empty())
        {
            head = s;
            head->next = head;
            head->prev = head;
        }
        else
        {
            s->next = head;
            s->prev = head->prev;
            head->prev->next = s;
            head->prev = s;
            head = s;
        }

        ++lsize;
    }
    void push_front(T&& value)   // move add an element to the beginning
    {
        auto s = std::make_shared<node>(std::move(value));
        if (empty())
        {
            head = s;
            head->next = head;
            head->prev = head;
        }
        else
        {
            s->next = head;
            s->prev = head->prev;
            head->prev->next = s;
            head->prev = s;
            head = s;
        }
        ++lsize;
    }
    void pop_back()    // removes the last element
    {
        if (empty())
        {
            throw std::out_of_range("Error: pop_back called empty list!");
        }
        if (lsize == 1)
        {
            head = nullptr;
        }
        else
        {
            auto last = head->prev;
            head->prev = last->prev;
            last->prev->next = head;
        }
        --lsize;
    }

    void pop_front()   // removes the first element
    {
        if (empty())
        {
            throw std::out_of_range("Error: pop_front called empty list!");
        }
        if (lsize == 1)
        {
            head = nullptr;
        }
        else
        {
            auto old_head = head;
            head = head->next;
            head->prev = old_head->prev;
            old_head->prev->next = head;
        }
        --lsize;
    }
    void copy(const circ_list& other)   // Copy
    {
        clear();
        if (other.empty())
        {
            return;
        }
        auto it = other.begin();
        auto start = other.begin();
        do
        {
            push_back(*it);
            ++it;
            if (it == other.end())
            {
                break;
            }
        }
        while (it != start);
    }
    bool operator==(const circ_list& other) const   // compare (equality)
    {
        if (size() != other.size())
        {
            return false;
        }
        if (empty())
        {
            return true;
        }
        auto it1 = begin();
        auto it2 = other.begin();
        do
        {
            if (*it1 != *it2)
            {
                return false;
            }
            ++it1;
            ++it2;
            if (it1 == end() || it2 == other.end())
            {
                break;
            }
        }
        while (it1 != begin());
        return true;
    }
    bool operator!=(const circ_list& other) const   // compare (inequality)
    {
        return !(*this == other);
    }
    void reverse_copy(const circ_list& other)   // reverse copy
    {
        clear();
        std::vector<T> temp;
        if (other.empty())
        {
            return;
        }
        auto it = other.begin();
        auto start = other.begin();
        do
        {
            temp.push_back(*it);
            ++it;
            if (it == other.end()) break;
        }
        while (it != start);
        std::reverse(temp.begin(), temp.end());
        for (const auto& element : temp)
        {
            push_back(element);
        }
    }
    class iterator
    {
    public:
        iterator() : cur(nullptr) {}  // default constructor for end iterator
        explicit iterator(std::shared_ptr<node> node_ptr) : cur(node_ptr) {}  // constructor for an iterator
        T& operator*() const   // dereference operator
        {
            if (!cur)
            {
                throw std::runtime_error("Error: dereferencing a null iterator!");
            }
            return cur->data;
        }
        T* operator->() const    // access operator
        {
            if (!cur)
            {
                throw std::runtime_error("Error: dereferencing a null iterator!");
            }
            return &(cur->data);
        }
        iterator& operator--()    // prefix decrement operator
        {
            if (!cur)
            {
                throw std::runtime_error("Error: decrementing a null iterator!");
            }
            cur = cur->prev;
            return *this;
        }
        iterator operator--(int)   // postfix decrement operator
        {
            iterator temp = *this;
            --(*this);
            return temp;
        }
        iterator& operator++()   // prefix increment operator
        {
            if (!cur)
            {
                throw std::runtime_error("Error: incrementing a null iterator!");
            }
            cur = cur->next;
            return *this;
        }
        iterator operator++(int)   // postfix increment operator
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const iterator& other) const   // equality operator
        {
            return cur == other.cur;
        }
        bool operator!=(const iterator& other) const   // inequality operator
        {
            return !(*this == other);
        }
        void swap(iterator& other)   // swap iterators
        {
            std::swap(cur, other.cur);
        }
    private:
        std::shared_ptr<node> cur; // pointer to current node
        friend class circ_list<T>; // give circ_list access to private
    };

    iterator begin()   // iterator to the beginning
    {
        return iterator(head);
    }
    iterator end()   // iterator to the end
    {
        return iterator(nullptr);
    }
    const iterator begin() const   // const begin
    {
        return iterator(head);
    }
    const iterator end() const    // const end
    {
        return iterator(nullptr);
    }
    iterator insert(iterator pos, const T& value)   // inserts element before position of iterator
    {
        if (pos == end())
        {
            push_back(value);
            return --end();
        }
        auto s = std::make_shared<node>(value);
        auto cur = pos.cur;
        s->next = cur;
        s->prev = cur->prev;
        cur->prev->next = s;
        cur->prev = s;
        if (cur == head)
        {
            head = s;
        }
        ++lsize;
        return iterator(s);
    }
    iterator insert(iterator pos, T&& value)   // move inserts element before position of iterator
    {
        if (pos == end())
        {
            push_back(std::move(value));
            return --end();
        }
        auto s = std::make_shared<node>(std::move(value));
        auto cur = pos.cur;
        s->next = cur;
        s->prev = cur->prev;
        cur->prev->next = s;
        cur->prev = s;
        if (cur == head)
        {
            head = s;
        }
        ++lsize;
        return iterator(s);
    }
    iterator erase(iterator pos)   // removes an element
    {
        if (pos == end())
        {
            throw std::out_of_range("Error: erase called end iterator!");
        }
        auto cur = pos.cur;
        auto next = cur->next;
        if (cur == head)
        {
            head = next;
        }
        cur->prev->next = next;
        cur->next->prev = cur->prev;
        --lsize;
        return iterator(next);
    }
    iterator find(const T& value)   // find an element
    {
        if (empty())
        {
            return end();
        }
        auto it = begin();
        auto start = begin();
        if (head == nullptr)
        {
            return end();
        }
        do
        {
            if (*it == value)
            {
                return it;
            }
            if (it.cur == head->prev)
            {
                return end();
            }
            ++it;
            if (it == end())
            {
                return end();
            }
        }
        while (it != start);
        return end();
    }
private:

};

#endif

