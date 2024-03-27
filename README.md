//ANTRA UŽDUOTIS//
1-osios užduoties pagrindu susikūriau 2-ąją repoziciją. Terminale naudojau šias komandas:
1. git clone --mirror https://github.com/Jovitel/1_OP.git
2. git clone --bare https://github.com/Jovitel/1_OP.git 2_OP
3. cd 2_OP
4. git branch -a
5. remote set-url origin https://github.com/Jovitel/2_OP.git
6. git push --mirror

//1 TESTAS://
Lyginame struct ir class realizacijos spartą, naudojant konteinerį std::vector, 1 strategiją ir failus 100 000.txt ir 1 000 000.txt

----STRUCT:----

100 000.txt

![Ekrano kopija (273)](https://github.com/Jovitel/2_OP/assets/150922295/4899aefe-3bc0-4120-87bc-aafac44eba74)

1 000 000.txt

![Ekrano kopija (303)](https://github.com/Jovitel/2_OP/assets/150922295/c1c55559-50f2-49bb-b4c2-e37076605b2d)

----CLASS:-----

100 000.txt

![Ekrano kopija (287)](https://github.com/Jovitel/2_OP/assets/150922295/254e4015-bd74-4d84-8a7c-6e9924eaac39)

1 000 000.txt

![Ekrano kopija (288)](https://github.com/Jovitel/2_OP/assets/150922295/2186ed06-3261-4783-b564-1485e971af7d)

/-/-/-/APIBENDRINIMAS/-/-/-/

![Ekrano kopija (306)](https://github.com/Jovitel/2_OP/assets/150922295/9ac4cd6e-30f0-456f-9335-f6da05b3f981)

Mano atveju, su STRUCT kodas veikia greičiau.

//2 TESTAS://
Atliekame ekspermentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'sus: o1, o2, o3.

----STRUCT:----

O1 
100 000.txt

![Ekrano kopija (290)](https://github.com/Jovitel/2_OP/assets/150922295/c0cb1ac5-b086-4c8a-a231-3ec1b8849ead)

1 000 000.txt

![Ekrano kopija (292)](https://github.com/Jovitel/2_OP/assets/150922295/4aba7635-7904-4ef7-8acc-8a2eeed0a256)

O2
100 000.txt

![Ekrano kopija (308)](https://github.com/Jovitel/2_OP/assets/150922295/82fed380-07b2-45a6-a2a6-568574dabb1c)

1 000 000.txT

![Ekrano kopija (294)](https://github.com/Jovitel/2_OP/assets/150922295/4d07abf0-c2b1-4b80-964a-a002f8c77975)

O3
100 000.txt

![Ekrano kopija (295)](https://github.com/Jovitel/2_OP/assets/150922295/02a43665-0aaf-4f9d-b907-1e7ccd6464fd)

1 000 000.txt

![Ekrano kopija (296)](https://github.com/Jovitel/2_OP/assets/150922295/a487ede8-182d-4291-9495-0629e67695d2)


-----CLASS:-----

O1
100 000.txt

![Ekrano kopija (297)](https://github.com/Jovitel/2_OP/assets/150922295/7bb1fb5b-f075-418b-b7f5-421ed515c6d9)

1 000 000.txt

![Ekrano kopija (298)](https://github.com/Jovitel/2_OP/assets/150922295/df05010b-bb05-4e82-aee7-d5a5d2a82928)

02
100 000.txt

![Ekrano kopija (299)](https://github.com/Jovitel/2_OP/assets/150922295/2db37259-bfa3-4d86-9ecf-7e3981ad1817)

1 000 000.txt

![Ekrano kopija (300)](https://github.com/Jovitel/2_OP/assets/150922295/8e6346c6-3fe6-48df-bae6-22aef99b19dc)

03
100 000.txt

![Ekrano kopija (301)](https://github.com/Jovitel/2_OP/assets/150922295/6edb9d00-4cfd-4c96-98d0-396c7f0f1373)

1 000 000.txt

![Ekrano kopija (302)](https://github.com/Jovitel/2_OP/assets/150922295/2b7b5139-ccf5-409f-a350-4c904fe4e6a2)

/-/-/-/APIBENDRINIMAS/-/-/-/

![Ekrano kopija (309)](https://github.com/Jovitel/2_OP/assets/150922295/71047d31-d284-43e4-a1ff-c24d38cc56eb)

Naudojant STRUCT:

100 000.txt failu:

Greičiausiai atliekama programa naudojant kompiliatoriais flag'są O1
Lėčiausiai atliekama programa naudojant kompiliatoriais flag'są O2

1 000 000.txt failu:

Greičiausiai atliekama programa naudojant kompiliatoriais flag'są O2
Lėčiausiai atliekama programa naudojant kompiliatoriais flag'są O1

Naudojant CLASS:

100 000.txt failu:

Greičiausiai atliekama programa naudojant kompiliatoriais flag'są O3
Lėčiausiai atliekama programa naudojant kompiliatoriais flag'są O1

1 000 000.txt failu:

Greičiausiai atliekama programa naudojant kompiliatoriais flag'są O3
Lėčiausiai atliekama programa naudojant kompiliatoriais flag'są O1

Galima teigti, jog, nauodajant STRUCT su didesniais failais efektyviau naudoti O2, o su mažensiais O1.

Tačiau, naudojant CLASS su įvairaus didumo failais efektyviausia naudoti O3.

![Ekrano kopija (307)](https://github.com/Jovitel/2_OP/assets/150922295/58efd865-4c2d-48f1-8236-5a8ca2c2f1de)

