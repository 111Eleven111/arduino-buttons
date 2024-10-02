# Reaksjonsspill for To Spillere

Dette er et reaksjonsspill som bruker tre LED-lys og tre knapper for to spillere, samt en reset-knapp. Spillet starter ved å trykke på reset-knappen og avsluttes når en spiller oppnår et gitt antall poeng. Formålet med spillet er å være den første til å trykke på en knapp når et grønt lys tennes.

## Spilleregler

- To spillere konkurrerer om å være først til å trykke på knappen når grønt lys er aktivt. 
- Reset-knappen starter spillet og kan også avslutte spillet tidligere.
- Spillet er over når en spiller oppnår et bestemt antall poeng.
- Hvis en spiller trykker på knappen når lyset ikke er grønt, mister spilleren et poeng.
- Status og poeng vises i et serie-vindu. En vinner blir kåret når en spiller oppnår maksimal poengsum.

## Komponenter

- **3 push-knapper**: To knapper for spillerinput, hvor spilleren kan tjene eller miste poeng, og én knapp for å resette spillet.
- **3 LED-lys**: Hvert lys tilsvarer en knapp. Grønt lys signaliserer at spilleren kan tjene poeng. Hvis knappen trykkes når lyset er av, mister spilleren poeng.
- **Arduino**: Kontrolleren som styrer spillet og håndterer logikken.
- **Breadboard**: Brukt til å koble sammen komponentene i kretsen.
- **Laptop**: Brukt for å vise spillstatus og poeng via seriell terminal (kan erstattes av en LCD-skjerm i fremtidige versjoner).
- **Piezo-høyttaler**: Gir lyd til spilleren som feedback under spillet. To toner brukes – en høy tone når spilleren vinner poeng og en lavere tone når spilleren mister poeng.

## Funksjonalitet

1. Spillet starter når reset-knappen trykkes.
2. Grønne lys tennes tilfeldig, og spillerne må reagere raskt for å tjene poeng.
3. Spillerne kan miste poeng ved å trykke på knappen når lyset er av.
4. Reset-knappen kan brukes til å avbryte spillet før en vinner er kåret.
5. Poengstatus vises kontinuerlig i et serie-vindu underveis i spillet.
6. Piezo-høyttaleren gir en høy tone når en spiller tjener poeng, og en lav tone når de mister poeng.

## Installasjon

1. Koble Arduino til en laptop via USB.
2. Bruk et breadboard til å koble sammen knappene, lysene og piezo-høyttaleren i henhold til kretsoppsettet.
3. Last opp koden til Arduino via Arduino IDE.
4. Start spillet ved å trykke på reset-knappen, og observer poengstillingen i serie-vinduet.

## Fremtidige forbedringer

- Bruk av en LCD-skjerm for å vise poengstatus i stedet for serie-vinduet.
- Skjuling av fysiske komponenter for et mer kompakt og profesjonelt utseende.