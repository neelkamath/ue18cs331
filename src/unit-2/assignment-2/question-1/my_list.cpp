#include <iostream>
#include <iterator>
#include <cstddef>

/** A doubly-linked list. */
template <typename T>
class my_list
{
public:
    struct node
    {
        struct node* prev;
        T data;
        struct node* next;

        node(T data) : prev(nullptr), data(data), next(nullptr)
        {
        }
    };

    struct iterator
    {
        using iterator_category = std::bidirectional_iterator_tag;

        iterator(struct node* pointer) : pointer(pointer)
        {
        }

        T& operator*() const
        {
            return pointer->data;
        }

        struct iterator& operator++()
        {
            pointer = pointer->next;
            return *this;
        }

        struct iterator operator++(int)
        {
            auto curr = *this;
            pointer = pointer->next;
            return curr;
        }

        struct iterator& operator--()
        {
            pointer = pointer->prev;
            return *this;
        }

        struct iterator operator--(int)
        {
            auto curr = *this;
            pointer = pointer->prev;
            return curr;
        }

        friend bool operator==(const struct iterator& lhs, const struct iterator& rhs)
        {
            return lhs.pointer == rhs.pointer;
        };

        friend bool operator!=(const iterator& lhs, const iterator& rhs)
        {
            return lhs.pointer != rhs.pointer;
        };
    private:
        struct node* pointer;
    };

    ~my_list()
    {
        for (auto* curr = head; head != nullptr; curr = head)
        {
            head = head->next;
            delete curr;
        }
    }

    struct iterator begin()
    {
        return iterator(head == nullptr ? nullptr : head);
    }

    struct iterator end()
    {
        return iterator(nullptr);
    }

    struct iterator rbegin()
    {
        for (auto* node = head; ; node = node->next)
            if (node == nullptr || node-> next == nullptr)
                return iterator(node);
    }

    struct iterator rend()
    {
        return iterator(nullptr);
    }

    /** Inserts the <element> as the first in the list. */
    void insert_first(T element)
    {
        auto* node = new struct node(element);
        node->next = head;
        if (head != nullptr)
            head->prev = node;
        head = node;
    }

    /** Throws an error if there isn't an element already existing at the <index>. */
    void insert(int index, T element)
    {
        auto* new_node = new struct node(element);
        if (head != nullptr && index == 0)
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
        }
        for (
            auto* curr_node = head, curr_index = 0;
            curr_node != nullptr && curr_node->next != nullptr;
            curr_node = curr_node->next, curr_index++
        )
            if (curr_index == index - 1)
            {
                new_node->prev = curr_node;
                new_node->next = curr_node->next;
                curr_node->next->prev = new_node;
                curr_node->next = new_node;
                return;
            }
        throw std::invalid_argument("Index out of bounds.");
    }

    /** Inserts the <element> as the last in the list. */
    void insert_last(T element)
    {
        auto* node = new struct node(element);
        if (head == nullptr)
            head = node;
        else
            for (auto* curr = head; ; curr = curr->next)
                if (curr->next == nullptr)
                {
                    curr->next = node;
                    node->prev = curr;
                    break;
                }
    }

    /** Returns the index of the <element>. Throws an error if the <element> doesn't exist. */
    int read(T element)
    {
        for (auto* curr = head, index = 0; curr != nullptr; curr = curr->next, index++)
            if (curr->data == element)
                return index;
        throw std::invalid_argument("No such element found.");
    }

    /** Sets the <index>'s data to the <element>. Throws an error if the <index> is out of bounds. */
    void update(int index, T element)
    {
        for (auto* curr = head, curr_index = 0; curr != nullptr; curr = curr->next, curr_index++)
            if (curr_index == index)
            {
                curr->data = element;
                return;
            }
        throw std::invalid_argument("Index out of bounds.");
    }

    /** Throws an error if the <index> is out of bounds. */
    void remove(int index)
    {
        for (auto* curr = head, curr_index = 0; curr != nullptr; curr = curr->next, curr_index++)
            if (curr_index == index)
            {
                if (curr_index == 0)
                    head = curr->next;
                if (curr->prev != nullptr)
                    curr->prev->next = curr->next;
                if (curr->next != nullptr)
                    curr->next->prev = curr->prev;
                delete curr;
                return;
            }
        throw std::invalid_argument("Index out of bounds.");
    }

    friend std::ostream& operator<<(std::ostream& stream, const my_list& list)
    {
        for (auto* node = list.head; node != nullptr; node = node->next)
            stream << node->data << ' ';
        return stream;
    }
private:
    struct node* head = nullptr;
};
