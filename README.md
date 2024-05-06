# V1.1 release

1-osios užduoties pagrindu sukurti 2-ąją repoziciją. 

--- 1 testas ---

Palyginti STRUCT ir CLASS realizacijos spartą, naudojant konteinerį std::vector, 1 strategiją ir failus 100 000.txt, 1 000 000.txt

-- Rezultatas --

STRUCT greičiau.

--- 2 testas ---

Atliekame ekspermentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'sus: o1, o2, o3.

-- Rezultatas --

Galima teigti, jog, nauodajant STRUCT su didesniais failais efektyviau naudoti O2, o su mažensiais O1. 
Tačiau, naudojant CLASS su įvairaus didumo failais efektyviausia naudoti O3.

# V1.2 release

Praplėsti v1.1 versiją ir realizuoti "Rule of five".

"Rule of five" sudaro:

1. Kopijavimo konstruktorius
2. Kopijavimo priskyrimo operatorius
3. Perkėlimo konstruktorius
4. Perkėlimo priskyrimo operatorius
5. Įvesties/Išvesties operatoriai, turimai Studentas klasei

Įvestis/išvestis

<img src="https://github.com/Jovitel/2_OP/assets/150922295/7fa861cc-0689-4829-9f3e-0f759b1e4e7a" width="700" />

-- Rezultatas --

Parašyti testai suveikė. 

# V1.5 release

Vietoje klasės Studentai reikia sukurti dvi: bazinę (abstrakti) klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Studentas.

Abstrakčioji klasė - tai negalima sukurti žmogaus tipo objektų, o tik objektus gautus iš išvestinių klasių (pvz: Studentas)

-- Rezultatas --

Parašyti testai veikia ir su pakeista, abstrakčia klase.

# V2.0 release

// DOKUMENTACIJA, NAUDOJANT DOXYGEN //

1. Instaliavau Doxygen https://www.doxygen.nl/download.html
2. Pakeitimai Wizard skiltyje:

<img src="https://github.com/Jovitel/2_OP/assets/150922295/36df219b-34a7-4aa2-8877-c429ba408be5" width="600" />

<img src="https://github.com/Jovitel/2_OP/assets/150922295/e199690d-aebd-4c17-93fe-cbf118b59c2c" width="600" />

3. Pakeitimai Expert skiltyje:

<img src="https://github.com/Jovitel/2_OP/assets/150922295/6e6798ff-2b33-4ea0-8dca-9bb13d9ee89b" width="600" />

4. Run Doxygen

<img src="https://github.com/Jovitel/2_OP/assets/150922295/a7985430-97ab-48ef-92bc-e77ad44863b7" width="600" />


5. Show HTML output

<img src="https://github.com/Jovitel/2_OP/assets/150922295/54dd6c76-b01e-4fb0-9617-f0f94cc46db4" width="400" />

6. HTML ir LATEX

<img src="https://github.com/Jovitel/2_OP/assets/150922295/0e7af6fd-b5e7-45cb-9821-5a4de5e8f930" width="400" />


// UNIT TESTS //

Realizavau UNIT Testus naudodama Catch frameworką. 

1. Parsisiunčiau šiuos failus:

<img src="https://github.com/Jovitel/2_OP/assets/150922295/c95defc6-3fd9-48b8-9fd7-e9e64df3df0c" width="400" />

2. Susikūriau aplankalą "Catch2" į kurį įdėjau parsisiųstus failus. "Catch2" įdėjau į aplankalą "Testai" kartu su .cpp ir .h failais.

<img src="https://github.com/Jovitel/2_OP/assets/150922295/76fbafb1-90e3-4ab0-ba79-bfefc566dc05" width="400" />

3. Susikūriau Main.cpp ir jame parašiau testus:

<img src="https://github.com/Jovitel/2_OP/assets/150922295/ec88cfe0-20e6-4a13-971d-7c1b91248401" width="550" />

<img src="https://github.com/Jovitel/2_OP/assets/150922295/dd961a76-c118-4f45-83e1-048bb5c9ab89" width="550" />

--- Rezultatas ---




