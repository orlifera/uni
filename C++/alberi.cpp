#include <iostream>
#include <string>

template <class T>
class albero;

template <class T>
std::ostream &operator<<(std::ostream &, const albero<T> &);

template <class T>
class albero
{
    friend std::ostream &operator<<(std::ostream &, const albero<T> &);

private:
    class nodo
    { //template di classe annidato associato
    public:
        T info;
        nodo *sx, *cx, *dx;
        nodo(const T &t, nodo *s = 0, nodo *c = 0, nodo *d = 0) : info(t), sx(s), cx(c), dx(d) {}
    };
    static nodo *copy(nodo *p)
    {
        if (p == nullptr)
        {
            return nullptr;
        }
        else
        {
            return new nodo(p->info, copy(p->sx), copy(p->cx), copy(p->dx));
        }
    }

    static void destroy(nodo *p)
    {
        if (p != nullptr)
        {
            destroy(p->sx);
            destroy(p->cx);
            destroy(p->dx);
            delete p;
        }
    }
    static bool search_rec(const T &t, nodo *p) //ha messo static così la può chiamare fuori
    {
        if (p == nullptr)
        {
            return false;
        }
        else
        {
            return (t == p->info) || (search_rec(t, p->sx) || search_rec(t, p->cx) ||
                                      search_rec(t, p->dx));
        }
    }
    static bool rec_eq(const nodo *p1, const nodo *p2)
    {
        if (!p1 && !p2)
        {
            return true;
        }
        else if (!p1 || !p2)
        {
            return false;
        }

        else if (p1 && p2)
        {
            return p1->info == p2->info && rec_eq(p1->sx, p2->sx) && rec_eq(p1->cx, p2->cx) && rec_eq(p1->dx, p2->dx);
        }
    }
    static void rec_print(std::ostream &os, nodo *p)
    {
        if (p != nullptr)
        {
            rec_print(os, p->sx);
            rec_print(os, p->cx);
            rec_print(os, p->dx);
            os << p->info << ' ';
        }
    }
    nodo *root;

public:
    albero() : root(nullptr) {}
    albero(const albero &a) : root(copy(a.root)){};
    albero &operator=(const albero &a)
    {
        if (this != &a)
        {
            destroy(root);
            root = copy(a.root);
        }
        return *this;
    }

    ~albero()
    {
        if (root != nullptr)
        {
            destroy(root);
        }
    }

    void insert(const T &t)
    {
        root = new nodo(t, copy(root), copy(root), root);
    }

    bool search(const T &t) const
    {
        return search_rec(t, root);
    }

    bool operator==(const albero &a) const
    {
        return rec_eq(root, a.root);
    }
};

template <class T>
std::ostream &operator<<(std::ostream &os, const albero<T> &a)
{
    albero<T>::rec_print(os, a.root);
    return os;
}
int main()
{
}
