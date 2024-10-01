#include <iostream>
#include <cstring>

#include "utils.h"

#include "Node.h"

template <typename T>
class List
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    Node<T> *get_head()
    {
        return head;
    }

    ~List()
    {
        remove_all();
    }

    size_t get_length()
    {
        size_t i = 0;
        for (Node<T> *node = head; node != nullptr; node = node->get_next(), i++)
        {
        }
        return i;
    }

    void append(T *data)
    {
        Node<T> *node = new Node<T>(data);
        if (head == nullptr)
        {
            head = node;
            tail = head;
        }
        else
        {
            tail->set_next(node);
            tail = node;
        }
    }

    void print_all()
    {
        size_t i = 1;
        for (Node<T> *node = head; node != nullptr; node = node->get_next(), i++)
        {
            T *drink = node->get_value();
            std::cout << i << ". " << *drink;
        }
    }

    void save_all(const char *filename)
    {
        std::ofstream fout(filename, std::ios::binary);
        for (Node<T> *node = head; node != nullptr; node = node->get_next())
        {
            T *drink = node->get_value();
            drink->save(fout);
        }
        fout.close();
    }

    void load_from(const char *filename)
    {
        size_t offset = 0;
        while (true)
        {
            T *drink = read_from_file_smart(filename, offset);
            if (drink == nullptr)
            {
                break;
            }
            append(drink);
        }
    }

    T *search(const char *name)
    {
        for (Node<T> *node = head; node != nullptr; node = node->get_next())
        {
            T *drink = node->get_value();
            if (std::strcmp(name, drink->get_name()) == 0)
            {
                return drink;
            }
        }
        return nullptr;
    }

    void remove(const char *name, size_t count = 0)
    {
        size_t deleted = 0;

        T empty_prehead_value;
        Node<T> prehead(&empty_prehead_value);
        prehead.set_next(head);

        for (Node<T> *node = &prehead; node != nullptr && node->get_next() != nullptr;)
        {
            Node<T> *next = node->get_next();

            T *value = next->get_value();
            if (std::strcmp(value->get_name(), name) == 0)
            {
                if (node == &prehead)
                {
                    head = head->get_next();
                    prehead.set_next(head);
                }
                else
                {
                    node->set_next(next->get_next());
                }
                delete next;
                if (count > 0)
                {
                    deleted++;
                    if (deleted == count)
                    {
                        break;
                    }
                }
            }
            else
            {
                node = node->get_next();
            }
        }
    }

    void remove_all()
    {
        while (head != nullptr)
        {
            Node<T> *current = head;
            head = head->get_next();
            delete current;
        }
    }
};
