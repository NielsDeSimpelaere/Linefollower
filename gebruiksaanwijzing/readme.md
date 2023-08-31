# Gebruiksaanwijzing

### opladen / vervangen batterijen
Zorg er bij het insteken of het uithalen van de batterijen voor dat de blauwe schakelaar, op de batterijhouder gemonteerd,
uit staat (naar het linker wiel van achteren bekeken toe gericht is).

Om de batterijen op te laden, wordt gebruikt gemaakt van de Xtar MC1 Li-ion Mini Batterijlader. Deze kan 1 batterij opladen op hetzelfde moment
opladen. Zorg ervoor dat de batterij wordt opgeladen tot ongeveer een spanning van 3,5V. Om dit te weten, haal de batterij uit de oplader en meet
de spanning op met een multimeter. Wanneer beide batterijen elk op hun beurt opgeladen zijn tot 3,5V, dan kunnen ze weer in de batterijhouder geplaatst
worden. Zorg ervoor dat de gebruikte batterijen  van het type LG 18650 Li-ion Batterij - 3400mAh - 10A - INR18650 MJ1 zijn.

### draadloze communicatie
#### verbinding maken
Verbinden van de linefollower en de smartphone gebeurt via de app Serial Bluetooth Terminal. Leg bluetooth aan op je smartphone, en ga in de app naar devices. Zorg ervoor dat je verbonden bent met de HC-05. Ga daarna naar de terminal en verbind rechtsboven door ophet symbooltje van de 2 connecties te klikken. Daarna krijg je de melding dat de HC-05 verbonden ("connected") is.

#### commando's
debug [on/off]  
start  
stop  
set cycle [µs]  
set power [0..255]  
set diff [0..1]  
set kp [0..]  
set ki [0..]  
set kd [0..]  
calibrate black  
calibrate white  

### kalibratie
Omdat de omstandigheden waarin de linefollower rijdt niet altijd 100% hetzelfde kunnen zijn, moet er bij te sterk verscillende zwart en wit waarden gekalibreerd worden. Hiervoor voeren we eens een kalibratie op een zwarte ondergrond uit en een kalibratie op de witte ondergrond.

Kalibratie voor zwartwaarden:
Zet de linefollower met zijn sensoren op een zwarte ondergrond. Hierop kalibreren we de zwartwaarden. Typ

### settings
De robot rijdt stabiel met volgende parameters:  
kp: 1
diff: 0,10
ki: 0
kd: 0,012
PWR: 65

### start/stop button
uitleg locatie + werking start/stop button
De zwarte knop bevindt zich links op de linefollower dicht bij de Nano microcontroller.
Bij het aanschakelen van de voeding (blauwe schakelaar), zal de microcontroller opstarten. Eenmaal de rode led brandt, wil dit zeggen dat de linefollower volledig is opgestart en kan starten met rijden. Om de linefollower te laten starten met de lijn te volgen, druk je op de knop. Wanneer je de lijnvolger weer wilt stoppen, til je de lijnvolger op en druk je weer op deze knop. Doordat deze knop is verbonden met een interrupt, zal de microcontroller het lezen van de loop code onderbreken en meteen het 'run' op nul zetten, dus stoppen.
