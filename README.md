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

Skaičiuoju, kiek vidutiniškai laiko užtrunka užpildyti tuščius vektorius: 10 000, 100 000, 1 000 000, 10 000 000 
ir 100 000 000 int elementų naudojant push_back() funkciją. 

|                 |   10 000   |   100 000  |  1 000 000 | 10 000 000 | 100 000 000 |  iš viso   |
|:---------------:|:----------:|-----------:| ----------:|-----------:|------------:|-----------:|
| _std::vector_   | 0.0008438s | 0.0059773s | 0.0387429s | 0.184515s  |  1.4759s    | 1,705979s  |
| _Vector_        | 0.000569s  | 0.0061737s | 0.0113419s | 0.118442s  |  1.14663s   | 1,2831566s |

#### Rezultatai:

Mažiausia laiko uztrunka su Vector.

# Kiek kartų įvyksta konteinerių (Vector ir std::vector) atminties perskirstymai užpildant 100000000 elementų.

Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: capacity() == size(), t.y. kai nelieka vietos capacity()`naujiems elementams.

#### Naudotas kodas:

```
 auto start = std::chrono::steady_clock::now();
    unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
    int std_vector = 0;
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i){
        v1.push_back(i);
        if (v1.capacity() == v1.size()){
            std_vector++;
        } 
    }
    auto end = std::chrono::steady_clock::now();

    auto start_2 = std::chrono::steady_clock::now();
    int Vector_2 = 0;
    Vector<int> v2;
    for (int i = 1; i <= sz; ++i){
        v2.push_back(i);
         if (v2.capacity() == v2.size()){
            Vector_2++;
        }
    }
    auto end_2 = std::chrono::steady_clock::now();

    // Laukiam, kol procesorius laiko
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::chrono::duration<double> elapsed_seconds_2 = end_2 - start_2;

    cout << "std::vector: " << elapsed_seconds.count() << "s\n";
    cout << "std::vector atmintis perskirstyta: " << std_vector << " kartus" << endl;
    cout << "Vector: " << elapsed_seconds_2.count() << "s\n";
    cout << "Vector atmintis perskirstyta: " << Vector_2 << " kartus" << endl;
```

#### Rezultatai:
```
std::vector atmintis perskirstyta: 27 kartus
Vector atmintis perskirstyta: 26 kartus
```
# Programos veikimas, naudojant std::vector ir Vector realizacijas (naudojant duomenų failą su 100 000, 1 000 000         ir 10 000 000 studentų įrašų)

#### 100 000 

|  _Vector_                            |   Laikas   |   
|:------------------------------------:|:----------:|
| Duomenu nuskaitymas iš failo:        |   0.236s   | 
| Studentų rūšiavimas didėjimo tvarka: |   0.34s    | 
| Studentų suskirstymas i dvi grupes:  |   0.053s   |
| Iš viso:                             |   0.629s   |

|   _std::vector_                      |   Laikas   |   
|:------------------------------------:|:----------:|
| Duomenu nuskaitymas iš failo:        |   0.245s   | 
| Studentų rūšiavimas didėjimo tvarka: |   0.335s   | 
| Studentų suskirstymas i dvi grupes:  |   0.05s    |
| Iš viso:                             |   0.63s    |

#### 1 000 000 

|  _Vector_                            |   Laikas   |   
|:------------------------------------:|:----------:|
| Duomenu nuskaitymas iš failo:        |   1.995s   | 
| Studentų rūšiavimas didėjimo tvarka: |   4.539s   | 
| Studentų suskirstymas i dvi grupes:  |   0.666s   |
| Iš viso:                             |   7.2s     |

|  _std::vector_                       |   Laikas   |   
|:------------------------------------:|:----------:|
| Duomenu nuskaitymas iš failo:        |   2.017s   | 
| Studentų rūšiavimas didėjimo tvarka: |   4.915s   | 
| Studentų suskirstymas i dvi grupes:  |   0.551s   |
| Iš viso:                             |   7.483s   |

#### 10 000 000 

|  _Vector_                            |   Laikas   |   
|:------------------------------------:|:----------:|
| Duomenu nuskaitymas iš failo:        |   20.986s  | 
| Studentų rūšiavimas didėjimo tvarka: |   54.59s   | 
| Studentų suskirstymas i dvi grupes:  |    5.627s  |
| Iš viso:                             |   81.203s  |

|  _std::vector_                       |   Laikas   |   
|:------------------------------------:|:----------:|
| Duomenu nuskaitymas iš failo:        |   24.705s  | 
| Studentų rūšiavimas didėjimo tvarka: |   69.182s  | 
| Studentų suskirstymas i dvi grupes:  |    5.872s  |
| Iš viso:                             |   99.759s  |

#### Rezultatai:

Palyginant bendrą laiką, galima matyti, kad naudojant Vector užtrunkame mažiau laiko nei naudojant std::vector.

# Testavimas:

Naujos klasės tikrinimui naudojau catch testus.

#### Rezultatai:

```
===============================================================================
All tests passed (38 assertions in 1 test case)
```

# Doxygen dokumentacija:

Dokumentacija buvo sukurta kaip ir v1.5 versijoje.

Taip pat su Overleaf sukurtas PDF failas:

<img src="https://github.com/Jovitel/3_OP/assets/150922295/155a20ae-24ab-4bd1-81fb-dd826585f753" width="700" />

#### Eiga:

1. Susikūriau Overleaf accountą.
2. New project
3. Upload file
4. Įkėliau Latex ZIP failą
5. Parsisiunčiau PDF failą.
   



