#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define ALL(v)     (v).begin(),(v).end()
using ll  = long long;
using vi  = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using namespace std;
constexpr int       INF  = 1e9;
constexpr long long LINF = 1e18;
constexpr double    EPS  = 1e-10;
constexpr int       MOD  = 998'244'353;
constexpr int       MOD2 = 1e9+7;

#define DEBUG

#ifdef DEBUG

#define debug(...) debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#define dline(a) dline_internal(__LINE__, #a, a);

template <typename T, class... Args>
void debug_internal(int l, const char *context, T &&first, Args &&...args) {
    constexpr const char *open_brackets = (sizeof...(args) == 0 ? "" : "(");
    constexpr const char *close_brackets = (sizeof...(args) == 0 ? "" : ")");
    std::cerr << "[L" << l << "] " << open_brackets << context << close_brackets << ": "
              << open_brackets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brackets << std::endl;
}

template <class Class>
void dline_internal(int l, const char *context, const Class &a) {
    std::cerr << "[L" << l << "] " << context << ": ";
    int cnt = 0;
    for(const auto &elem : a) std::cerr << (cnt++ == 0 ? "" : " ") << elem;
    std::cerr << std::endl;
}

#else

#define debug(...) void(0)
#define dline(a) void(0)

#endif

template <typename Type>
std::istream &operator>>(std::istream &is, std::vector<Type> &v) {
    for(auto &in : v) is >> in;
    return is;
}

template <typename Type>
std::ostream &operator<<(std::ostream &os, const std::vector<Type> &v) {
    int cnt = 0;
    for(const auto &out : v) os << (cnt++ ? " " : "") << out;
    return os;
}


// template <class T>
// class has_iterator {
//   template <class U>
//   static constexpr std::true_type check(typename U::iterator*);

//   template <class U>
//   static constexpr std::false_type check(...);

// public:
//   static constexpr bool value = decltype(check<T>(nullptr))::value;
// };


// struct has_iterator_impl {
//   template <class T>
//   static std::true_type check(typename T::iterator*);

//   template <class T>
//   static std::false_type check(...);
// };

// template <class T>
// class has_iterator :
//   public decltype(has_iterator_impl::check<T>(nullptr)) {};

#include <iostream>
#include <iterator>
#include <type_traits>

// テンプレートクラス has_iterator を定義する
template <typename T, typename = void>
struct has_iterator : std::false_type {};

// テンプレートクラス has_iterator にイテレータを持つクラスが与えられた場合、std::void_t を使って std::iterator_traits を取得し、
// その型が定義されていることを確認する
template <typename T>
struct has_iterator<T, std::void_t<typename std::iterator_traits<typename T::iterator>::value_type>>
    : std::true_type {};

// イテレータを持つクラスのみを引数にとる関数
template <typename T, typename std::enable_if<has_iterator<T>::value, int>::type = 0>
void func(T container) {
    std::cout << "This container has an iterator.\n";
    // containerを使った処理
}

// イテレータを持たないクラスの場合にコンパイルエラーを出力する
template <typename T, typename std::enable_if<!has_iterator<T>::value, int>::type = 0>
void func(T container) {
    // static_assert(has_iterator<T>::value, "This container does not have an iterator.");
    cout<<"This container does not have an iterator."<<endl;
}

// 使用例
#include <vector>
#include <list>
#include <string>

int main() {
    std::vector<int> v;
    std::list<double> l;
    std::string s;
    int a;
    
    func(v); // OK
    func(l); // OK
    func(s); // コンパイルエラー
    func(a);
}


// int main(){
//     int a;
//     double b;
//     string s="abc";
//     vi v({1,2,3,4,5});

//     debug(has_iterator<decltype(a)>::value);
//     debug(has_iterator<decltype(b)>::value);
//     debug(has_iterator<decltype(s)>::value);
//     debug(has_iterator<decltype(v)>::value);
// }
