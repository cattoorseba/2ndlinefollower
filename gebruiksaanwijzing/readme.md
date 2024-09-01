# Gebruiksaanwijzing

### opladen / vervangen batterijen
De batterijen worden opgeladen met een bijgeleverde oplader. Het is de Liitokala Lii-L2. Je stopt deze in je laptop met de batterijen erin en ze zullen opladen. Je kan ook een USB oplaadblokje connecteren met de oplader en deze dan zo in het stopcontact steken. Wanneer het lichtje groen is, zijn de batterijen volledig opgeladen.

### draadloze communicatie
#### verbinding maken
Geen draadloze communicatie...

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
De linefollower kalibreert zichzelf. Wanneer je de grote switch aanzet, zal de linefollower eerst wat heen en weer bewegen om zichzelf af te stellen op zijn omgeving. Wanneer dit gebeurd is en de linefollower staat stil, kan je op de startknop drukken (D7). De linefollower zal nu de lijn volgen totdat je de grote switch weer uitzet.

### settings
De robot rijdt stabiel met volgende parameters:
  
Kp: 0.17
Kd: 3
lijn 79: fout = (qtra.readLine(sensorValue, 1, achtergrond) -1500);
"de -1500 is een belangrijke foutcorrectie waarde"
### start/stop button
Zoals bij de kalibratie vermeld moet je eerst de grote switch aanzetten om de power te voorzien. Hierna zal de linefollower zich kalibreren. Wanneer dit gebeurd is kan je de startknop eenmalig indrukken. Deze bevindt zich op de PCB onder vakje D7. Rechtsonder wanneer je de PCB (en Arduin Nano) recht bekijkt.
