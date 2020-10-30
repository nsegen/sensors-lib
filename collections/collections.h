#ifndef collections_h
#define collections_h

template <class T>
struct Node
{
    public:
        T* value;
        Node* next;
        Node* previous;
        Node();
        Node(T*);
        Node(T*, Node<T>*);
        Node(T*, Node<T>*, Node<T>*);
        ~Node();    
};

template <class T>
class Iterator
{
    private:
        Node<T>* current;
        Node<T>* initial;
    public:
        Iterator(Node<T>*);
        ~Iterator();
        bool hasNext();
        bool hasPrevious();
        T* next();
        T* previous();
        T* getCurrent();
};

template <class T>
class Collection
{
    protected:
        Node<T>* head;
        int count;
    public:
        Collection();
        ~Collection();
        virtual void add(T*);
        virtual void remove(int);
        int getSize();
        Iterator<T> getIterator();     
};

template <class T>
class List : public Collection<T>
{
    public:
        List();
        ~List();
        void add(T*);
        void remove(int);  
};

#endif