#include <iostream>
using namespace std;

template <typename TypeE>
class Univers
{
public:
    int n;
    TypeE* U;
    Univers(int nn, TypeE* u) : n(nn)
    {
        U = new TypeE[n];
        for (int i = 0; i < n; i++)
            U[i] = u[i];
    }
    TypeE& operator [] (int i)
    {
        return U[i];
    }
    int N() { return n; }
};

template <typename TypeE>
class Set
{
private:
    Univers<TypeE>* U0;
public:
    int n;
    int* shk;
    Set(Univers<TypeE>& U)
    {
        n = U.N();
        cout << "n=" << n << endl;
        shk = new int[n];
        for (int i = 0; i < n; i++)
            shk[i] = 0;
        U0 = &U;
    }
    void add(int i) 
    {
        shk[i] = 1;
    }

    void print() {
        for (int i = 0; i < n; i++)
        {
            if (shk[i] == 1)
                cout << (*U0)[i] << " ";
        }
    }

    void add2(TypeE x) {
        for (int i = 0; i < n; i++) {
            if ((*U0)[i] == x)
                add(i);
        }
    }

    /*   void Union(Set s01, Set s02, Set s00){
           for (int i = 0; i < n; i++) {
               if (s01.shk[i] == 1) and (s02.shk[i] = 1) {
               s00.shk[i] = 1};
           }
       }*/
};

int main()
{
    int m[5] = { 17,36,96,3555,41414 };
    Univers<int> intU(5, m);
    cout << "intU="; for (int i = 0; i < 5; i++) cout << intU[i] << ' ';
    cout << endl;

    Set<int> s1(intU);

    cout << "s1=";
    s1.print();
    cout << endl;

    s1.add(2);
    s1.add2(3555);
    cout << "s1=";
    s1.print();
    cout << endl;

    /* Set<int> s3(intU);
    Set<int> s4(intU);

    s3.add2(17);
    Union(s1, s3, s4);
    cout << "Union is "
        s4.print();
    cout << endl; */

        float mm[6] = { 0.0,1.1,2.2,3.3,4.4,5.5 };
    Univers<float> floatU(6, mm);
    for (int i = 0; i < 6; i++) intU[i] = i; cout << endl;
    cout << "floatU="; for (int i = 0; i < 6; i++) cout << floatU[i] << ' ';
    cout << endl;

    Set<float> s2(floatU);
    cout << "s2=";
    s2.print();
    cout << endl;

    s2.add2(4.4);
    s2.add(3);
    cout << "s2=";
    s2.print();
    return 0;
}
// добавить объединение set-ов