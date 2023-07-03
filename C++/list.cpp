#include <iostream>

template <class T>
class dList
{
private:
    class nodo
    {
    public:
        T t;
        nodo *prev; //ptr al previous
        nodo *next; //ptr al next
        nodo(const T &i, nodo *p = 0, nodo *n = 0) : t(i), prev(p), next(n){};
    };
    nodo *first;
    nodo *last;
    //dList vuota iff first == last ==  nullptr

    static void destroy(nodo *f)
    {
        if (f)
        {
            destroy(f->next);
            delete f;
        }
    }
    static void copy(nodo *&fst, nodo *&f, nodo *&l)
    {
        if (fst == nullptr)
        {
            f = l = nullptr;
            return;
        }
        //list non vuota
        nodo *ptr = fisrt;

        l = f = new nodo(ptr->info, nullptr, nullptr);

        while (first->next != nullptr)
        {
            ptr = ptr->next;
            l->next = new nodo(ptr->info, l, nullptr);
            l = l->next;
        }
    }
    static bool lex_compare(nodo *f, nodo *s)
    {
        if (!f && !s)
        {
            return false;
        }
        if (!f)
        {
            return true;
        }
        if (!s)
        {
            return false;
        }
        if (f->info < s->info)
        {
            return true;
        }
        if (s->info < f->info)
        {
            return false;
        }

        return f->info == s->info && lex_compare(f->next, s->next);
    }

public:
    dList(const dList &d) : copy(d.first, first, last){};
    dList &operator=(const dList &d)
    {
        if (this != &d)
        {
            destroy(first);
            copy(d.first, first, last);
        }
        return *this;
    }
    ~dList()
    {
        if (first)
        {
            destroy(first);
        }
    }
    void insertFront(const T &t)
    {
        first = new nodo(t, nullptr, first);
        if (last == nullptr)
        {
            last = first;
        }
        if (first->next != nullptr)
        {
            (first->next)->prev = first;
        }
    }
    dList(unsigned int k, const T &t) : first(nullptr), last(nullptr)
    {
        for (unsigned int i = 0; i < k; ++i)
        {
            insertFront(t);
        }
    }

    bool operator<(const dList &d) const
    {
        return lex_compare(first, d.first);
    }

    class const_iterator
    {
        friend class dList<T>;

    private:
        const nodo *ptr;
        bool PastTheEnd;
        //iteratore indef IFF ptr == nullptr & pastTheEnd == false
        const_iterator(const nodo *p, bool pte = false) : ptr(p), PastTheEnd(pte){};

    public:
        const_iterator() : ptr(nullptr), PastTheEnd(false){};

        const_iterator &operator++()
        {
            const_iterator tmp(*this);
            //const_iterator || const_iterator pastTheEnd indef nulla da fare
            //ptr == 0 & pTE = false
            if (ptr && !PastTheEnd)
            {
                if (ptr->next == nullptr)
                {
                    ptr += 1;
                    PastTheEnd = true;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            return *this;
        }

        const_iterator &operator++(int)
        {
            const_iterator tmp(*this);
            //const_iterator || const_iterator pastTheEnd indef nulla da fare
            //ptr == 0 & pTE = false
            if (ptr && !PastTheEnd)
            {
                if (ptr->next == nullptr)
                {
                    ptr += 1;
                    PastTheEnd = true;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            return tmp;
        }

        const_iterator &operator--()
        {
            if (ptr)
            {
                if (ptr->prev == nullptr)
                {
                    ptr == nullptr;
                }
                else if (PastTheEnd == true)
                {
                    ptr -= 1;
                    PastTheEnd = false;
                }
                else
                {
                    ptr = ptr->prev;
                }
            }
            return *this;
        }

        const_iterator &operator--(int)
        {
            const_iterator tmp(*this);
            if (ptr || PastTheEnd)
            {
                if (ptr->prev == nullptr)
                {
                    ptr == nullptr;
                }
                else if (PastTheEnd == true)
                {
                    ptr -= 1;
                    PastTheEnd = false;
                }
                else
                {
                    ptr = ptr->prev;
                }
            }
            return tmp;
        }

        bool safeConstIterator() const
        {
        }

        const T &operator*() const
        {
            return ptr->info;
        }

        const T &operator->() const
        {
            return &(ptr->info);
        }
    };

    const_iterator begin() const
    {
        if (first != nullptr)
        {
            return const_iterator(first);
            return const_iterator();
        }
    }

    const_iterator end() const
    {
        if (first == nullptr)
        {
            return const_iterator();
        }
        else
        {
            return const_iterator(last + 1, true);
        }
    }
};