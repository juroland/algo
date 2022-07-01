template<typename T>
Vector<T>::Vector(int size): size_{size}, elem_{new T[size]} {}

template<typename T>
Vector<T>::~Vector() { delete[] elem_; }

template<typename T>
typename Vector<T>::value_type&
Vector<T>::operator[](int i) { return elem_[i]; }

template<typename T>
const typename Vector<T>::value_type&
Vector<T>::operator[](int i) const { return elem_[i]; }

template<typename T>
int 
Vector<T>::size() const { return size_; }
