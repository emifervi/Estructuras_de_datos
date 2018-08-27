
template <class T>
class Lista{
private:
    // Attributes
    T arrDatos[10];
    int iCant;
    void bubble(T arr[], int n, bool ascending);

public:
    Lista();
    Lista(const Lista &lList);

    int getCant();
    T getDato(int iPosition);

    bool add(T data);
    int search(T data);
    void sort(bool order);

    Lista<T> operator = (const Lista<T> &lLista);
    bool operator == (const Lista<T> &lLista);
    void print();
};

template <class T>
Lista<T>::Lista(){
    this->iCant = 0;
}

template <class T>
Lista<T>::Lista(const Lista<T> &lLista){
    for (int i = 0; i < lLista.iCant; i++){
        arrDatos[i] = lLista.arrDatos[i];
    }
    this -> iCant = lLista.iCant;
}

template <class T>
int Lista<T>::getCant(){
    return iCant;
}

template <class T>
T Lista<T>::getDato(int iPosition){
    return arrDatos[iPosition];
}

template <class T>
bool Lista<T>::add(T data){
    if(iCant >= 10){
        return false;
    }
    else{
        arrDatos[iCant] = data;
        iCant++;
        return true;
    }
}

template <class T>
int Lista<T>::search(T data){
    for(int i = 0; i < iCant; i++){
        if (arrDatos[i] == data){
            return i;
        }
    }
    return -1;
}

// Bubble Sort de Slides;
template <class T>
void Lista<T>::bubble(T arr[], int n, bool ascending){
    bool flag = true;
    T aux;
    for (int i = 0; i < n -1 && flag; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(ascending){
                if(arr[j+1] < arr[j]){
                    aux = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = aux;
                    flag = true;
                }
            }
            else{
                if(arr[j+1] > arr[j]){
                    aux = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = aux;
                    flag = true;
                }
            }
        }
    }
}

template <class T>
void Lista<T>::sort(bool order){
    bubble(arrDatos, iCant, order);
}

template <class T>
Lista<T> Lista<T>::operator = (const Lista<T> &lLista){
    *this=(lLista);   
}

template <class T>
bool Lista<T>::operator == (const Lista<T> &lLista){
    if(this->iCant != lLista.iCant){
        return false;
    }
    else{
        for(int i = 0; i < this->iCant; i++){
            if(this->arrDatos[i] != lLista.arrDatos[i]){
                return false;
            }
        }
        return true;
    }
}

template <class T>
void Lista<T>::print(){
    for (int i = 0; i < iCant; i++){
        cout << i << " - " << arrDatos[i] << endl;
    }
}