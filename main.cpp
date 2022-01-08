#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
    explicit List();
    ~List();

    int GetSize() const { return size; }
    void insert(T data, int index);
    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void pop_back();
    void clear();
    void removeAt(const int index);

    T &operator[](const int index);

private:
    template <typename N>
    class Node
    {
    public:
        explicit Node(N data = N(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }

        Node *pNext;
        N data;
    };

    int size = 0;
    Node<T> *pHead;
};

template <typename T>
List<T>::List()
{
    this->size = 0;
    this->pHead = nullptr;
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
T &List<T>::operator[](const int index)
{
    int count = 0;
    Node<T> *pCur = pHead;
    while (pCur != nullptr)
    {
        if (count == index)
        {
            return pCur->data;
        }
        pCur = pCur->pNext;
        count++;
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    if (pHead == nullptr)
    {
        pHead = new Node<T>(data);
    }
    else
    {
        Node<T> *pCur = pHead;
        while (pCur->pNext != nullptr)
        {
            pCur = pCur->pNext;
        }
        pCur->pNext = new Node<T>(data);
    }
    size++;
}

template <typename T>
void List<T>::push_front(T data)
{
    pHead = new Node<T>(data, pHead);
    size++;
}

template <typename T>
void List<T>::pop_front()
{
    Node<T> *pCur = pHead;
    pHead = pHead->pNext;
    delete pCur;
    size--;
}

template <typename T>
void List<T>::pop_back()
{
    removeAt(size - 1);
}

template <typename T>
void List<T>::clear()
{
    if (size == 0)
    {
        cout << "Sorry, you can't clear the list, because it's already clear!" << endl;
    }
    else
    {
        while (size)
        {
            pop_front();
        }
    }
}

template <typename T>
void List<T>::removeAt(const int index)
{
    Node<T> *prev = pHead;
    for (int i = 0; i < index - 1; ++i)
    {
        prev = prev->pNext;
    }
    Node<T> *toDel = prev->pNext;
    prev->pNext = toDel->pNext;
    delete toDel;
    size--;
}

template <typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T> *prev = pHead;
        for (int i = 0; i < index - 1; ++i)
        {
            prev = prev->pNext;
        }
        prev->pNext = new Node<T>(data, prev->pNext);
        size++;
    }
}

int main()
{
    List<int> l;
    l.push_back(5);
    l.push_back(10);
    l.push_front(0);
    l.push_back(15);
    l.push_back(20);
    l.push_back(25);

    cout << "Values: ";
    for (int i = 0; i < l.GetSize(); i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "Size: " << l.GetSize() << endl;

    l.pop_front();
    cout << endl
         << "[POP_FRONT]" << endl
         << endl;
    cout << "Values: ";
    for (int i = 0; i < l.GetSize(); i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "Size: " << l.GetSize() << endl;

    l.insert(0, 0);
    cout << endl
         << "[INSERT]" << endl
         << endl;
    cout << "Values: ";
    for (int i = 0; i < l.GetSize(); i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "Size: " << l.GetSize() << endl;

    l.pop_back();
    cout << endl
         << "[POP_BACK]" << endl
         << endl;
    cout << "Values: ";
    for (int i = 0; i < l.GetSize(); i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "Size: " << l.GetSize() << endl;

    l.removeAt(1);
    cout << endl
         << "[REMOVE_AT]" << endl
         << endl;
    cout << "Values: ";
    for (int i = 0; i < l.GetSize(); i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "Size: " << l.GetSize() << endl;

    l.clear();
    cout << endl
         << "[CLEAR]" << endl
         << endl;
    cout << "Values: ";
    for (int i = 0; i < l.GetSize(); i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "Size: " << l.GetSize() << endl;

    system("pause");
    return 0;
}