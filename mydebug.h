#ifndef _MYDEBUG_H_
#define _MYDEBUG_H_

#define NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define F_1(F, ARG) F(ARG)
#define F_2(F, ARG, ...) F(ARG) F_1(F, __VA_ARGS__)
#define F_3(F, ARG, ...) F(ARG) F_2(F, __VA_ARGS__)
#define F_4(F, ARG, ...) F(ARG) F_3(F, __VA_ARGS__)
#define F_5(F, ARG, ...) F(ARG) F_4(F, __VA_ARGS__)
#define F_6(F, ARG, ...) F(ARG) F_5(F, __VA_ARGS__)
#define FOR_EACH(F, ...)                                                       \
  NTH_ARG(__VA_ARGS__, F_6, F_5, F_4, F_3, F_2, F_1)(F, __VA_ARGS__)

#define C_RED "\033[2;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define C_RESET "\033[0m"

#define watch(x) cerr << C_GREEN #x " = " C_BLUE << (x) << C_RESET "; ";
#define debug(...)                                                             \
  cerr << C_RED "Line " << __LINE__ << ": " C_RESET;                           \
  FOR_EACH(watch, __VA_ARGS__)                                                 \
  cerr << endl

#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &t) {
  os << '{';
  bool f = 1;
  apply([&](auto &&... args) { ((os << (f ? "" : ", ") << args, f = 0), ...); },
        t);
  return os << '}';
}

template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  for (auto it = begin(c); it != end(c); ++it)
    os << (it == begin(c) ? "" : ", ") << *it;
  return os << ']';
}

template <class T, size_t size, class = enable_if_t<!is_same<T, char>::value>>
ostream &operator<<(ostream &os, const T (&arr)[size]) {
  os << '[';
  for (auto it = begin(arr); it != end(arr); ++it)
    os << (it == begin(arr) ? "" : ", ") << *it;
  return os << ']';
}
#endif
