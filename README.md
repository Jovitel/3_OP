//3 užduotis//

Sukūriau Vector klasę, kuri yra pilnavertė alternatyva std::vector konteineriui, t.y. visi fonkciunalumai (Member types, Member functions, Non-member functions). Naudojausi: https://en.cppreference.com/w/cpp/container/vector

# Įsitikinti, ar Vector konteineris veikia (funkcionalumo prasme) lygiai taip, kaip std::vector

Pasirinkau 5 funkcijas ir stebėjau, ar gauti rezultatai su Vector konteineriu atitinka std::vector rezultatus. Naudojausi: https://en.cppreference.com/w/cpp/container/vector

**MAZ_SIZE():**

``` Vector<char> p;
    Vector<long> q;
 
    locale("C"));
    cout << uppercase
         << "p.max_size() = " << std::dec << p.max_size() << " = 0x"
         << std::hex << p.max_size() << '\n'
         << "q.max_size() = " << std::dec << q.max_size() << " = 0x"
         << std::hex << q.max_size() << '\n';
```

#### (TEISINGAS) OUTPUT:

```
p.max_size() = 9,223,372,036,854,775,807 = 0x7,FFF,FFF,FFF,FFF,FFF
q.max_size() = 1,152,921,504,606,846,975 = 0xFFF,FFF,FFF,FFF,FFF
```
**EMPTY():**

```
    cout << boolalpha;
    vector<int> numbers;
    cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
```

#### (TEISINGAS) OUTPUT:

```
Initially, numbers.empty(): true
After adding elements, numbers.empty(): false
```
**PUSH_BACK():**

```
    Vector<string> letters;
 
    letters.push_back("abc");
    string s{"def"};
    letters.push_back(move(s));
 
    std::cout << "std::vector letters holds: ";
    for (auto&& e : letters)
        cout << quoted(e) << ' ';
 
    cout << "\nMoved-from string s holds: " << quoted(s) << '\n';
```

#### (TEISINGAS) OUTPUT:

```
std::vector letters holds: "abc" "def"
Moved-from string s holds: ""
```
**OPERATOR = :**

```
    Vector<int> foo (3,0);
    Vector<int> bar (5,0);

    bar = foo;
    foo = Vector<int>();

    cout << "Size of foo: " << int(foo.size()) << '\n';
    cout << "Size of bar: " << int(bar.size()) << '\n';

```

#### (TEISINGAS) OUTPUT:

```
Size of foo: 0
Size of bar: 3

```
**SWAP():**

```
      Vector<int> alice{1, 2, 3};
    Vector<int> bob{7, 8, 9, 10};
 
    auto print = [](const int& n) { cout << ' ' << n; };
 
    // Print state before swap
    cout << "Alice:";
    for_each(alice.begin(), alice.end(), print);
    cout << "\n" "Bob  :";
    for_each(bob.begin(), bob.end(), print);
    cout << '\n';
 
    cout << "-- SWAP\n";
    swap(alice, bob);
 
    // Print state after swap
    cout << "Alice:";
    for_each(alice.begin(), alice.end(), print);
    cout << "\n" "Bob  :";
    for_each(bob.begin(), bob.end(), print);
    cout << '\n';
```

#### (TEISINGAS) OUTPUT:

```
Alice: 1 2 3
Bob  : 7 8 9 10
-- SWAP
Alice: 7 8 9 10
Bob  : 1 2 3
```

Visi rezultatai sutampa.

# Efektyvumo/spartos analizė std::vector vs Vector

Skaičiuoju, kiek vidutiniškai laiko užtrunka užpildyti tuščius vektorius: 10 000, 100 000, 1 000 000, 10 000 000 ir 100 000 000 int elementų naudojant push_back() funkciją.

|                 |   10 000   |   100 000  |  1 000 000 | 10 000 000 | 100 000 000 |  iš viso   |
|:---------------:|:----------:|-----------:| ----------:|-----------:|------------:|-----------:|
| _std::vector_   | 0.0008438s | 0.0059773s | 0.0387429s | 0.184515s  |  1.4759s    | 1,705979s  |
| _Vector_        | 0.000569s  | 0.0061737s | 0.0113419s | 0.118442s  |  1.14663s   | 1,2831566s |

#### Rezultatai:

Mažiausiau laiko uztrunka su Vector.
