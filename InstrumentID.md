# identification de l'instrument

On va chercher a utiliser un message SysEx de Requête d'Identification pour informer le controleur du type d'instrument connecté et ses carracteristiques.  

Il y a beaucoup de données qui peuvnet etre recupérées :
- le type d'instrument
- le delais pour action
- la premiere note midi jouable 
- le nombre de note jouable
- le type d'octave (chromatique ou diatonique)
- le nombre de noteOn max jouable en meme temps 
  

## Reponse de ID Request SysEx type
``` 
F0 7E <Device ID> 06 02 <Manufacturer ID> <Family Code> <Family Number> <Software Revision> F7
```
- F0 : Début d'un message SysEx.
- 7E : Universel non réel-temps.
- <Device ID> : Identifiant de l'appareil (retourne l'ID).
- 06 : Sous-ID #1 (indique "Device Inquiry").
- 02 : Sous-ID #2 (indique "Reply").
- <Manufacturer ID> : Identifiant du fabricant (7D pour les projet open source).
- <Family Code> : Code de la famille de produits (deux octets).
- <Family Number> : Numéro de modèle ou série (deux octets).
- <Software Revision> : Version du firmware ou du logiciel (quatre octets).
- F7 : Fin du message SysEx.

On va garder la meme strucure pour permettre de fonctionner avec des instruments du marché et dans le cas ou un instrument pour l'orchestrion est détécté, on viendra lire les données qui serront mmise en forme d'une autre facon pour la transmission des parametre de l'instrument.

on utilisera l'octets de <Device ID> avec les codes general midi 1 pour les Program Change Instrument Mapping pour identifier l'instrument

## Association instrument / Device ID 


| Famille        | Instrument              | Numéro ID|
|----------------|-------------------------|---------------------|
| Piano          | Acoustic Grand Piano     | 1                   |
| Piano          | Bright Acoustic Piano    | 2                   |
| Piano          | Honky-tonk Piano         | 4                   |
| Piano          | Harpsichord              | 7                   |
| Piano          | Clavinet                 | 8                   |
| Chromatic Percussion | Celesta            | 9                   |
| Chromatic Percussion | Glockenspiel       | 10                  |
| Chromatic Percussion | Music Box          | 11                  |
| Chromatic Percussion | Vibraphone         | 12                  |
| Chromatic Percussion | Marimba            | 13                  |
| Chromatic Percussion | Xylophone          | 14                  |
| Chromatic Percussion | Tubular Bells      | 15                  |
| Chromatic Percussion | Dulcimer           | 16                  |
| Organ          | Reed Organ               | 21                  |
| Organ          | Accordion                | 22                  |
| Organ          | Harmonica                | 23                  |
| Guitar         | Acoustic Guitar (nylon)  | 25                  |
| Guitar         | Acoustic Guitar (steel)  | 26                  |
| Guitar         | Electric Guitar (jazz)   | 27                  |
| Bass           | Acoustic Bass            | 33                  |
| Bass           | Electric Bass            | 34                  |
| Bass           | Fretless Bass            | 36                  |
| Strings        | Violin                   | 41                  |
| Strings        | Viola                   | 42                  |
| Strings        | Cello                   | 43                  |
| Strings        | Contrabass              | 44                  |
| Strings        |  Harp                   | 47                  |
| Brass          | Trumpet                 | 57                  |
| Brass          | Trombone                | 58                  |
| Brass          | Tuba                    | 59                  |
| Brass          | Trumpet                 | 60                  |
| Brass          | French Horn             | 61                  |
| Reed           | Soprano Sax             | 65                  |
| Reed           | Alto Sax                | 66                  |
| Reed           | Tenor Sax               | 67                  |
| Reed           | Baritone Sax            | 68                  |
| Reed           | English Horn            | 70                  |
| Reed           | Bassoon                 | 71                  |
| Reed           | Clarinet                | 72                  |
| Pipe           | Piccolo                 | 73                  |
| Pipe           | Flute                   | 74                  |
| Pipe           | Recorder                | 75                  |
| Pipe           | Pan Flute               | 76                  |
| Pipe           | Ocarina                 | 80                  |
| Ethnic         | Banjo                    | 106                 |
| Ethnic         | Kalimba                  | 109                 |
| Ethnic         | Bagpipe                  | 110                 |
| Percussive     | Tinkle Bell              | 113                 |
| Percussive     | Steel Drums              | 115                 |
| Percussive     | Woodblock                | 116                 |
| Percussive     | Melodic Tom              | 118                 |
