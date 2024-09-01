# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1
bestel alle componenten uit de bill of materials

### stap 2
zorg dat je voldoende werkgereedschap bij hebt:
- soldeerbout
- tin
- schroevendraaier (+ en -)
- enventueel soldeerzuigpompje
- striptang

### stap 3
soldeer de bijgeleverde pinnen aan de lijnsensor met je rolletje tin.\
let op: wanneer verkeerd gesoldeerd, gebruik de soldeerzuigpomp.

### stap 4
soldeer het robot board pakketje:
1. zorg dat alle groene klemmen met hun ingang naar de buitenkant zitten
2. soldeer alle pinnen op dezelfde manier als in stap 3
3. soldeer de vrouwelijke ingangen ook als in stap 3
4. soldeer de buzzer, startknop en dipswitches (let op polarisatie)
5. soldeer de L293 mount in het midden (let op waar het halve maantje zich bevindt)
6. soldeer de grote switch

### stap 5
soldeer 2 jumperwires (liefst duidelijk verschillende stroom gerelateerde kleuren) aan elke motor

### stap 6
monteer de wielen samen de wheelmounts op de plastic basisplaat.\
hiervoor heb je 4 bouten en 4 moeren nodig.\
Monteer ze op de buitenste gaatjes.

### stap 7
monteer de plastic evenwichtswieltjes vooraan op de basisplaat.\
Deze kan je er gewoon indrukken

### stap 8
Nu is de wagen gebalanceerd. Monteer de lijn sensor samen met 2 bouten en moeren vooraan op de linefollower.\
De gaan in de binnenste gaatjes van de basisplaat.

### stap 9 
draai de goudkleurige staafjes in de basisplaat en bevestig deze met 4 moeren.

### stap 10
strip de draden van de batterijhouder ongeveer een halve centimeter af.\
Bevestig de batterijhouder in het midden van de basisplaat met de draden naar achter gericht. (van de wagen)\
Dit met 2 bouten, 2 moeren en 2 rondellen.\
LET OP: steek de batterijen nog niet in de houder!

### stap 11
Deze stap is eerder belangrijk.\
Voordat we de robot board op de staafjes bevestigen, zorgen we eerst dat de jumper wires van de motor goed liggen tov de staafjes.\
Ook de draden van de batterij moeten juist liggen.\
Zo zorgen we ervoor dat de draden mooi uitkomen op de robot board.\
Ga dus na waar draden in de board gaan. Dit zou normaal, wanneer de lijnsensor rechts is en de wielen links, bovenaan op het bord moeten zijn.\
Je zou de letters op het bord ook moeten kunnen lezen.

### stap 12
bevestig nu de robot board op de staafjes met 4 bouten.

### stap 13
we connecteren nu alle draden op de robot board\
steek de draden van de linkse motor in de klemmen waar staat 'sol motor' (linkse motor)\
steek de draden van de rechtse motor in de klemmen waar staat 'sag motor' (rechtse motor)\
+/- maakt niet uit, dit beïnvloed alleen de draairichting van de motor en deze kunnen we nog omdraaien indien gewenst.\
conencteer de + van de batterijhouder (rood) met de + op het robot board, doe hetzelfde voor -.\
alle draden zouden nu geconnecteerd moeten zijn.

### stap 14
connecteer 6 draden met de sensor (female), deze schuiven er gewoon over.\
ZORG ERVOOR DAT DIT VERSCHILLENDE KLEUREN ZIJN!\
schuif de andere kant van de 6 draden onder het robot board door. (en over de batterijhouder)\
Let nu zeer goed op waar je deze plaatst\
Alle draden moeten sowieso achteraan het robot board komen. (tenzij je met een sensor met 6 sensor werkt dan gaan 2 analoge ingangen vooraan op het bord.)\
Stop de Vin (+) in een + spot op het board. Het maakt niet uit welke.\
Stop de GND (-) in een - spot op het board. Het maakt niet uit welke.\
Kijk op de sensor waar de 1, 2, 3, 4 staat en steek deze in A0, A1, A2, A2. (A3 en A4 wanneer je 6 sensoren gebruikt deze zitten vooraan op het bord)\
*D8 en D12 zijn geen analoge ingangen voor de mensen die meerdere sensoren gebruiken!\

configuratie:\
\
1 --> A0\
2 --> A1\
3 --> A2\
4 --> A3

### stap 15
plaats de L293 motordriver op de robot board\
LET OP WAAR DE INKEPING ZIT, dit zou overeen moeten komen met die van de L293 houder

### stap 16
Plaats de arduino op de robot board.\
LET OP: de USB poort moet naar de grote switch gericht zitten anders gaat je linefollower NIET werken.

### stap 17
proficiat je fysieke linefollower is gemaakt.\
Upload de arduino code met je laptop en bijgeleverde usb kabel naar de Arduino Nano

### stap 18
plaats de batterijen in de houder nadat je de linefollower losmaakt van de computer\
(zorg dat ze opgeladen zijn XD)

### stap 19

Zet de grote switch aan wanneer je de linefollower op een parcour zet.\
Deze zal nu zijn omgeving kalibreren.

### stap 20
druk op de startknop (D7), na enkele aftelbiepjes zal je linefollower het parcour gaan volgen.\
Om je linefollower te tunen, kan je de Kd, Kp en de waar foutcorrectie waarde (standaard op 1500 ingesteld) aanpassen.\
VEEL PLEZIER!
