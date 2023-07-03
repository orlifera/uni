#include <iostream>

class Vettore
{
private:
    int *a;
    unsigned int size;
    //vettore nullo IFF a == nullptr && size == 0   IFF == if and only if
    int *copia() const
    {
        if (size == 0)
        {
            return nullptr;
        }
        int *b = new int[size];
        for (unsigned int k = 0; k < size; ++k)
        {
            b[k] = a[k];
        }
        return b;
    }

public:
    //conversione da unsigned int a Vettore
    explicit Vettore(unsigned dim = 0, int v = 0) : a(dim == 0 ? nullptr : new int[dim]), size(dim)
    {
        for (unsigned int k = 0; k < size; ++k)
        {
            a[k] = v;
        }
    }
    Vettore(const Vettore &v) : a(v.copia()), size(v.size) {}
    Vettore &operator=(const Vettore &v)
    {
        if (this != &v)
        {
            delete[] a;
            size = v.size;
            a = v.copia();
        }
    }
    ~Vettore()
    {
        if (a != nullptr)
        {
            delete[] a;
        }
    }

    //Vettore &operator=;
    Vettore operator+(const Vettore &v) const
    {
        Vettore w(size + v.size);
        unsigned int k = 0;
        for (; k < size; ++k)
        {
            w.a[k] = a[k];
        }
        for (; k < size + v.size; ++k)
        {
            w.a[k] = v.a[k - size];
        }
        return w;
    }

    void append(const Vettore &v)
    {
        *this = this->operator+(v); //assegnazione profonda
    }
    bool operator==(const Vettore &v) const
    {
        if (size != v.size)
        {
            return false;
        }
        else
        {
            for (unsigned int k = 0; k < size; ++k)
            {
                if (a[k] != v.a[k])
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    int &operator[](unsigned int k) const
    {
        return a[k];
    }
    unsigned int getSize() const
    {
        return size;
    }
};

std::ostream &operator<<(std::ostream &os, const Vettore &v)
{
    for (unsigned int k = 0; k < v.getSize(); ++k)
    {
        os << v[k] << ' ';
    }
    return os;
}