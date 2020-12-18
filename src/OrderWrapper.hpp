//
// Created by Stercutius on 18/12/2020.
// Permet d'écrire les ordres plus clairement. Pour cela, au lieu d'extraire
// manuellement les arguments d'un BufferedData, on écrit la fonction de manière
// naturelle, c'est-à-dire :
//
// int ordre(int a, double b) {
//    ...
// }
//
// Au lieu de :
//
// BufferedData* ordre(BufferedData& buffered_data) {
//   int a; double b;
//   getData(a, &buffered_data);
//   getData(b, &buffered_data);
//
//   ...
//
//   auto return_buffer_ptr = new BufferedData(sizeof(return_value));
//   putData(return_value, return_buffer_ptr);
//   return return_buffer_ptr;
// }
//
// C'est plus joli non ? :)
// Pour passer l'ordre en callback à I2CC, il suffit alors de faire :
//
// registerRPC(WRAP_ORDER(order), [le numéro de l'ordre]);
//

#pragma once

// decay maison, parce que j'ai la flemme d'inclure la bibliothèque standard.
// C'est légèrement moins bien que std::decay, parce que ça fait juste sauter
// les const, & et &&.
template<typename T>
struct decay {
  using type = T;
};
template<typename T>
struct decay<T&> : decay<T> {};
template<typename T>
struct decay<const T&> : decay<T> {};
template<typename T>
struct decay<T&&> : decay<T> {};
template<typename T>
struct decay<const T&&> : decay<T> {};
template<typename T>
using decay_t = typename decay<T>::type;

// Retourne la valeur réccupérée grâce à un appel à 'getData'
using I2CC::getData;
template<typename T>
auto forward_arguments(BufferedData& buffered_data) {
  decay_t<T> value;
  getData(value, &buffered_data);
  return value;
}

// Extraire les arguments de 'buffered_data' pour les passer à 'function'
// Si les données ont bien été insérées dans le BufferedData de retour, un
// pointeur valide est retourné. Sinon, la fonction retourne nullptr.
// Si R = void, la fonction retourne nullptr.
using I2CC::putData;
template<typename R, typename... Args>
BufferedData* unfold(R(function)(Args...), BufferedData& buffered_data) {
  auto&& return_value = function(forward_arguments<Args>(buffered_data)...);
  auto   return_buffer_ptr = new BufferedData(sizeof(return_value));

  // Le 1er argument de 'putData' est un const T& : pas d'optimisation à faire
  if (putData(return_value, return_buffer_ptr)) {
    return return_buffer_ptr;
  } else {
    free(return_buffer_ptr); //undefined reference to delete(void*, unsigned int)
    return nullptr;
  }
}
template<typename... Args>
BufferedData* unfold(void(function)(Args...), BufferedData& buffered_data) {
  function(forward_arguments<Args>(buffered_data)...);
  return nullptr;
}

// Executer l'ordre emballé
template<typename F, F function>
BufferedData* order(BufferedData& buffered_data) {
  return unfold(function, buffered_data);
}

#define WRAP_ORDER(f) order<decltype(f)*, f>
