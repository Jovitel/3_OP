//3 užduotis//

Sukūriau Vector klasę, kuri yra pilnavertė alternatyva std::vector konteineriui, t.y. visi fonkciunalumai (Member types, Member functions, Non-member functions). Naudojausi: https://en.cppreference.com/w/cpp/container/vector

**Įsitikinti, ar Vector konteineris veikia (funkcionalumo prasme) lygiai taip, kaip std::vector**

Pasirinkau 5 funkcijas ir stebėjau, ar gauti rezultatai su Vector konteineriu atitinka std::vector rezultatus.

**MAZ_SIZE()**

``` Vector<char> p;
    Vector<long> q;
 
    cout.imbue(locale("en_US.UTF-8"));
    cout << uppercase
         << "p.max_size() = " << std::dec << p.max_size() << " = 0x"
         << std::hex << p.max_size() << '\n'
         << "q.max_size() = " << std::dec << q.max_size() << " = 0x"
         << std::hex << q.max_size() << '\n';
```

#### (TEISINGAS) OUTPUT:

```p.max_size() = 9,223,372,036,854,775,807 = 0x7,FFF,FFF,FFF,FFF,FFF

q.max_size() = 1,152,921,504,606,846,975 = 0xFFF,FFF,FFF,FFF,FFF
```

