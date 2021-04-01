
#ifndef Wrapper_h
#define Wrapper_h

/* Advanced */

using namespace std;

template <class Type>
class Wrapper
{

public:

Wrapper();
    
Wrapper(int key, Type data);

~Wrapper();

int getKey() const;

Type getData() const;
    
Wrapper<Type>& build (int key,Type data);

bool operator < (const Wrapper<Type> &w) const;

bool operator == (const Wrapper<Type> &w) const;
    
    
private:

int key;
    
Type data;

};

template<class Type>
Wrapper<Type>::Wrapper()
{

}

template<class Type>
Wrapper<Type>::Wrapper(int key, Type data)
{
    this-> key = key;
    this-> data = data;
}

template<class Type>
Wrapper<Type>::~Wrapper()
{

}

template<class Type>
int Wrapper<Type>::getKey() const
{
    return key;
}

template<class Type>
Type Wrapper<Type>::getData() const
{
    return data;
}

template<class Type>
Wrapper<Type>& Wrapper<Type>:: build (int key,Type data)
{
    return *(new Wrapper<Type>(key, data));
}

template<class Type>
bool Wrapper<Type>:: operator < (const Wrapper<Type> &w) const
{
        if (key<w.getKey())
                return true;
        else
                return false;
}

template<class Type>
bool Wrapper<Type>:: operator == (const Wrapper<Type> &w) const
{
        if(key==w.getKey())
                return true;
        else
                return false;
}

#endif /* Wrapper_h */
