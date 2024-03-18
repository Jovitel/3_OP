// 1 DALIS //
APRAŠYMAS:

Su šia programa yra testuojama programos sparta, naudojant skirtingus konteinerius (std::vector, std::list, std::deque). Matuojama: duomenų nuskaitymas iš failo į atitinkamą konteinerį
           studentų rūšiavimas didėjimo tvarką konteineryje 
           studentų skirstymas  į dvi grupes/kategorijas

REZULTATAI:
1000

![Ekrano kopija (259)](https://github.com/Jovitel/1_OP/assets/150922295/71b0cf1b-6f50-455c-8e46-5f77e61cb27e)
![Ekrano kopija (260)](https://github.com/Jovitel/1_OP/assets/150922295/de6211c5-07f8-45a3-b8bb-00fa73229921)

10 000

![2](https://github.com/Jovitel/1_OP/assets/150922295/8063d316-d155-4f96-a994-d53d7ae6598c)
![Ekrano kopija (262)](https://github.com/Jovitel/1_OP/assets/150922295/c009ca89-ebd6-49dc-b793-c9f996318d9c)

100 000

![3](https://github.com/Jovitel/1_OP/assets/150922295/b6cc98b3-f84a-4565-b423-bb2a5736c64e)
![Ekrano kopija (263)](https://github.com/Jovitel/1_OP/assets/150922295/967158a3-ec7b-4989-a5d6-f381bcd7cb0c)

1 000 000

![4](https://github.com/Jovitel/1_OP/assets/150922295/205ad437-b3af-4466-ae01-a928e6fb32ed)
![Ekrano kopija (264)](https://github.com/Jovitel/1_OP/assets/150922295/15f7930b-1a0e-431a-8eec-c8c1f23e4476)

10 000 000

![Ekrano kopija (267)](https://github.com/Jovitel/1_OP/assets/150922295/00973ea7-2fa1-4722-ab7b-27b954534155)
![Ekrano kopija (266)](https://github.com/Jovitel/1_OP/assets/150922295/fd805374-62c2-4056-ba58-b5f3aa4edf45)

APIBENDRINIMAS:
![Ekrano kopija (268)](https://github.com/Jovitel/1_OP/assets/150922295/34a7260e-d159-4226-856b-f129c2d4b986)

Atlikti visus šiuos veiksmus greičiausiai pavyko naudojant std::list, o daugiausia buvo sugaišta laiko su std::deque konteineriu. Nuskaitymas trumpiausiai užtruko su std::deque, rūšiavimas žymiai trumpiau su std::list, o mokinių suskirstymas - std::vector. 
// 2 DALIS //
APRAŠYMAS:

Optimizuojama studentų rūšiavimo į 2 kategorijas ("Vargšiukai"; "Kietiakai") realizacija. Visiems trims konteinerių tipams (vector, list ir deque) išmatuojame programos veikimo spartą priklausomai nuo studentų dalijimo strategijos.

REZULTATAI:
1 strategija
Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". 
![Ekrano kopija (271)](https://github.com/Jovitel/1_OP/assets/150922295/648c122f-e652-4bb9-832f-b50277ad12e7)
![Ekrano kopija (272)](https://github.com/Jovitel/1_OP/assets/150922295/4fe8f38d-f3ad-49dd-8985-619ae0616ff1)
![Ekrano kopija (273)](https://github.com/Jovitel/1_OP/assets/150922295/73193f69-b8bc-4133-88ec-b11c7c8eaea7)
![Ekrano kopija (275)](https://github.com/Jovitel/1_OP/assets/150922295/e725a02c-98a9-4464-9e6c-1c33aa57b54a)
![Ekrano kopija (274)](https://github.com/Jovitel/1_OP/assets/150922295/12919eed-1e4b-4789-9a08-433e9cdca396)

2 strategija
Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".
![Ekrano kopija (276)](https://github.com/Jovitel/1_OP/assets/150922295/06b383ba-973f-43e9-92f5-a9f197103acd)
![Ekrano kopija (277)](https://github.com/Jovitel/1_OP/assets/150922295/12c591be-7dad-4e2d-ac70-9105a7a648f0)
![Ekrano kopija (278)](https://github.com/Jovitel/1_OP/assets/150922295/4fbe09f8-02bb-4ee2-8d19-68ea1999fad8)
![Ekrano kopija (279)](https://github.com/Jovitel/1_OP/assets/150922295/f0735bb9-ce9e-4721-bb20-b5d49fba2026)
![Ekrano kopija (280)](https://github.com/Jovitel/1_OP/assets/150922295/2a32d8f0-1c7f-4346-8ba2-c523ce3ba99a)

3 strategija
Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant greičiausiai veikianti 1 arba 2 strategiją  įtraukiant į ją "efektyvius" darbo su konteineriais metodus (std::copy, std::remove, std::remove_if, std::partition)
![Ekrano kopija (281)](https://github.com/Jovitel/1_OP/assets/150922295/edd5bde6-da50-4c8d-abaf-ab7eaa2545c5)
![Ekrano kopija (282)](https://github.com/Jovitel/1_OP/assets/150922295/da3ba13a-088b-4bc1-8b86-38358282fa7f)
![Ekrano kopija (283)](https://github.com/Jovitel/1_OP/assets/150922295/9501aaf6-14fc-4d96-8a67-2b86f617873a)
![Ekrano kopija (284)](https://github.com/Jovitel/1_OP/assets/150922295/7b890b9c-862d-4f31-bd31-2f520a35bc34)

APIBENDRINIMAS:




