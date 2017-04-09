#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     float dato;
     struct nodo *izq, *der;
};

typedef struct nodo *ArbolBinarioBusqueda;

ArbolBinarioBusqueda crearNodo(float numero)
{
     ArbolBinarioBusqueda nuevoNodo = new(struct nodo);
     nuevoNodo->dato = numero;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ArbolBinarioBusqueda &arbol, float numero)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(numero);
     }
     else if(numero < arbol->dato)
          insertar(arbol->izq, numero);
     else if(numero > arbol->dato)
          insertar(arbol->der, numero);
}

void profundidad(ArbolBinarioBusqueda arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->dato <<" ";
          profundidad(arbol->izq);
          profundidad(arbol->der);
     }
}

void verArbol(ArbolBinarioBusqueda arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->dato <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    ArbolBinarioBusqueda arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    float numero; // elemento a insertar en cada nodo

    cout << "\n\t\t ARBOL BINARIO DE BUSQUEDA\n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> numero;
        insertar( arbol, numero);
    }

    cout << "\n Mostrando Arbol Binario Busqueda \n\n";
    verArbol( arbol, 0);

    cout << "\n Recorridos del Arbol Binario Busqueda";


    cout << "\n\n Profundidad  :  ";   profundidad(arbol);//Primero el padre, luego el hijo izquierdo y finalmente el hijo derecho.


    cout << endl << endl;

    system("pause");
    return 0;
}
