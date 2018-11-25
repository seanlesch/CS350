#include "Alphabet.h"

template <class T>
Alphabet<T>::Alphabet(T alphabet)
{
  Vector<T> alpha = new Vector<T>();
  for (int iter = 0; iter < alphabet.size(); iter++ )
  {
    alpha[iter] = alphabet[iter];
  }
}

template <class T>
Alphabet<T>::~Alphabet()
{
  delete alpha;
}