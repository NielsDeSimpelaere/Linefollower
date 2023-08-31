# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1
bestel alle componenten uit de bill of materials  
### stap 2
Neem de 2 printplaten met afmeting van 50x100mm en leg deze voor je uit. De ene printplaat gebruiken we volledig, de andere gebruiken we voor de montage van de motoren en de sensor. Neem een printplaat en gebruik een schijfzaag om een rechthoek van 25x70 mm en één rechthoek van 20x100 mm te bekomen. 
### stap 3
Zet nu de arduino nano op twee centimeter van de korte zijde met de poort naar rechts als we de korte zijde als bovenkant van onze linefollower zullen beschouwen. Solder nu de arduino nano vast op de printplaat. Meet telkens bij het solderen met de multimeter na of de verbindingen correct zijn en of er geen connecties zijn naburige pinnen die we niet willen.
### stap 4
Soldeer een blauwe led nu rectboven op de printplaat, vlak naast D13. Soldeer de positieve kant van de LED op pin D13. Aan de negatieve pin van de led soldeer je op de onderkant van de printplaat hieraan een weerstand van 220 Ohm. Verbind deze weerstand met ground.
### stap 5
Soldeer een rode led aan de andere kant van de microcontroller tegenover de blauwe led vlak naast D12. Soldeer de positieve kant van de LED op pin D12. Aan de negatieve pin van de led soldeer je op de onderkant van de printplaat hieraan een weerstand van 220 Ohm. Verbind deze weerstand met ground.
### stap 6
Neem de eerder op maat gezaagde printplaat van 25x70 mm. Deze gebruiken we voor de montage van de motoren. Het is de bedoeling dat de motoren op 1 lijn liggen en dat hun assen weg van de printplaat is gericht. Neem de motorbevestiging en steek de motor hier in. Het is de bedoeling dat de motoren op de plaat zitten, waarbij de boord van de motorbevestiging gelijk komt met de boord van de printplaa. Zorg ervoor dat de motorbevestiging mooi symmetrisch ligt en teken dan de te boren gaten af. Voor elke motorbevestiging moeten er twee gaten geboord worden.
### stap 7
Boor deze gaten met een boorkop met diameter 3. Eens de gaten geboord zijn, bevestig dan de motoren met de motorhouder op de plaat en maak deze vast met de meegeleverde bout en de moer.
### stap 8
Neem nu het plaatje waarop de motoren gemonteerd zijn en leg deze onder de achterkant van de linefollower (zoals eerder vermeld dus de kant het meest ver weg van de eerder gesoldeerde microcontroller). Zorg nu dat de plaat met de motoren tegen de volledige printplaat wordt geplaatst en dat de achterkant gelijkkomt. We zien dus dat de achterkant van de auto twee platen zijn die niet voorbij elkaar uitsteken in verticale richting.
### stap 9
Om deze te monteren, moeten er twee boorgaten met diameter 4 worden geboord. Dit wordt idealiter gedaan zo ver mogelijk van de achterkant van de linefollower omdat we nog plaats nodig hebben voor de batterijhouder. Teken twee gaten af zodat we de twee platen aan elkaar kunnen bevestigen.
### stap 10
Boor de twee gaten met een boord met diameter 4. Eens de gaten zijn geboord,bevestig dan de twee platen aan elkaar.
### stap 11
Neem nu de batterijhouder die we hierop zullen monteren. Zet al eens de batterijhouder zoals op de foto om een zicht te hebben hoe deze wordt geïnstalleerd. Zoals deze nu georiënteerd is, spreken we af dat de kant die contact heeft met de printplaat, de onderkant is. Het vlak dat gericht is naar de voorkant van de auto, is de achterkant.
### stap 12
Teken een gat af op de onderkant van de batterijhouder, in het midden van de langste zijde en zo dicht mogelijk richting de achterkant.
### stap 13
Boor nu een gat met een boor met diameter 4 door de onderkant van de batterijhouder. Boor nu ook een gat met dezelfde diameter in het midden van de onderste printplaat, door de printplaat erboven.
### stap 14
Bevestig nu met de bout maat M4 bovenaan door de batterijhouder en onderaan met de moer M4.
### stap 15
Dan kunnen we nu de ground kabel van de batterijhouder  met de ground van de arduino nano microcontroller verbinden door middel van solderren. Verbind de rode voedingskabel van de batterijhouder met de schakelaar waarmee we de voeding voor de volledige linefollower aan of af kunnen zetten. Verbind de de schakelaar dan met de 'V in' van de microcontroller. Bevestig de schakelaar op de batterijhouder.
### stap 16
Neem nu de DRV en bevestig deze op het bord zoals op de foto. Soldeer deze vast. Verbind de pinnen zoals te zien is op de technische tekening.
### stap 17
Neem nu de HC05 en bevestig deze op het bord zoals op de foto. Soldeer deze vast. Verbind de pinnen zoals te zien is op de technische tekening. Soldeer ook zeker de schakelaar tussen de voeding en het HC-05 bord zodat we later de HC05 kunnen uitzetten om zo ongestoord programma's van de pc naar de nano microcontroller kunnen uploaden.
### stap 18
Neem nu de button en bevestig deze op het bord zoals op de foto. Deze bevindt zich vlak links onder de microcontroller. Soldeer deze vast. Verbind de pinnen zoals te zien is op de technische tekening.
### stap 19
Neem nu de QTR-8A en bevestig deze op het bord zoals op de foto. Soldeer deze vast. Verbind de pinnen zoals te zien is op de technische tekening.
### stap 20
Eens alles gesoldeerd is, kan je het finale programma uploaden via de Arduino IDE
### stap 21
Als alles goed is verlopen, werkt het programma goed op de linefollower.
### stap 22
Stel de parameters zoals in de handleiding vermeld om zo goed te kunnen rijden.
### stap 23
Experimenteer met de parameters en geniet van je linefollower


