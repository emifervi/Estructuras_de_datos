# Hash, Set y Map
### Emilio Fernando Alonso Villa
### A00959385
### ITC
> ## Hash
> es una mejora a las tablas de accesamiento directo, estas funciones permiten a insertar, borrar y buscar data en con una complejidad de: **O(1)**.<br>
> Algunas de las funciones <br><br>
> En C++ se utiliza de la siguiente manera:
>```C++
>#include <iostream>
>#include <functional>
>using namespace std;
>
>int main(){
>    // sintaxys: hash<data_type> name;
>    // ej.-
>
>    string clase = "Estructura";
>
>    hash<char> stringHash;
>    stringHash(clase);
>
>    return 0;
>}
>```
> En este caso la función hash nos retornaría el valor hash del argumento dado. Este valor tiende a ser un valor numérico el cual se utilizaría para referenciar la variable a la hora de guardarla en un hash set o hash map.

> ## Map
> es un tipo de contenedor que funciona de manera asociativa, guardando de manera desordenada parejas de valores llave y valores _mapeados_, estos contenedores son iterables y para acceder a los valores guardados, utilizamos los valores llave como _indice_ para acceder a los valores. Estas llaves nos sriven para ordenar el mapa.<br>
> Algunas de las operaciones que soportan:
> - find(): iterador que sirve para encontrar el elemento en el mapa.
> - count(): retorna el número de elementos que tienen una llave.
> - lower_bound(): un iterador que regresa el primer elemento con una llave de mayor o igual valor al objetivo.
> - upper_bound(): iterador que regresa el primer elmento que va _después_ del objetivo.
> - equal_range(): retorna dos parejas, las cuales representan el lower_bound y el upper_bound, respectivamente.
>
> En C++ se usa de la sigueinte manera
> ```C++
>#include <iostream>
>#include <map>
>using namespace std;
>
>int main(){
>   map<string,int> teams;
>   teams["Barcelona"] = 21;
>   teams["Real Madrid"]= 14;
>   teams["Alavés"] = 20;
>   for(auto team : teams){
>       cout << team.first << " " << team.second << endl; 
>   }
>}
>
> Output:
> Barcelona 21
> Real Madrid 14
> Alaves 20
> ```
>Estos contenedores guardan llaves únicas y a nivel físico suelen estar implementados como un BST.

>## Sets
>Son muy parecidos a los mapas previamente mencionados, pero estos se parecen más a un array. No obstante, estos sólo guardan valores únicos en el contenedor y su valor funciona como su propia llave. 
>Los valores en el set no pueden ser modificados, pero si se soporta la inserción y borrado de valores.
>Algunas de las operaciones que se soportan en C++:
> - find(): iterador que sirve para encontrar el elemento en el set, si no se encuentra, llega hasta el final y lo retorna.
> - count(): retorna el número de elementos en el set que tienen una llave especificada.
> - lower_bound(): un iterador que regresa el primer elemento con una llave de mayor o igual valor al objetivo.
> - upper_bound(): iterador que regresa el primer elmento que va _después_ del objetivo.
> - equal_range(): retorna dos parejas, las cuales representan el lower_bound y el upper_bound, respectivamente.
>
> En C++ se usa de la sigueinte manera
> ```C++
>#include <iostream>
>#include <set>
>using namespace std;
>int main(){}
>   set<int> califs;
>   califs.insert(82);
>   califs.insert(100);
>   califs.insert(91)
>
>   for(auto calif : califs){
>       cout << calif << endl; 
>   }
>
>   return 0;
>}
> ```
> &nbsp;
