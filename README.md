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

![Ekrano kopija (285)](https://github.com/Jovitel/1_OP/assets/150922295/23dfd549-0989-40d5-9ac6-a65ca3dfe9ba)


APIBENDRINIMAS:

![Ekrano kopija (286)](https://github.com/Jovitel/1_OP/assets/150922295/18402131-e465-42eb-93da-ae219c9dc4a1)

GREIČIAUSIAI ATLIKTA:

VECTOR NUSKAITYMAS - 1 strategija
VECTOR RŪŠIAVIMAS - 1 strategija
VECTOR SUSKIRSTYMAS - 3 strategija

LIST NUSKAITYMAS - 1 strategija
LIST RŪŠIAVIMAS - 1 strategija
LIST SUSKIRSTYMAS - 1 strategija

DEQUE NUSKAITYMAS - 1 strategija
DEQUE RŪŠIAVIMAS - 1 strategija
DEQUE SUSKIRSTYMAS - 1 strategija

Taigi galima teigti, jog šioje programoje laiko atžvilgiu naudingiausia naudoti 1 strategiją (bet svarbu paminėti, kad ši strategija nėra efektyvi užimamos atminties atžvilgiu), 
2-oji strategija garantuoja atminties efektyvumą, teoriškai mąstant turėjo sutaupyti laiko, palyginant rūšiavime ir nuskaityme tam tikrose vietose (iki 1000 000 failo) sugaištas laikas tikrai yra mažesnis, bet pasiekus 10 000 000 failą, efektyvumas ženkliai sumažėjo, todėl ir bendri rezultatai yra šiek tiek blogesni už 1-ąją strategiją,
o 3-oje strategijoje naudojami algoritmai leidžia supaprastinti kodą, nors mano atveju rezultatai yra panašūs į 2-osios strategijos rezultatus, galbūt, kad dalis algoritmų jau buvo naudojami 2-oje strategijoje.
Atsižvelgiant į konteinerius, iš 1-ojo testo išsiaiškinome, jog std::list nuskaityme ir suskirstyme yra pranašiausias, todėl yra pravartu pasirinkti jį.

PROGRAMOS NAUDOJIMOSI INSTRUKCIJA:
1. Prisijungiame prie Github paskyros, jei jos neturime, susikuriame ir susikonfiguruojam Github.
https://docs.github.com/en/get-started/getting-started-with-git/set-up-git
2. Tuomet, parsisiunčiam Visual Studio Code (galima naudoti ir kitą aplinką, bet instrukciją tęsiu su VS Code)
https://code.visualstudio.com/download
3. Parsisiunčiame paketus. Atsidarius VS Code kairėje, 5 mygtukas vertikaliai, jį paspaudus randame visus paketus. ("CMake"; "CMake Tools"; "C/C++ Themes"; "C/C++ Runner"; "C/C++ Extension Pack"; "C/C++")
4. Parsisiunčiam šį kodą, įsidedame į norimą folderį pvz:(C:\Darbai\1_OP) ir atidarome jį Visual Studio Code aplinkoje.
https://github.com/Jovitel/1_OP/tree/v1.0_1
5. Terminale (jeigu jo nėra, viršuje paspaudžiame ant 3 taškiukų ir paspaudžiame "New terminal") paspaudžiame kairėje prie "+" esančia rodyklę, rodančią į apačią. Pasirenkame "Command Prompt".
6. Naudojant cd pasiekiame vietą, kur yra kodas.
PVZ: cd  C:\Darbai\1_OP
7. Norint paleisti kodą, terminale, Command Prompt, įrašome "vektoriai"
8. Terminale pamatysit 6 pasirinkimus, jų pavadinimai nusako, kokie veiksmai bus atlikti, įvykdžius tam tikrą pasirinkimą.
   
Štai smulkesni pasirinkimų aprašymai:
1. Programos pradžia.
Įvedama:

Kelių mokinių pažymiai bus apskaičiuojami
Kiek bus įrašoma namų darbų pažymių
Taip pat įvedami egzamino rezultatai
Išvedama

Pavardė, vardas
Galutinis balas arba mediana (pasirenkama)
Neledžiama vartotojui įvesti nelogiškus atsakymus, tai padarius programa informuoja vartotoją
(PVZ ten, kur skirta įvesti pažymius nuo 1 iki 10 nebus leidžiama įvesti didesnių skaičių arba raidžių)
2. Galima pasirinkti, ar nori, kad pažymiai ir vardai būtų sugeneruojami atsitiktinai
(tai buvo įgyvendinta 2 atskiruose failuose, tik su vektoriais ir tik su masyvais)
Yra meniu skirtingos programos eigos pasirinkimui (1 - ranką, 2 - generuoti pažymius, 3 - generuoti ir pažymius ir studentų vardus, pavardės, 4 - baigti darbą).
3. Galima pasirinkti, ar nori, kad pažymiai ir vardai būtų sugeneruojami atsitiktinai
(tai buvo įgyvendinta 2 atskiruose failuose, tik su vektoriais ir tik su DINAMINIAIS masyvais)
Yra meniu skirtingos programos eigos pasirinkimui (1 - ranką, 2 - generuoti pažymius, 3 - generuoti ir pažymius ir studentų vardus, pavardės, 4 - baigti darbą).
4. Užbaigti programą.
5. Duomenys nuskaitomi iš failo, apskaičiuojama, per kiek laiko nuskaitoma.
6. Generuojami failai su mokiniais ir jų pažymiais iš anksto.
Reikia pasirinkti, kiek mokinių generuoti bei jų pažymių skaičių.
Mokiniai yra suskirstomi pagal galutinius vidurkius (<5 vargšiukai; >=5 kietiakai) ir padalinami į 2 atskirus failus.
Yra 3 strategijos bei 3 skirtingi konteineriai, std::vector; std::list; std::deque
