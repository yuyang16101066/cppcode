#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <memory>
using namespace std;
template <typename T>
int compare(const T &v1, const T &v2){
    if (v1 < v2) return -1;
    if (v1 < v2) return 1; 
    return 0;
}
template <typename T>
T foo(T *p){
    T tmp = *p;
    return tmp;
}
template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]){
    return strcmp(p1, p2);
}
template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type; 
    Blob(): data(make_shared<vector<T>>()) {};
    Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) { };
    size_type size() const { return data -> size(); }
    bool empty() const { return data -> empty(); }
    void push_back(const T &t) { data -> push_back(t); }
    void push_back(T &&t) { data -> push_back(move(t)); }
    void pop_back();
    T& front();
    T& back();
    T& operator [] (size_type i);
private:
    shared_ptr<vector<T>> data;
    void check(sizetype i, const string &msg) const;
};
int main(){
    cout << compare("hi", "hello") << endl;
    int p = 5;
    cout << foo(&p) << endl;
}