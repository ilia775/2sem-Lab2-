#pragma once
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <cmath>
using namespace std;



double doublerand(double min, double max)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

float floatrand(float min, float max)
{
    float f = (float)rand() / RAND_MAX;
    return min + f * (max - min);
}

class complex
{
public:

    complex()
    {
        this->Re = 0;
        this->Im = 0;
    }

    complex(double Re, double Im)
    {
        this->Re = Re;
        this->Im = Im;
    }

    bool operator>(complex other)
    {
        if (sqrt(this->GetRe() * this->GetRe() + this->GetIm() * this->GetIm()) > sqrt(other.GetRe() * other.GetRe() + other.GetIm() * other.GetIm())) return 1;
        return 0;
    }

    bool operator<(complex other)
    {
        if (sqrt(this->GetRe() * this->GetRe() + this->GetIm() * this->GetIm()) < sqrt(other.GetRe() * other.GetRe() + other.GetIm() * other.GetIm())) return 1;
        return 0;
    }

    friend ostream& operator<<(ostream& out, const complex c);

    friend istream& operator>>(istream& in, complex& c);

    complex operator=(const complex c1)
    {
        this->Im = c1.Im;
        this->Re = c1.Re;
        return complex(c1.Re, c1.Im);
    }

    double& GetRe()
    {
        return Re;
    }

    double& GetIm()
    {
        return Im;
    }

    bool operator==(const complex other)
    {
        if (this->Re == other.Re && this->Im == other.Im) return true;
        else return false;
    }

    void operator+=(const complex* other)
    {
        this->Re += other->Re;
        this->Im += other->Im;
    }

    void operator+=(const double other)
    {
        this->Re += other;
        this->Im += other;
    }

    void operator+=(const complex other)
    {
        this->Re += other.Re;
        this->Im += other.Im;
    }

    void operator*=(const complex other)
    {
        double ReStart = this->Re, ImStart = this->Im;
        this->Re = ReStart * other.Re - ImStart * other.Im;
        this->Im = ReStart * other.Im + ImStart * other.Re;
    }

    complex& operator=(const int i)
    {
        this->Im = this->Re = i;
        return *this;
    }

    complex& operator*(const complex other)
    {
        complex* temp = new complex();
        temp->Re = Re * other.Re - Im * other.Im;
        temp->Im = Re * other.Im + Im * other.Re;
        return *temp;
    }

    void rand(double min = 0, double max = 1000)
    {
        Re = doublerand(min, max);
        Im = doublerand(min, max);
        //complex(doublerand(min, max), doublerand(min, max));
    }

    void Print()
    {
        cout << this->to_string() << endl;
    }

    string to_string()
    {
        return "Re: " + std::to_string(Re) + "     Im: " + std::to_string(Im);
    }
private:
    double Re;
    double Im;
};

istream& operator>>(istream& in, complex& c)
{
    cout << "Re:";
    in >> c.GetRe();
    cout << "Im:";
    in >> c.GetIm();
    return in;
}

ostream& operator<<(ostream& out, const complex c)
{
    out << to_string(c.Re) + "+" + to_string(c.Im) + "i";
    return out;
}

void swap(complex* c1, complex* c2)
{
    complex* temp = new complex();
    temp = c1;
    c1 = c2;
    c2 = temp;
}

//string sqrt(complex c)
//{
//    double phi = pow(tan(c.GetIm() / c.GetRe()), -1);
//    double z = sqrt(pow(c.GetIm(), 2) + pow(c.GetRe(), 2));
//    double Re0 = sqrt(z) * cos(phi/2);
//    double Im0 = sqrt(z) * sin(phi / 2);
//    double Re1 = sqrt(z) * cos((phi + 2 * _Pi) / 2);
//    double Im1 = sqrt(z) * sin((phi + 2 * _Pi) / 2);
//    return to_string(Re0) + "+" + to_string(Im0) + "i" + " | " + to_string(Re1) + "+" + to_string(Im1) + "i";
//}

//template <typename T> class Myclass
//{
//public:
//    T data;
//    Myclass()
//    {
//        data = 0;
//    }
//    void Print()
//    {
//        cout << data << endl;
//    }
//};

//complex sqrt(complex num)
//{
//    const double  PI = 3.14159265358979323846;
//    double x, y, phi, z;
//    x = num.GetRe();
//    y = num.GetIm();
//    phi = atan2(y, x);
//    z = sqrt(x * x + y * y);
//    return complex(sqrt(z) * cos((phi + 2 * PI) / 2), sqrt(z) * sin((phi + 2 * PI) / 2));
//}

//complex sqrt2(complex num)
//{
//    const double  PI = 3.14159265358979323846;
//    double x, y, phi, z;
//    x = num.GetRe();
//    y = num.GetIm();
//    phi = atan2(y, x);
//    z = sqrt(x * x + y * y);
//    return complex(sqrt(z) * cos(phi / 2), sqrt(z) * sin(phi / 2));
//}
string sqrt(complex num)
{
    const double  PI = 3.14159265358979323846;
    double x, y, phi, z;
    x = num.GetRe();
    y = num.GetIm();
    phi = atan2(y, x);
    z = sqrt(x * x + y * y);
    complex(sqrt(z) * cos((phi + 2 * PI) / 2), sqrt(z) * sin((phi + 2 * PI) / 2));
    cout<<"Первая: " << complex(sqrt(z) * cos((phi + 2 * PI) / 2), sqrt(z) * sin((phi + 2 * PI) / 2)) << "  Вторая: " << complex(sqrt(z) * cos(phi / 2), sqrt(z) * sin(phi / 2));
    return " ";
}
complex pow(complex num, int pow)
{
    complex temp = num;
    for (int i = 1; i < pow; i++)
    {
        num *= temp;
    }
    return num;
}

template <typename T> class DynamicArray
{
public:
    DynamicArray(int size)
    {
        this->arr = new T[size]{ T() };
        this->len = size;
    }
    DynamicArray()
    {
        len = 0;
        arr = new T[len];
    }
    DynamicArray(T* items, int count)
    {
        /*if (arr != nullptr)
        {
            delete[] arr;
            len = count;
        }*/
        arr = new T[count];
        len = count;
        for (int i = 0; i < len; i++)
        {
            arr[i] = items[i];
        }
    }

    DynamicArray(const DynamicArray<T>& other)
    {
        this->len = other.len;
        this->arr = new T[this->len];
        for (int i = 0; i < this->len; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    T* GetArr()
    {
        return arr;
    }

    T& Get(int index)
    {
        if (index < len) return arr[index];
        else throw "IndexOutOfRange_DA_Get";
        //else cout << "IndexOutOfRange_DA_Get\n";
        return arr[0];
    }
    T GetLast()
    {
        try {
            return this->Get(len - 1);
        }
        catch (string ex)
        {
            throw ex;
        }
    }
    T GetFirst()
    {
        try {
            return this->Get(0);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetSize()
    {
        return len;
    }

    void set(int index, T item)
    {
        if (index < len) arr[index] = item;
        else throw "IndexOutOfRange";
    }

    void Resize(int NewSize)
    {
        T* arrnew = new T[NewSize]();
        if (NewSize >= len)
        {
            for (int i = 0; i < len; i++)
            {
                arrnew[i] = arr[i];
            }

        }
        else
        {
            for (int i = 0; i < NewSize; i++)
            {
                arrnew[i] = arr[i];
            }
        }
        len = NewSize;
        delete[] arr;
        this->arr = arrnew;
    }

    DynamicArray<T> operator=(const DynamicArray<T>& other)
    {
        T* arrnew = new T[other.len];
        for (int i = 0; i < other.len; i++)
        {
            arrnew[i] = other.arr[i];
        }
        delete[] arr;
        len = other.len;
        this->arr = arrnew;
        return DynamicArray<T>(*this);
    }



    ~DynamicArray()
    {
        delete[] this->arr;
    }

    void Print(int index)
    {
        cout << arr[index] << endl;
    }

    T& operator[](int index)
    {
        if (index < len) return arr[index];
        else throw "IndexOutOfRange_DA_[]";
        return arr[0];
    }

private:
    T* arr;
    int len;
};

template <typename T> class LinkedList
{
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    ~LinkedList()
    {
        while (size)
        {
            this->Pop_Front();
        }
    }

    LinkedList(T* items, int count)
    {
        size = 0;
        //head = new Node<T>();
        for (int i = 0; i < count; i++)
        {
            this->Push_Back(items[i]);
        }
    }

    LinkedList(int count)
    {
        size = 0;
        head = nullptr;
        for (int i = 0; i < count; i++)
        {
            this->Push_Back(T());
        }
    }

    LinkedList(const LinkedList<T>& other)
    {
        Node<T>* temp = other.head;
        for (int i = 0; i < other.size; i++)
        {
            this->Push_Back(temp->data);
            temp = temp->ptrNext;
        }
    }

    T GetFirst()
    {
        if (size >= 1)
        {
            try {
                return this->Get(0);
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        else
        {
            throw "IndexOutOfRange_LL_GetFirst";
            //return T();
        }
    }

    void Resize(int NewSize)
    {
        if (NewSize == size) {}
        else if (NewSize > size) for (int i = 0; i < NewSize - size;) this->Append(T());
        else if (NewSize < size) for (int i = 0; i < size - NewSize;) this->Pop_Back();
    }

    T GetLast()
    {
        if (size == 0)
        {
            throw "IndexOutOfRange_LL_GetLast";
            return T();
        }
        else
        {
            try
            {
                return this->Get(size - 1);
            }
            catch (string ex)
            {
                throw ex;
            }
            /*Node<T>* temp = head;
            while (temp->ptrNext != nullptr)
            {
                temp = temp->ptrNext;
            }
            return temp->data;*/
        }
    }

    T Get(int index)
    {
        if (index < size)
        {
            return this->operator[](index);
        }
        else
        {
            throw "IndexOutOfRange_LL_Get";
            return T();
        }

    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < size && endIndex < size && startIndex>=0 && endIndex >= 0)
        {
            if (endIndex < startIndex)
            {
                LinkedList<T>* res = new LinkedList<T>();
                return res;
            }
            Node<T>* temp = head;
            T* arrnew = new T[endIndex - startIndex + 1];
            for (int i = 0; i < startIndex; i++)
            {
                temp = temp->ptrNext;
            }
            for (int i = startIndex; i <= endIndex; i++)
            {
                arrnew[i - startIndex] = temp->data;
                temp = temp->ptrNext;
            }
            LinkedList<T>* res = new LinkedList<T>(arrnew, endIndex - startIndex + 1);
            delete[] arrnew;
            return res;
        }
        else
        {
            throw "IndexOutOfRange_LL_GetSubList";
            LinkedList<T>* res = new LinkedList<T>();
            return res;
        }
    }

    void Clear()
    {
        while (size)
        {
            this->Pop_Front();
        }
    }

    void printall()
    {
        cout << "printall  this=" << this << endl;
        for (int i = 0; i < size; i++)
        {
            cout << this->operator[](i) << endl;
        }
    }

    void Pop_Front()
    {
        //cout << this << "   " << size << this->head->data << endl;
        Node<T>* temp = head->ptrNext;
        delete[] head;
        head = temp;
        size -= 1;
    }

    void Push_Back(T data)
    {
        size += 1;
        if (head == nullptr)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T>* current = this->head;
            while (current->ptrNext != nullptr)
            {
                current = current->ptrNext;
            }
            current->ptrNext = new Node<T>(data);
        }
    }

    int GetSize()
    {
        return size;
    }

    T& operator[](int index)
    {
        Node<T>* current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->ptrNext;
        }
        return current->data;
    }

    LinkedList<T>& operator=(const LinkedList<T>& other)
    {
        Clear();
        Node<T>* temp = other.head;
        for (int i = 0; i < other.size; i++)
        {
            Push_Back(temp->data);
            temp = temp->ptrNext;
        }
        return *this;
    }

    void Push_Front(T data)
    {
        head = new Node<T>(data, head);
        size += 1;
    }

    T* GetArr()
    {
        T* Arr = new T[size]();
        for (int i = 0; i < size; i++)
        {
            Arr[i] = this->operator[](i);
        }
        return Arr;
    }

    void Pop_Back()
    {
        Node<T>* current = this->head;
        for (int i = 0; i < size - 1; i++)
        {
            current = current->ptrNext;
        }
        delete[] current->ptrNext;
        current->ptrNext = nullptr;
        size -= 1;
    }

    void Append(T item)
    {
        Push_Back(item);
    }

    void Prepend(T item)
    {
        Push_Front(item);
    }


    void InsertAt(T item, int index)
    {
        if (index > size) throw "IndexOutOfRange_LL_InsertAt";
        else
        {

            if (index == 0)
            {
                Push_Front(item);
            }
            else {
                index -= 1;
                size += 1;
                Node<T>* temp = this->head;
                for (int i = 0; i < index; i++)
                {
                    temp = temp->ptrNext;
                }
                Node<T>* ins = new Node<T>(item, temp->ptrNext);
                temp->ptrNext = ins;
            }
        }
    }
    LinkedList<T>* Concat(LinkedList<T>* other)
    {
        size += other->size;
        Node<T>* temp = head;
        while (temp->ptrNext != nullptr)
        {
            temp = temp->ptrNext;
        }
        temp->ptrNext = other->head;
        LinkedList<T>* res = new LinkedList<T>(*this);
        return res;
    }



private:
    template <typename T1> class Node
    {
    public:
        Node<T1>* ptrNext;
        T1 data;

        Node(T1 data = T1(), Node<T1>* ptrNext = nullptr)
        {
            this->data = data;
            this->ptrNext = ptrNext;
        }
        Node<T1>& operator=(const Node<T1> other)
        {
            this->data = other.data;
        }
        /*Node<T1>& operator[](const int index)
        {
            Node<T1>* temp = this;
            for (int i = 0; i < index; i++)
            {
                temp = temp->ptrNext;
            }
            return &temp->data;
        }*/
    };
    int size;
    Node<T>* head;
};

template <typename T> class Sequence
{
public:

    virtual ~Sequence() {};
    virtual T GetFirst() = 0;
    virtual void Resize(int len) = 0;
    virtual T GetLast() = 0;
    virtual T* GetArr() = 0;

    virtual T Get(int index) = 0;

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;

    virtual int GetLenght() = 0;


    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;

    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
    virtual T& operator[](int index) = 0;
private:
};

template <typename T> class ArraySequence : public Sequence<T>
{
public:
    ~ArraySequence() override
    {
        delete items;
    }

    ArraySequence(T* items, int count)
    {
        this->items = new DynamicArray<T>(items, count);
    }

    ArraySequence()
    {
        this->items = new DynamicArray<T>();
    }

    ArraySequence(int count)
    {
        this->items = new DynamicArray<T>(count);
    }

    T& operator[](int index) override
    {
        return items->operator[](index);
    }

    int GetSize()
    {
        return this->GetLenght();
    }

    T* GetArr() override
    {
        return items->GetArr();
    }

    Sequence <T>* Concat(Sequence <T>* other) override
    {
        for (int i = 0; i < other->GetLenght(); i++)
        {
            try{
                this->Append(other->Get(i));
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        ArraySequence<T>* res = new ArraySequence<T>(*this);
        return res;
    }

    ArraySequence(const ArraySequence<T>& other)
    {
        this->items = new DynamicArray<T>(other.items->GetArr(), other.items->GetSize());
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        DynamicArray<T>* temp = new DynamicArray<T>(abs(endIndex - startIndex) + 1);
        for (int i = startIndex; i <= endIndex; i++)
        {
            temp->operator[](i - startIndex) = items->operator[](i);
        }
        int len = temp->GetSize();
        T* arr = new T[len];
        for (int i = 0; i < len; i++)
        {
            try {
                arr[i] = temp->Get(i);
            }
            catch (string ex)
            {
                throw ex;
            }
        }
        delete temp;
        ArraySequence<T>* res = new ArraySequence<T>(arr, len);
        return res;
    }

    T GetFirst() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetFirst();
        }

        else throw "IndexOutOfRange_DS_GETFIRST";
        return items->GetFirst();
    }

    T GetLast() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetLast();
        }

        else throw "IndexOutOfRange_DS_GetLast";
        return items->GetLast();
    }

    T Get(int index) override
    {
        try
        {
            return items->Get(index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetLenght() override
    {
        return items->GetSize();
    }

    void Append(T item) override
    {
        if (items->GetSize() != 0) {
            int len = items->GetSize() + 1;
            DynamicArray<T>* items_new = new DynamicArray<T>(len);
            for (int i = 0; i < len - 1; i++)
            {
                items_new->operator[](i) = items->operator[](i);
            }
            items_new->operator[](len - 1) = item;
            delete items;
            items = items_new;
        }
        else throw "IndexOutOfRange_DS_APPEND";
    }

    void InsertAt(T item, int index) override
    {
        if (this->GetSize() < index) throw"IndexOutOfRange_AS_InsertAt";
        if (index == 0) this->Prepend(item);
        else if (index == items->GetSize()) this->Append(item);
        else
        {
            int len = items->GetSize() + 1;
            DynamicArray<T>* items_new = new DynamicArray<T>(len);
            int i1 = 0;
            for (int i = 0; i < len; i++)
            {
                if (i != index) {
                    items_new->operator[](i) = items->operator[](i1);
                    i1++;
                }
                else
                {
                    items_new->operator[](i) = item;
                }
            }
            delete items;
            items = items_new;
        }
    }

    void Prepend(T item) override
    {
        int len = items->GetSize() + 1;
        DynamicArray<T>* items_new = new DynamicArray<T>(len);
        items_new->operator[](0) = item;
        for (int i = 1; i < len; i++)
        {
            items_new->operator[](i) = items->operator[](i - 1);
        }
        delete items;
        this->items = items_new;
    }

    void Resize(int len) override
    {
        items->Resize(len);
    }

private:
    DynamicArray<T>* items;
};

template <typename T> class ListSequence : public Sequence<T>
{
public:

    ~ListSequence() override
    {
        if (items->GetSize() != 0) delete[] items;
    }

    ListSequence(T* items, int count)
    {
        this->items = new LinkedList<T>(items, count);
    }

    ListSequence(int count)
    {
        this->items = new LinkedList<T>(count);
    }

    ListSequence()
    {
        this->items = new LinkedList<T>();
    }

    T* GetArr()
    {
        return items->GetArr();
    }

    ListSequence(const ListSequence<T>& other)
    {
        this->items = new LinkedList<T>(other.items->GetArr(), other.items->GetSize());
    }

    int GetSize()
    {
        return this->GetLenght();
    }

    T& operator[](int index) override
    {
        return items->operator[](index);
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        ListSequence<T>* res = new ListSequence<T>();
        try
        {
            res->items = this->items->GetSubList(startIndex, endIndex);
        }
        catch (string ex)
        {
            throw ex;
        }
        return res;
    }

    Sequence <T>* Concat(Sequence <T>* other) override
    {
        ListSequence<T>* temp = new ListSequence<T>(this->GetArr(), this->GetLenght());
        temp->items->Concat(new LinkedList<T>(other->GetArr(), other->GetLenght()));
        return temp;
    }

    T GetFirst() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetFirst();
        }
        else
        {
            throw "IndexOutOfRange_LS_GetFirst";
            return T();
        }
    }

    T GetLast() override
    {
        if (items->GetSize() > 0)
        {
            return items->GetLast();
        }
        else
        {
            throw "IndexOutOfRange_DS_GetLast";
            return T();
        }
    }

    T Get(int index) override
    {
        try
        {
            return items->Get(index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    int GetLenght() override
    {
        return items->GetSize();
    }

    void Append(T item) override
    {
        if (items->GetSize() != 0) {
            items->Append(item);
        }
        else throw "IndexOutOfRange_DS_APPEND";
    }

    void InsertAt(T item, int index) override
    {
        try
        {
            items->InsertAt(item, index);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void Prepend(T item) override
    {
        items->Prepend(item);
    }

    void Resize(int len) override
    {
        items->Resize(len);
    }

private:
    LinkedList<T>* items;
};

template <typename T, typename T1> class Matrix
{
public:

    Matrix()
    {
        this->NumOfRows = 0;
        this->NumOfColumns = 0;

        this->typeofarray = typeid(T).name();
        if (typeofarray[0] == 'L')
        {
            typeofarray == "LinkedArr";
            items = new ListSequence<T>();
        }
        else
        {
            typeofarray == "DynamicArr";
            items = new ArraySequence<T>();
        }
        this->typeofdata = typeid(T1).name();
    }

    Matrix(string typeofarray, string typeofdata, int Columns, int Rows)
    {
        if (typeofarray[0] == 'L') typeofarray = "LinkedArr";
        else typeofarray = "DynamicArr";
        this->NumOfRows = Rows;
        this->NumOfColumns = Columns;
        this->typeofarray = typeofarray;
        this->typeofdata = typeofdata;
        if (typeofarray == "LinkedArr")
        {
            items = new ListSequence<T>(Rows);

            for (int i = 0; i < Rows; i++)
            {
                T* temp = &items->operator[](i);
                temp->Resize(Columns);
                //cout<< "Len of "<< i << " element " << items->operator[](i).GetLenght() <<endl;
            }
        }

        if (typeofarray == "DynamicArr")
        {
            items = new ArraySequence<T>(Rows);
            for (int i = Rows - 1; i > -1; i--)
            {

                items->operator[](i).Resize(Columns);
                //cout << "Len of " << i << " element " << items->operator[](i).GetLenght() << endl;
            }
        }

    }

    ~Matrix()
    {
        delete[] items;
    }

    T1& Get(int Row, int Column)
    {
        return (items->operator[](Row)).operator[](Column);
    }

    string GetTypeOfArray() { return typeofarray; }

    string GetTypeOfData() { return typeofdata; }

    void MatrixSum(Matrix<T, T1>* other)
    {
        try
        {
            for (int i = 0; i < NumOfRows; i++) for (int j = 0; j < NumOfColumns; j++) this->Get(i, j) += other->Get(i, j);
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void MatrixMult(T1 num)
    {
        try
        {
            for (int i = 0; i < NumOfRows; i++) for (int j = 0; j < NumOfColumns; j++) this->Get(i, j) *= num;
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void operator*=(T1 num)
    {
        this->MatrixMult(num);
    }

    void operator*=(Matrix<T, T1> other)
    {
        Matrix<T, T1>* mat = new Matrix<T, T1>(this->GetTypeOfArray(), this->GetTypeOfData(), other.GetNumOfColumns(), this->GetNumOfRows());
        for (int i = 0; i < this->GetNumOfColumns(); i++) {
            for (int j = 0; j < other.GetNumOfRows(); j++) {

                try
                {
                    mat->Get(i, j) = 0;
                    for (int k = 0; k < other.GetNumOfColumns(); k++) {
                        mat->Get(i, j) += this->Get(i, k) * other.Get(k, j);
                    }
                }
                catch (string ex)
                {
                    throw ex;
                }
            }
        }
    }

    int GetNumOfRows() { return NumOfRows; }

    int GetNumOfColumns() { return NumOfColumns; }

    void PrintParams()
    {
        cout << "Количество столбцов: " << this->GetNumOfColumns() << endl;
        cout << "Количество строк: " << this->GetNumOfRows() << endl;
        cout << "Тип последовательности: " << this->GetTypeOfArray() << endl;
        cout << "Тип данных: " << this->GetTypeOfData() << endl;
    }

    void FindNorm1(int width)
    {
        try
        {
            T1 norm = T1();
            for (int i = 0; i < this->GetNumOfRows(); i++) for (int j = 0; j < this->GetNumOfColumns(); j++) norm += (T1)pow(this->Get(i, j), 2);
            cout << " Норма " << setw(width) << sqrt(norm) << endl;
            
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void FindNorm3(int width)
    {
        try
        {
            //for (int i = 0; i < ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfRows(); i++)
                //                        {
                //                            norm = 0;
                //                            for (int j = 0; j < ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfColumns(); j++) norm += abs((int)((Matrix<ListSequence<int>, int>*)mat1)->Get(i, j));
                //                            if (norm1 < norm) norm1 = norm;
                //                        }
            if (typeid(T1).name() != typeid(complex).name())
            {
                T1 norm = T1();
                T1 norm1 = T1();
                for (int i = 0; i < this->GetNumOfColumns(); i++)
                {
                    norm = T1();
                    for (int j = 0; j < this->GetNumOfRows(); j++) norm += abs(this->Get(j, i));
                    if (norm1 < norm) norm1 = norm;
                }
                cout << "Норма: " << setw(width) << norm1 << endl;
            }
            else
            {
                double norm = 0;
                double norm1 = 0;
                for (int i = 0; i < this->GetNumOfColumns(); i++)
                {
                    norm = 0;
                    for (int j = 0; j < this->GetNumOfRows(); j++) norm += abs(this->Get(j, i));
                    if (norm1 < norm) norm1 = norm;
                }
                cout << "Норма: " << setw(width) << norm1 << endl;
            }
        }
        catch (string ex)
        {
            throw ex;
        }
    }

    void FindNorm2(int width)
    {
        try
        {
            if (typeid(T1).name() != typeid(complex).name())
            {
                T1 norm = T1();
                T1 norm1 = T1();
                for (int i = 0; i < this->GetNumOfRows(); i++)
                {
                    norm = T1();
                    for (int j = 0; j < this->GetNumOfColumns(); j++) norm += abs(this->Get(i, j));
                    if (norm1 < norm) norm1 = norm;
                }
                cout << "Норма: " << setw(width) << norm1 << endl;
            }
            else
            {
                double norm = 0;
                double norm1 = 0;
                for (int i = 0; i < this->GetNumOfRows(); i++)
                {
                    norm = 0;
                    for (int j = 0; j < this->GetNumOfColumns(); j++) norm += abs(this->Get(i, j));
                    if (norm1 < norm) norm1 = norm;
                }
                cout << "Норма: " << setw(width) << norm1 << endl;
            }
        }
        catch (string ex)
        {
            throw ex;
        }
    }
    
    void ChangeRows(int row1, int row2)
    {
        for (int i = 0; i < NumOfColumns; i++)
        {
            try
            {
                swap(this->Get(row1, i), this->Get(row2, i));
            }
            catch (string ex)
            {
                throw ex;
            }
        }
    }

    void MultRow(int row, T1 num)
    {
        for (int i = 0; i < NumOfColumns; i++)
        {
            try
            {
                this->Get(row, i) *= num;
            }
            catch (string ex) {
                throw ex;
            }
        }
    }

    void RowCombination(T1 num, int row1, int row2)
    {
        
        try
        {
            for (int i = 0; i < NumOfColumns; i++) this->Get(row2, i) += this->Get(row1, i) * num;
        }
        catch (string ex) {
            throw ex;
        }
    }

    void ChangeColumns(int column1, int column2)
    {
        
        try
        {
            for (int i = 0; i < NumOfRows; i++) swap(this->Get(i, column1), this->Get(i, column2));
        }
        catch (string ex) {
            throw ex;
        }
    }

    void MultColumn(int column, T1 num)
    {
        
        try
        {
            for (int i = 0; i < NumOfRows; i++) this->Get(i, column) *= num;
        }
        catch (string ex) {
            throw ex;
        }
    }

    void ColumnCombination(T1 num, int column1, int column2)
    {
        
        try
        {
            for (int i = 0; i < NumOfRows; i++) this->Get(i, column2) += this->Get(i, column1) * num;
        }
        catch (string ex) {
            throw ex;
        }
    }


private:
    string typeofdata;
    string typeofarray;
    int NumOfRows;
    int NumOfColumns;
    Sequence<T>* items;
};

double abs(complex num)
{
    return sqrt(num.GetRe() * num.GetRe() + num.GetIm() * num.GetIm());
}

string gettypeofdata()
{
    string typeofdata = "";
    while (typeofdata == "")
    {
        cout << "Выберите тип данных:\n1 - int\n2 - long int\n3 - float\n4 - double\n5 - complex\n";
        int a = 0;
        cin >> a;
        switch (a)
        {
        case(1):
            typeofdata = "int";
            break;
        case(2):
            typeofdata = "long int";
            break;
        case(3):
            typeofdata = "float";
            break;
        case(4):
            typeofdata = "double";
            break;
        case(5):
            typeofdata = "complex";
            break;
        default:
            cout << " Неверный ввод\n";
            typeofdata = "";
            break;
        }

    }
    return typeofdata;
}

string gettypeofarray()
{
    string typeofarray = "";
    while (typeofarray == "")
    {
        cout << "Выберите тип данных:\n1 - LinkedArr\n2 - DynamicArr\n";
        int a = 0;
        cin >> a;
        switch (a)
        {
        case(1):
            typeofarray = "LinkedArr";
            break;
        case(2):
            typeofarray = "DynamicArr";
            break;

        default:
            cout << "Неверный ввод\n";
            typeofarray = "";
            break;
        }

    }
    return typeofarray;
}

int getnumofcollumns()
{
    int Columns = -1;
    while (Columns < 1) {
        cout << "Введите количество столбцов для матрицы: ";
        cin >> Columns;
        if (Columns < 1) cout << "\nНеверный ввод\n";

    }
    return Columns;
}

int getnumofrows()
{
    int Rows = -1;
    while (Rows < 1) {
        cout << "Введите количество строк для матрицы: ";
        cin >> Rows;
        if (Rows < 1) cout << "\nНеверный ввод\n";

    }
    return Rows;
}

void* GetMatrix()
{
    void* mat1 = nullptr;
    string typeofarray = gettypeofarray();
    string typeofdata = gettypeofdata();
    if (typeofarray == "LinkedArr") {
        if (typeofdata == "int") {
            mat1 = new Matrix<ListSequence<int>, int>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ListSequence<int>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "long int") {
            mat1 = new Matrix<ListSequence<long>, long>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ListSequence<long>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "float") {
            mat1 = new Matrix<ListSequence<float>, float>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ListSequence<float>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "double") {
            mat1 = new Matrix<ListSequence<double>, double>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ListSequence<double>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "complex") {
            mat1 = new Matrix<ListSequence<complex>, complex>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ListSequence<complex>>*)mat1)->PrintParams();
        }
    }
    else if (typeofarray == "DynamicArr")
    {
        if (typeofdata == "int") {
            mat1 = new Matrix<ArraySequence<int>, int>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ArraySequence<int>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "long int") {
            mat1 = new Matrix<ArraySequence<long>, long>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ArraySequence<long>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "float") {
            mat1 = new Matrix<ArraySequence<float>, float>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ArraySequence<float>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "double") {
            mat1 = new Matrix<ArraySequence<double>, double>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ArraySequence<double>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "complex") {
            mat1 = new Matrix<ArraySequence<complex>, complex>(typeofarray, typeofdata, getnumofcollumns(), getnumofrows());
            //((Matrix<ArraySequence<complex>>*)mat1)->PrintParams();
        }
    }
    else {
        cout << "Неверный ввод GetMatrix\n";
    }
    return mat1;
}

void* GetMatrix(string typeofdata, string typeofarray, int rows, int columns)
{
    void* mat1 = nullptr;
    if (typeofarray == "LinkedArr") {
        if (typeofdata == "int") {
            mat1 = new Matrix<ListSequence<int>, int>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ListSequence<int>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "long int") {
            mat1 = new Matrix<ListSequence<long>, long>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ListSequence<long>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "float") {
            mat1 = new Matrix<ListSequence<float>, float>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ListSequence<float>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "double") {
            mat1 = new Matrix<ListSequence<double>, double>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ListSequence<double>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "complex") {
            mat1 = new Matrix<ListSequence<complex>, complex>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ListSequence<complex>>*)mat1)->PrintParams();
        }
    }
    else if (typeofarray == "DynamicArr")
    {
        if (typeofdata == "int") {
            mat1 = new Matrix<ArraySequence<int>, int>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ArraySequence<int>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "long int") {
            mat1 = new Matrix<ArraySequence<long>, long>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ArraySequence<long>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "float") {
            mat1 = new Matrix<ArraySequence<float>, float>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ArraySequence<float>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "double") {
            mat1 = new Matrix<ArraySequence<double>, double>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ArraySequence<double>>*)mat1)->PrintParams();
        }
        else if (typeofdata == "complex") {
            mat1 = new Matrix<ArraySequence<complex>, complex>(typeofarray, typeofdata, columns, rows);
            //((Matrix<ArraySequence<complex>>*)mat1)->PrintParams();
        }
    }
    else {
        cout << "Неверный ввод GetMatrix\n";
    }
    return mat1;
}


void RandomizeMatrix(void* mat)
{
    srand((int)time(NULL));
    string typeofdata = ((Matrix<ListSequence<int>, int>*)mat)->GetTypeOfData();
    string typeofarray = ((Matrix<ListSequence<int>, int>*)mat)->GetTypeOfArray();
    int Columns = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfColumns();
    int Rows = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfRows();
    try
    {
        if (typeofarray == "LinkedArr") {
            if (typeofdata == "int") { for (int i = 0; i < Rows; i++) { for (int k = 0; k < Columns; k++) { ((Matrix<ListSequence<int>, int>*)mat)->Get(i, k) = (int)(pow(-1, rand() % 2) * (rand() % 1000)); } } }
            else if (typeofdata == "long int") { for (int i = 0; i < Rows; i++) { for (int k = 0; k < Columns; k++) { ((Matrix<ListSequence<long>, long>*)mat)->Get(i, k) = (long)(pow(-1, rand() % 2) * (rand() % 1000)); } } }
            else if (typeofdata == "float") { for (int i = 0; i < Rows; i++) { for (int k = 0; k < Columns; k++) { ((Matrix<ListSequence<float>, float>*)mat)->Get(i, k) = floatrand(-1000, 1000); } } }
            else if (typeofdata == "double") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ListSequence<double>, double>*)mat)->Get(i, k) = doublerand(-1000, 1000);
                    }
                }
            }
            else if (typeofdata == "complex") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ListSequence<complex>, complex>*)mat)->Get(i, k).GetRe() = doublerand(-1000, 1000);
                        ((Matrix<ListSequence<complex>, complex>*)mat)->Get(i, k).GetIm() = doublerand(-1000, 1000);
                    }
                }
            }
        }
        else if (typeofarray == "DynamicArr")
        {
            if (typeofdata == "int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ArraySequence<int>, int>*)mat)->Get(i, k) = (int)(pow(-1, rand() % 2) * (rand() % 1000));
                    }
                }
            }
            else if (typeofdata == "long int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ArraySequence<long>, long>*)mat)->Get(i, k) = (long)(pow(-1, rand() % 2) * (rand() % 1000));
                    }
                }
            }
            else if (typeofdata == "float") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ArraySequence<float>, float>*)mat)->Get(i, k) = floatrand(-1000, 1000);
                    }
                }
            }
            else if (typeofdata == "double") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ArraySequence<double>, double>*)mat)->Get(i, k) = doublerand(-1000, 1000);
                    }
                }
            }
            else if (typeofdata == "complex") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        ((Matrix<ArraySequence<complex>, complex>*)mat)->Get(i, k).GetRe() = doublerand(-1000, 1000);
                        ((Matrix<ArraySequence<complex>, complex>*)mat)->Get(i, k).GetIm() = doublerand(-1000, 1000);
                    }
                }
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

//template<typename T, typename T1>
//void RandomizeMatrix(Matrix<T, T1>* mat)
//{
//    srand((int)time(NULL));
//    int Columns = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfColumns();
//    int Rows = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfRows();
//    if (typeid(T1).name() != "complex" || typeid(T1).name() == "long int") for (int i = 0; i < Rows; i++) for (int k = 0; k < Columns; k++) mat->Get(i, k) = doublerand(-1000,1000);
//    else if (typeid(T1).name() == "complex") for (int i = 0; i < Rows; i++) for (int k = 0; k < Columns; k++)
//    {
//        ((Matrix<T, complex>*)mat)->Get(i, k).GetRe() = doublerand(-1000, 1000);
//        ((Matrix<T, complex>*)mat)->Get(i, k).GetIm() = doublerand(-1000, 1000);
//    }
//}

void ByHandMatrix(void* mat)
{
    string typeofdata = ((Matrix<ListSequence<int>, int>*)mat)->GetTypeOfData();
    string typeofarray = ((Matrix<ListSequence<int>, int>*)mat)->GetTypeOfArray();
    int Columns = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfColumns();
    int Rows = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfRows();
    cout << "Введите " << Rows << " строк и " << Columns << " стобцов элементов типа " + typeofdata << endl;
    try
    {
        if (typeofarray == "LinkedArr") {
            if (typeofdata == "int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        int temp = -123;
                        cin >> temp;
                        ((Matrix<ListSequence<int>, int>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "long int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        long temp = -123;
                        cin >> temp;
                        ((Matrix<ListSequence<long>, long>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "float") {
                //cout << "Columns: "<<((Matrix<ListSequence<float>, float>*)mat)->GetNumOfColumns() << endl << "Rows: "<<((Matrix<ListSequence<float>, float>*)mat)->GetNumOfRows() << endl;
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        float temp = -123;
                        cin >> temp;
                        //cout << temp<<endl<< ((Matrix<ListSequence<float>, float>*)mat)->Get(i, k)<<endl;
                        ((Matrix<ListSequence<float>, float>*)mat)->Get(i, k) = temp;
                        //cout << "Res: " << ((Matrix<ListSequence<float>, float>*)mat)->Get(i, k) << endl;
                    }
                }
            }
            else if (typeofdata == "double") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        double temp = -123;
                        cin >> temp;
                        ((Matrix<ListSequence<double>, double>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "complex") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        double tempRE = 0, tempIM = 0;
                        cout << "RE = ";
                        cin >> tempRE;
                        cout << "\nIM = ";
                        cin >> tempIM;
                        cout << "\n";
                        complex temp(tempRE, tempIM);
                        ((Matrix<ListSequence<complex>, complex>*)mat)->Get(i, k) = temp;
                    }
                }
            }
        }
        else if (typeofarray == "DynamicArr")
        {
            if (typeofdata == "int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        int temp = -123;
                        cin >> temp;
                        ((Matrix<ArraySequence<int>, int>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "long int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        long temp = -123;
                        cin >> temp;
                        ((Matrix<ArraySequence<long>, long>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "float") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        float temp = -123;
                        cin >> temp;
                        ((Matrix<ArraySequence<float>, float>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "double") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        double temp = -123;
                        cin >> temp;
                        ((Matrix<ArraySequence<double>, double>*)mat)->Get(i, k) = temp;
                    }
                }
            }
            else if (typeofdata == "complex") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        double tempRE = 0, tempIM = 0;
                        cout << "RE = ";
                        cin >> tempRE;
                        cout << "\nIM = ";
                        cin >> tempIM;
                        cout << "\n";
                        complex temp(tempRE, tempIM);
                        ((Matrix<ArraySequence<complex>, complex>*)mat)->Get(i, k) = temp;
                    }
                }
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

void MatrixToConsole(void* mat)
{
    int width = 10;
    string typeofdata = ((Matrix<ListSequence<int>, int>*)mat)->GetTypeOfData();
    string typeofarray = ((Matrix<ListSequence<int>, int>*)mat)->GetTypeOfArray();
    int Columns = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfColumns();
    int Rows = ((Matrix<ListSequence<int>, int>*)mat)->GetNumOfRows();
    try
    {


        if (typeofarray == "LinkedArr") {
            if (typeofdata == "int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ListSequence<int>, int>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "long int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ListSequence<long>, long>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "float") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ListSequence<float>, float>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "double") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ListSequence<double>, double>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "complex") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ListSequence<complex>, complex>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
        }
        else if (typeofarray == "DynamicArr")
        {
            if (typeofdata == "int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ArraySequence<int>, int>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "long int") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ArraySequence<long>, long>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "float") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ArraySequence<float>, float>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "double") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ArraySequence<double>, double>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
            else if (typeofdata == "complex") {
                for (int i = 0; i < Rows; i++) {
                    for (int k = 0; k < Columns; k++)
                    {
                        cout << setw(width) << ((Matrix<ArraySequence<complex>, complex>*)mat)->Get(i, k) << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

void MatrixSum(void* mat1)
{
    cout << "Выберите способ ввода матрицы для суммирования:\n1. Ручной.\n2. Случайный.\n";
    int choice1 = 0;
    void* mat2 = GetMatrix(((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData(), ((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray(), ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfRows(), ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfColumns());
    try
    {
        while (1)
        {
            cin >> choice1;
            if (choice1 == 1)
            {
                ByHandMatrix(mat2);
            }
            else if (choice1 == 2)
            {
                RandomizeMatrix(mat2);
            }
            else
            {
                cout << "Неврный ввод.\n";
                cin.clear();
                while (cin.get() != '\n');
            }

            if (choice1 == 1 || choice1 == 2)
            {
                cout << "Матрица для суммирования:\n";
                MatrixToConsole(mat2);
                if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
                {
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "int") ((Matrix<ListSequence<int>, int>*)mat1)->MatrixSum(((Matrix<ListSequence<int>, int>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "long int") ((Matrix<ListSequence<long>, long>*)mat1)->MatrixSum(((Matrix<ListSequence<long>, long>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "float") ((Matrix<ListSequence<float>, float>*)mat1)->MatrixSum(((Matrix<ListSequence<float>, float>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "double") ((Matrix<ListSequence<double>, double>*)mat1)->MatrixSum(((Matrix<ListSequence<double>, double>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "complex") ((Matrix<ListSequence<complex>, complex>*)mat1)->MatrixSum(((Matrix<ListSequence<complex>, complex>*)mat2));
                }
                if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
                {
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "int") ((Matrix<ArraySequence<int>, int>*)mat1)->MatrixSum(((Matrix<ArraySequence<int>, int>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "long int") ((Matrix<ArraySequence<long>, long>*)mat1)->MatrixSum(((Matrix<ArraySequence<long>, long>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "float") ((Matrix<ArraySequence<float>, float>*)mat1)->MatrixSum(((Matrix<ArraySequence<float>, float>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "double") ((Matrix<ArraySequence<double>, double>*)mat1)->MatrixSum(((Matrix<ArraySequence<double>, double>*)mat2));
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "complex") ((Matrix<ArraySequence<complex>, complex>*)mat1)->MatrixSum(((Matrix<ArraySequence<complex>, complex>*)mat2));
                }
                break;
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

void MatrixMult(void* mat1)
{
    cout << "Выберите способ ввода числа для умножения:\n1. Ручной.\n2. Случайный.\n";
    int choice1 = 0;
    void* num = nullptr;
    string typeofdata = ((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData();
    try
    {
        while (1)
        {
            cin >> choice1;
            if (choice1 == 1)
            {
                if (typeofdata == "int")
                {
                    int num1;
                    cout << "Введите число типа " << typeofdata << endl;
                    cin >> num1;
                    num = &num1;
                }
                else if (typeofdata == "long int")
                {
                    long num1;
                    cout << "Введите число типа " << typeofdata << endl;
                    cin >> num1;
                    num = &num1;
                }
                else if (typeofdata == "float")
                {
                    float num1;
                    cout << "Введите число типа " << typeofdata << endl;
                    cin >> num1;
                    num = &num1;
                }
                else if (typeofdata == "double")
                {
                    double num1;
                    cout << "Введите число типа " << typeofdata << endl;
                    cin >> num1;
                    num = &num1;
                }
                else if (typeofdata == "complex")
                {
                    double Re, Im;
                    cout << "Введите число типа " << typeofdata << endl << "Re: ";
                    cin >> Re;
                    cout << "Im: ";
                    cin >> Im;
                    num = new complex(Re, Im);
                }
            }
            else if (choice1 == 2)
            {
                if (typeofdata == "int")
                {
                    int num1 = (int)(pow(-1, rand() % 2) * (rand() % 1000));
                    cout << "Сгенерированное число: " << num1 << endl;
                    num = &num1;
                }
                else if (typeofdata == "long int")
                {
                    long num1 = (long)(pow(-1, rand() % 2) * (rand() % 1000));
                    cout << "Сгенерированное число: " << num1 << endl;
                    num = &num1;
                }
                else if (typeofdata == "float")
                {
                    float num1 = floatrand(-1000, 1000);
                    cout << "Сгенерированное число: " << num1 << endl;
                    num = &num1;
                }
                else if (typeofdata == "double")
                {
                    double num1 = doublerand(-1000, 1000);
                    cout << "Сгенерированное число: " << num1 << endl;
                    num = &num1;
                }
                else if (typeofdata == "complex")
                {
                    double Re = doublerand(-1000, 1000), Im = doublerand(-1000, 1000);
                    complex num1(Re, Im);
                    cout << "Сгенерированное число: " << num1 << endl;
                    num = new complex(Re, Im);
                }
            }
            else
            {
                cout << "Неврный ввод.\n";
                cin.clear();
                while (cin.get() != '\n');
            }

            if (choice1 == 1 || choice1 == 2)
            {
                if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
                {
                    if (typeofdata == "int") ((Matrix<ListSequence<int>, int>*)mat1)->MatrixMult(*(int*)num);
                    if (typeofdata == "long int") ((Matrix<ListSequence<long>, long>*)mat1)->MatrixMult(*(long*)num);
                    if (typeofdata == "float") ((Matrix<ListSequence<float>, float>*)mat1)->MatrixMult(*(float*)num);
                    if (typeofdata == "double") ((Matrix<ListSequence<double>, double>*)mat1)->MatrixMult(*(double*)num);
                    if (typeofdata == "complex") ((Matrix<ListSequence<complex>, complex>*)mat1)->MatrixMult(*(complex*)num);
                    /*{
                        double Im = ((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetIm(), Re = ((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetRe();
                        ((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetIm() = Re * (*(complex*)num).GetIm() + Im * (*(complex*)num).GetRe();
                        ((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetRe() = Re * (*(complex*)num).GetRe() - Im * (*(complex*)num).GetIm();
                    }*/
                }
                if (((Matrix<ArraySequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
                {
                    if (typeofdata == "int") ((Matrix<ArraySequence<int>, int>*)mat1)->MatrixMult(*(int*)num);
                    if (typeofdata == "long int") ((Matrix<ArraySequence<long>, long>*)mat1)->MatrixMult(*(long*)num);
                    if (typeofdata == "float") ((Matrix<ArraySequence<float>, float>*)mat1)->MatrixMult(*(float*)num);
                    if (typeofdata == "double") ((Matrix<ArraySequence<double>, double>*)mat1)->MatrixMult(*(double*)num);
                    if (typeofdata == "complex") ((Matrix<ArraySequence<complex>, complex>*)mat1)->MatrixMult(*(complex*)num);
                    /*{
                        double Im = ((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetIm(), Re = ((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetRe();
                        ((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetIm() = Re * (*(complex*)num).GetIm() + Im * (*(complex*)num).GetRe();
                        ((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetRe() = Re * (*(complex*)num).GetRe() - Im * (*(complex*)num).GetIm();
                    }*/
                }
                break;
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

//void FindNorm(void* mat1)
//{
//    int width = 9;
//    int choice1 = 0;
//    cout << "Выберите тип нормы:\n1. Корень из суммы квадратов элементов матрицы.\n2. Максимальная из сум модулей элементов строк матрицы.\n3. Максимальная из сум модулей элементов столбцов матрицы.\n";
//    string typeofdata = ((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData();
//    try
//    {
//        while (1)
//        {
//            cin >> choice1;
//            if (choice1 == 1)
//            {
//                if (typeofdata == "int")
//                {
//                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        ((Matrix<ListSequence<int>, int>*)mat1)->FindNorm1(width);
//                    }
//                    else if (((Matrix<ArraySequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        ((Matrix<ArraySequence<int>, int>*)mat1)->FindNorm1(width);
//                    }
//                }
//                else if (typeofdata == "long int")
//                {
//                    long norm = 0;
//                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        ((Matrix<ListSequence<long>, long>*)mat1)->FindNorm1(width);
//                    }
//                    else if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        ((Matrix<ArraySequence<long>, long>*)mat1)->FindNorm1(width);
//                    }
//                }
//                else if (typeofdata == "float")
//                {
//                    float norm = 0;
//                    if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        ((Matrix<ListSequence<float>, float>*)mat1)->FindNorm1(width);
//                    }
//                    else if (((Matrix<ArraySequence<float>, float>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        ((Matrix<ArraySequence<float>, float>*)mat1)->FindNorm1(width);
//                    }
//                }
//                else if (typeofdata == "double")
//                {
//                    double norm = 0;
//                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        ((Matrix<ListSequence<double>, double>*)mat1)->FindNorm1(width);
//                    }
//                    else if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        ((Matrix<ArraySequence<double>, double>*)mat1)->FindNorm1(width);
//                    }
//                }
//                else if (typeofdata == "complex")
//                {
//                    double Re = 0, Im = 0;
//                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfRows(); i++) for (int j = 0; j < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            Re += pow(((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetRe(), 2) - pow(((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetIm(), 2);
//                            Im += 2 * ((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetRe() * ((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j).GetIm();
//                        }
//
//                    }
//                    else if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ArraySequence<complex>, complex>*)mat1)->GetNumOfRows(); i++) for (int j = 0; j < ((Matrix<ArraySequence<complex>, complex>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            Re += pow(((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetRe(), 2) - pow(((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetIm(), 2);
//                            Im += 2 * ((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetRe() * ((Matrix<ArraySequence<complex>, complex>*)mat1)->Get(i, j).GetIm();
//                        }
//
//                    }
//                    complex* norm = new complex(Re, Im);
//                    cout << "Норма: sqrt(" << *norm << ")\n";
//                }
//                break;
//            }
//            else if (choice1 == 3)
//            {
//                if (typeofdata == "int")
//                {
//                    int norm = 0;
//                    int norm1 = 0;
//                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfRows(); i++) norm += abs((int)((Matrix<ListSequence<int>, int>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ArraySequence<int>, int>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ArraySequence<int>, int>*)mat1)->GetNumOfRows(); i++) norm += abs((int)((Matrix<ArraySequence<int>, int>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "long int")
//                {
//                    long norm = 0;
//                    long norm1 = 0;
//                    if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ListSequence<long>, long>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ListSequence<long>, long>*)mat1)->GetNumOfRows(); i++) norm += abs((long)((Matrix<ListSequence<long>, long>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ArraySequence<long>, long>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ArraySequence<long>, long>*)mat1)->GetNumOfRows(); i++) norm += abs((long)((Matrix<ArraySequence<long>, long>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "float")
//                {
//                    float norm = 0;
//                    float norm1 = 0;
//                    if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ListSequence<float>, float>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ListSequence<float>, float>*)mat1)->GetNumOfRows(); i++) norm += abs((float)((Matrix<ListSequence<float>, float>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ArraySequence<long>, long>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ArraySequence<long>, long>*)mat1)->GetNumOfRows(); i++) norm += abs((long)((Matrix<ArraySequence<float>, float>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "double")
//                {
//                    double norm = 0;
//                    double norm1 = 0;
//                    if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ListSequence<double>, double>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ListSequence<double>, double>*)mat1)->GetNumOfRows(); i++) norm += abs((double)((Matrix<ListSequence<double>, double>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ArraySequence<double>, double>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ArraySequence<double>, double>*)mat1)->GetNumOfRows(); i++) norm += abs((double)((Matrix<ArraySequence<double>, double>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "complex")
//                {
//                    double norm = 0, norm1 = 0;
//                    if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfRows(); i++) norm += abs((complex)((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int j = 0; j < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfColumns(); j++)
//                        {
//                            norm = 0;
//                            for (int i = 0; i < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfRows(); i++) norm += abs((complex)((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << "\n";
//                }
//                break;
//            }
//            else if (choice1 == 2)
//            {
//                if (typeofdata == "int")
//                {
//                    int norm = 0;
//                    int norm1 = 0;
//                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ListSequence<int>, int>*)mat1)->GetNumOfColumns(); j++) norm += abs((int)((Matrix<ListSequence<int>, int>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ArraySequence<int>, int>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ArraySequence<int>, int>*)mat1)->GetNumOfColumns(); j++) norm += abs((int)((Matrix<ArraySequence<int>, int>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "long int")
//                {
//                    long norm = 0;
//                    long norm1 = 0;
//                    if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<long>, long>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ListSequence<long>, long>*)mat1)->GetNumOfColumns(); j++) norm += abs((long)((Matrix<ListSequence<long>, long>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ArraySequence<long>, long>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ArraySequence<long>, long>*)mat1)->GetNumOfColumns(); j++) norm += abs((long)((Matrix<ArraySequence<long>, long>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "float")
//                {
//                    float norm = 0;
//                    float norm1 = 0;
//                    if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<float>, float>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ListSequence<float>, float>*)mat1)->GetNumOfColumns(); j++) norm += abs((float)((Matrix<ListSequence<float>, float>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ArraySequence<float>, float>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ArraySequence<float>, float>*)mat1)->GetNumOfColumns(); j++) norm += abs((float)((Matrix<ArraySequence<float>, float>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "double")
//                {
//                    double norm = 0;
//                    double norm1 = 0;
//                    if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<double>, double>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ListSequence<double>, double>*)mat1)->GetNumOfColumns(); j++) norm += abs((double)((Matrix<ListSequence<double>, double>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ArraySequence<double>, double>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ArraySequence<double>, double>*)mat1)->GetNumOfColumns(); j++) norm += abs((double)((Matrix<ArraySequence<double>, double>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << endl;
//                }
//                else if (typeofdata == "complex")
//                {
//                    double norm = 0, norm1 = 0;
//                    if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfArray() == "LinkedArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfColumns(); j++) norm += abs((complex)((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//                    }
//                    else if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfArray() == "DynamicArr")
//                    {
//                        for (int i = 0; i < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfRows(); i++)
//                        {
//                            norm = 0;
//                            for (int j = 0; j < ((Matrix<ListSequence<complex>, complex>*)mat1)->GetNumOfColumns(); j++) norm += abs((complex)((Matrix<ListSequence<complex>, complex>*)mat1)->Get(i, j));
//                            if (norm1 < norm) norm1 = norm;
//                        }
//
//                    }
//                    cout << "Норма: " << setw(width) << norm1 << "\n";
//                }
//                break;
//            }
//            else
//            {
//                cout << "Неверный ввод\n";
//                cin.clear();
//                while (cin.get() != '\n');
//            }
//        }
//    }
//    catch (string ex)
//    {
//        throw ex;
//    }
//}

template<typename T, typename T1>
void FindNorm(Matrix<T, T1>* mat)
{
    int width = 9;
    int choice1 = 0;
    cout << "Выберите тип нормы:\n1. Корень из суммы квадратов элементов матрицы.\n2. Максимальная из сум модулей элементов строк матрицы.\n3. Максимальная из сум модулей элементов столбцов матрицы.\n";
    try
    {
        while (1)
        {
            cin >> choice1;
            if (choice1 == 1)
            {
                mat->FindNorm1(width);
                break;
            }
            else if (choice1 == 2)
            {
                mat->FindNorm2(width);
                break;
            }
            else if (choice1 == 3)
            {
                mat->FindNorm3(width);
                break;
            }
            else
            {
                cout << "Неверный ввод\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
    catch (string ex) 
    {
        throw ex;
    }
}

template<typename T, typename T1>
void transformations_rows(void* mat1)
{
    Matrix<T, T1>* mat = ((Matrix<T, T1>*)mat1);
    cout << "Выберите преобразование:\n1. Перестановка местами двух строк.\n2. Умножение на ненулевую константу строки.\n3. Прибавление к любой строке матрицы другой строки, умноженной на ненулевое число.\n";
    int choice1 = 0;
    try
    {
        while (1)
        {
            cin >> choice1;
            if (choice1 == 1)
            {
                while (1)
                {
                    int row1 = -1, row2 = -1;
                    cout << "Выберите первую строку для перестановки: ";
                    cin >> row1;
                    cout << "Выберите вторую строку для перестановки: ";
                    cin >> row2;
                    if (row1 < 0 || row1 >= mat->GetNumOfRows() || row2 < 0 || row2 >= mat->GetNumOfRows())
                    {
                        cout << "Неврный ввод\n";
                        cin.clear();
                        while (cin.get() != '\n');
                    }
                    else
                    {
                        mat->ChangeRows(row1, row2);
                        break;
                    }
                }
                break;
            }
            else if (choice1 == 2)
            {
                while (1)
                {
                    T1 num = T1();
                    int row = -1;
                    cout << "Введите ненулевую константу: ";
                    cin >> num;
                    cout << "Выберите строку для умножения: ";
                    cin >> row;
                    if (num == T1() || row < 0 || row >= mat->GetNumOfRows())
                    {
                        cout << "Неверный ввод\n";
                        cin.clear();
                        while (cin.get() != '\n');
                    }
                    else
                    {
                        mat->MultRow(row, num);
                    }
                }
                break;
            }
            else if (choice1 == 3)
            {
                while (1)
                {
                    T1 num = T1();
                    int row1 = -1, row2 = -1;
                    cout << "Введите ненулевую костанту: ";
                    cin >> num;
                    cout << "Выберите строку для умножения: ";
                    cin >> row1;
                    cout << "Выберите строку для сложения: ";
                    cin >> row2;
                    if (num == T1() || row1 < 0 || row1 >= mat->GetNumOfRows() || row2 < 0 || row2 >= mat->GetNumOfRows())
                    {
                        cout << "Неверный ввод\n";
                        cin.clear();
                        while (cin.get() != '\n');
                    }
                    else
                    {
                        mat->RowCombination(num, row1, row2);
                    }
                }
                break;
            }
            else
            {
                cout << "Неверный ввод\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

template<typename T, typename T1>
void transformations_columns(void* mat1)
{
    Matrix<T, T1>* mat = (Matrix<T, T1>*)mat1;
    cout << "Выберите преобразование:\n1. Перестановка местами двух столбцов.\n2. Умножение на ненулевую константу столбца.\n3. Прибавление к любому столбцу матрицы другого стобца, умноженного на ненулевое число.\n";
    int choice1 = 0;
    try
    {
        while (1)
        {
            cin >> choice1;
            if (choice1 == 1)
            {
                while (1)
                {
                    int column1 = -1, column2 = -1;
                    cout << "Выберите первый столбец для перестановки: ";
                    cin >> column1;
                    cout << "Выберите второй столбец для перестановки: ";
                    cin >> column2;
                    if (column1 < 0 || column1 >= mat->GetNumOfColumns() || column2 < 0 || column2 >= mat->GetNumOfColumns())
                    {
                        cout << "Неврный ввод\n";
                        cin.clear();
                        while (cin.get() != '\n');
                    }
                    else
                    {
                        mat->ChangeColumns(column1, column2);
                        break;
                    }
                }
                break;
            }
            else if (choice1 == 2)
            {
                while (1)
                {
                    T1 num = T1();
                    int column = -1;
                    cout << "Введите ненулевую константу: ";
                    cin >> num;
                    cout << "Выберите столбец для умножения: ";
                    cin >> column;
                    if (num == T1() || column < 0 || column >= mat->GetNumOfColumns())
                    {
                        cout << "Неверный ввод\n";
                        cin.clear();
                        while (cin.get() != '\n');
                    }
                    else
                    {
                        mat->MultColumn(column, num);
                    }
                }
                break;
            }
            else if (choice1 == 3)
            {
                while (1)
                {
                    T1 num = T1();
                    int column1 = -1, column2 = -1;
                    cout << "Введите ненулевую костанту: ";
                    cin >> num;
                    cout << "Выберите стобец для умножения: ";
                    cin >> column1;
                    cout << "Выберите стобец для сложения: ";
                    cin >> column2;
                    if (num == T1() || column1 < 0 || column1 >= mat->GetNumOfColumns() || column2 < 0 || column2 >= mat->GetNumOfColumns())
                    {
                        cout << "Неверный ввод\n";
                        cin.clear();
                        while (cin.get() != '\n');
                    }
                    else
                    {
                        mat->ColumnCombination(num, column1, column2);
                    }
                }
                break;
            }
            else
            {
                cout << "Неверный ввод\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
    catch (string ex)
    {
        throw ex;
    }
}

void Interface()
{
    //void* mat1 = GetMatrix();
    //((Matrix<ListSequence<int>, int>*)mat1)->PrintParams();
    int choice1 = 0, choice2 = 0, choice3 = 0;
    //void* mat1 = new Matrix<ListSequence<int>, int>();
    void* mat1 = nullptr;
    while (choice1 != 5) {
    start:
        choice1 = choice2 = choice3 = 0;
        cout << "Выберите действие: \n1. Создание матрицы\n2. Операции над матрицей\n3. Удаление матрицы\n4. Отображение матрицы\n5. Окончание программы\n";
        cin >> choice1;

        if (choice1 == 1)
        {
            if (mat1 != nullptr)
            {
                cout << "При создании новой матрицы будет удалена старая, продолжить?\n1. Да\n2. Нет\n";
                cin >> choice2;
                if (choice2 == 2) goto start;
                else if (choice2 != 1) {
                    cout << "Неверный ввод\n";
                    cin.clear();
                    while (cin.get() != '\n');
                    goto start;
                }
            }
            delete mat1;
            mat1 = nullptr;
            try {
                mat1 = GetMatrix();
            }
            catch (string ex)
            {
                cout << "Во время создания матрицы произошла ошибка: " << ex << endl;
            }
            while (1)
            {
                cout << "Выберите способ задания матрицы:\n1. Случайно.\n2. Вручную.\n";
                cin >> choice2;
                if (choice2 == 1)
                {
                    try {
                        RandomizeMatrix(mat1);
                    }
                    catch (string ex)
                    {
                        cout << "Во время заполнения матрицы псевдослучайными числами произошла ошибка:" << ex << endl;
                    }
                }
                else if (choice2 == 2)
                {
                    try {
                        ByHandMatrix(mat1);
                    }
                    catch (string ex)
                    {
                        cout << "Во время заполнения матрицы числами из консоли произошла ошибка:" << ex << endl;
                    }
                }
                else
                {
                    cout << "Неверный ввод\n";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                if (choice1 == 1 || choice1 == 2) break;
            }
        }

        else if (choice1 == 2)
        {
            if (mat1 == nullptr)
            {
                cout << "Матрица не обнаружена\n";
                goto start;
            }
            cout << "Выберите операцию:\n1. Сложение.\n2. Умножение на скаляр.\n3. Вычисление нормы.\n4. Элементарные преобразования строк.\n5. Элементарные преобразования столбцов.\n";
            cin >> choice2;
            if (choice2 == 1)
            {
                try {
                    MatrixSum(mat1);
                }
                catch (string ex)
                {
                    cout << "Во время сложения матриц произошла ошибка:" << ex << endl;
                }
            }
            else if (choice2 == 2)
            {
                try {
                    MatrixMult(mat1);
                }
                catch (string ex)
                {
                    cout << "Во время умножения матрицы на скаляр произошла ошибка:" << ex << endl;
                }
            }
            else if (choice2 == 3)
            {
                
                try {
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
                    {
                        if (((Matrix<ArraySequence<int>, int>*)mat1)->GetTypeOfData() == "int") FindNorm<ArraySequence<int>, int>((Matrix<ArraySequence<int>, int>*)mat1);
                        if (((Matrix<ArraySequence<float>, float>*)mat1)->GetTypeOfData() == "float") FindNorm<ArraySequence<float>, float>((Matrix< ArraySequence<float>, float >*)mat1);
                        if (((Matrix<ArraySequence<long>, long>*)mat1)->GetTypeOfData() == "long int") FindNorm<ArraySequence<long>, long>((Matrix<ArraySequence<long>, long>*)mat1);
                        if (((Matrix<ArraySequence<double>, double>*)mat1)->GetTypeOfData() == "double") FindNorm<ArraySequence<double>, double>((Matrix<ArraySequence<double>, double>*)mat1);
                        if (((Matrix<ArraySequence<complex>, complex>*)mat1)->GetTypeOfData() == "complex") FindNorm<ArraySequence<complex>, complex>((Matrix<ArraySequence<complex>, complex>*)mat1);
                    }
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
                    {
                        if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "int") FindNorm<ListSequence<int>, int>((Matrix<ListSequence<int>, int>*)mat1);
                        if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfData() == "float") FindNorm<ListSequence<float>, float>((Matrix<ListSequence<float>, float>*)mat1);
                        if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfData() == "long int") FindNorm<ListSequence<long>, long>((Matrix<ListSequence<long>, long>*)mat1);
                        if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfData() == "double") FindNorm<ListSequence<double>, double>((Matrix<ListSequence<double>, double>*)mat1);
                        if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfData() == "complex") FindNorm<ListSequence<complex>, complex>((Matrix<ListSequence<complex>, complex>*)mat1);
                    }
                }
                catch (string ex)
                {
                    cout << "Во время поиска нормы матрицы произошла ошибка:" << ex << endl;
                }
            }
            else if (choice2 == 4)
            {
                try
                {
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
                    {
                        if (((Matrix<ArraySequence<int>, int>*)mat1)->GetTypeOfData() == "int") transformations_rows<ArraySequence<int>, int>(mat1);
                        if (((Matrix<ArraySequence<float>, float>*)mat1)->GetTypeOfData() == "float") transformations_rows<ArraySequence<float>, float>(mat1);
                        if (((Matrix<ArraySequence<long>, long>*)mat1)->GetTypeOfData() == "long int") transformations_rows<ArraySequence<long>, long>(mat1);
                        if (((Matrix<ArraySequence<double>, double>*)mat1)->GetTypeOfData() == "double") transformations_rows<ArraySequence<double>, double>(mat1);
                        if (((Matrix<ArraySequence<complex>, complex>*)mat1)->GetTypeOfData() == "complex") transformations_rows<ArraySequence<complex>, complex>(mat1);
                    }
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
                    {
                        if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "int") transformations_rows<ListSequence<int>, int>(mat1);
                        if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfData() == "float") transformations_rows<ListSequence<float>, float>(mat1);
                        if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfData() == "long int") transformations_rows<ListSequence<long>, long>(mat1);
                        if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfData() == "double") transformations_rows<ListSequence<double>, double>(mat1);
                        if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfData() == "complex") transformations_rows<ListSequence<complex>, complex>(mat1);
                    }
                }
                catch (string ex)
                {
                    cout << "Во время элементарных преобразований строк произошла ошибка: " << ex << endl;
                }
            }
            else if (choice2 == 5)
            {
                try
                {
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "DynamicArr")
                    {
                        if (((Matrix<ArraySequence<int>, int>*)mat1)->GetTypeOfData() == "int") transformations_columns<ArraySequence<int>, int>(mat1);
                        if (((Matrix<ArraySequence<float>, float>*)mat1)->GetTypeOfData() == "float") transformations_columns<ArraySequence<float>, float>(mat1);
                        if (((Matrix<ArraySequence<long>, long>*)mat1)->GetTypeOfData() == "long int") transformations_columns<ArraySequence<long>, long>(mat1);
                        if (((Matrix<ArraySequence<double>, double>*)mat1)->GetTypeOfData() == "double") transformations_columns<ArraySequence<double>, double>(mat1);
                        if (((Matrix<ArraySequence<complex>, complex>*)mat1)->GetTypeOfData() == "complex") transformations_columns<ArraySequence<complex>, complex>(mat1);
                    }
                    if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfArray() == "LinkedArr")
                    {
                        if (((Matrix<ListSequence<int>, int>*)mat1)->GetTypeOfData() == "int") transformations_columns<ListSequence<int>, int>(mat1);
                        if (((Matrix<ListSequence<float>, float>*)mat1)->GetTypeOfData() == "float") transformations_columns<ListSequence<float>, float>(mat1);
                        if (((Matrix<ListSequence<long>, long>*)mat1)->GetTypeOfData() == "long int") transformations_columns<ListSequence<long>, long>(mat1);
                        if (((Matrix<ListSequence<double>, double>*)mat1)->GetTypeOfData() == "double") transformations_columns<ListSequence<double>, double>(mat1);
                        if (((Matrix<ListSequence<complex>, complex>*)mat1)->GetTypeOfData() == "complex") transformations_columns<ListSequence<complex>, complex>(mat1);
                    }
                }
                catch (string ex)
                {
                    cout<< "Во время элементарных преобразований столбцов произошла ошибка : " << ex << endl;
                }
            }
            else
            {
                cout << "Неверный ввод\n";
                cin.clear();
                while (cin.get() != '\n');
            }
        }

        else if (choice1 == 3)
        {
            if (mat1 == nullptr)
            {
                cout << "Матрица не обнаружена\n";
            }
            else
            {
                delete mat1;
                mat1 = nullptr;
                cout << "Матрица удалена\n";
            }
        }

        else if (choice1 == 4)
        {
            if (mat1 == nullptr)
            {
                cout << "Матрица не обнаружена\n";

            }
            else
            {
                try
                {

                    MatrixToConsole(mat1);
                }
                catch (string ex)
                {
                    cout << "Во время вывода матрицы в консоль произошла ошибка: " << ex << endl;
                }
            }
        }
        else if (choice1 != 5)
        {
            cout << "Неверный ввод\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}