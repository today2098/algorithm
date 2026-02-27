---
title: 動的Modint構造体
documentation_of: //algorithm/Math/ModularArithmetic/dynamic_modint.hpp
---


## 概要

実行時に法が決まる Modint 構造体．

インスタンスを生成する前に法とする自然数を設定する．

```cpp
DynamicModint<0>::set_modulus(5);
DynamicModint<0> a = 13;
DynamicModint<0> b = 17;
cout << a << " " << b << endl;  // 3 2

DynamicModint<1>::set_modulus(17);
DynamicModint<1> c = 13;
DynamicModint<1> d = 17;
cout << c << " " << d << endl;  // 13 0
```
