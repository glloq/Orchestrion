# Orchestrion - Projet de création d'un orchestre électronique

Le projet Orchestrion est une initiative ambitieuse visant à créer un orchestre électronique complet composé d'instruments acoustiques. L'objectif de ce projet est de jouer des musiques à partir de fichiers MIDI.

Ce dépôt GitHub regroupe les explications générales du projet

Chaque type d'instrument aura un lien vers son propre dépôt pour l'instrument contenant les plans, fichiers et tutoriels spécifiques à chaque instrument.

## Contrôle de l'orchestre électronique

Tous les instruments seront contrôlés électroniquement à l'aide de microcontrôleurs Arduino, de moteurs, d'électroaimants et de servomoteurs.

L'orchestre électronique sera construit à partir de matériaux tels que du bois, du métal ou l'impression 3D. Chaque instrument sera équipé d'électronique pour contrôler les mouvements des cordes, des membranes et des clapets nécessaires pour produire les sons.

Le contrôle de l'orchestre électronique sera effectué à partir d'un ordinateur ou d'un Raspberry Pi via une page web. L'utilisateur pourra sélectionner un fichier MIDI et assigner les différents canaux à chaque instrument. Pour la communication MIDI via USB, nous utiliserons la bibliothèque MidiUSB.h.


# Code instruments

## Code generique
Vu que je cherche a utiliser le meme type de materiel, il n'y aura que quelques codes generique a faire pour chaque type type d'actionneurs.
les codes suivants seront construit avec des objets en c++, ils dervais etre adaptable a beaucoup d'instruments ! (ca sera très probablement que pour moi XD) 

### simple action 

[Servo MIDI ](https://github.com/glloq/servo-midi-music)
- 1 a 88 servomoteurs avec des pca9685
- code adaptable grattage (+/- un angle alterné)ou action avec servomoteurs (deplacement avec noteOn, retour avec noteOff)
- Accordage diatonique ou chromatique 

Solenoid MIDI Simple => a venir
- Code adaptable pour l'activation de 1 a 88 solenoides avec des mcp23017
- avec decoupage pwm sur l'alimentation generale des solenoides (pour limiter la chauffe du ou des solenoides actifs)
- accordage chromatique 

Solenoid MIDI Velocity => c'est le code pour le piano !!
- Code adaptable pour l'activation de 1 a 88 solenoides
- avec decoupage pwm de chacun des solenoides pour adapter la puissance de frappe en fonction de l'intensité de la note midi recue.
- accordage chromatique 

Stepper Motor MIDI => a venir
- Code pour controler un moteur pas a pas et gerer le deplacement a certaines position definie en fonction de la note midi recue.


### instrument a corde gratté
- instrument à corde gratté de une a 6 cordes avec X frettes par corde => [general](https://github.com/glloq/OneStringGuitar)
  - [Actionné par solenoides](https://github.com/glloq/Orchestrion_Plucked_Strings_Solenoids/tree/main)
  - [Actionné par servomoteurs](https://github.com/glloq/Orchestrion_Plucked_Strings_Servomotors/tree/main)
  - Moteur pas à pas
    - Contact Continu
    - avec servomoteurs
    - avec solenoides
      
### instrument à corde frottée
- instrument à corde frottée de une a 6 cordes avec X frettes par corde  =>[general](https://github.com/glloq/OneStringCello)

### instrument a vent
- instrument a vent "basse pression" (avec un ventilateur radial ou autre pompe a air adapté) 

    
- instrument a vent "haute pression" => c'est la partie la plus compliqué pour moi (utiliser des compresseurs de frigo ?) 

  
## Exemples fini (presque) 
- Xylophone, glokenspiel, marimba, vibraphone = [Code adaptable de 17 a 32 notes avec gestion pwm + silencieux pour noteOff + volume/vibrato](https://github.com/glloq/Orchestrion-Xylophone)
- [lyre 16 cordes](https://github.com/glloq/16-cords-lyre-midi)
- [ukulele solenoides](https://github.com/glloq/Orchestrion_ukulele)
- [piano](https://github.com/glloq/Orchestrion_Piano)
- [percussion](https://github.com/glloq/MidiPercussion)
- [Trompette](https://github.com/glloq/Orchestrion_trumpet) 
- [flute a bec](https://github.com/glloq/servo-flute)
- [Harmonica](https://github.com/glloq/harmonica_Midi)

-------------------------------------------------------

# Partie Controleur host et interfaces 

l'objectif est d'avoir un systeme qui joue les fichiers midi le plus simplement possible sur les instruments connecté.  
idealement je souhaite faire fonctionner le systeme depuis un raspberry pi avec une interface tactile.
il faudrait utiliser un hub usb avec une alimentation isolé pour permettre de connecter plusieurs instruments 



il faut permettre plusieurs actions sur l'interface de controle :

- gestion des fichiers midi
  - uploader un fichier midi
  - selectionner un fichier midi
  - supprimer le fichier selectionné
  - creer un dossier
  - deplacer le fichier selectionné dans un dossier
    
- gestion de la lecture du fichier midi 
  - afficher les instruments utilisé dans le fichier midi
  - fait l'association automatique des intruments utilisé dans le fichier midi et les instruments connecté
  - permettre de selectionner un autre type d'instrument connecté comme sortie pour le chanel du fichier midi (et enregistrer le choix pour ce fichier ?)
  - envoi les messages midi a chaque instrument selectionné avec les delais adapté de chaque instrument

- reconnaitre et lister les instruments connecté
  - recuperer le type d'instrument
  - recuperer le delais pour activation
  - les informations sur les notes jouables (premiere note midi, nombre de note jouable, type de gamme utilisé, nombre de corde etc..)


## identification de l'instrument

On va chercher a utiliser un message SysEx de Requête d'Identification pour informer le controleur du type d'instrument connecté se ses carracteristiques.
- le type d'appareil
- le delais pour action
- la premiere note midi jouable 
- le nombre de note jouable
- le type d'octave (chromatique ou diatonique)
  

L'appareil répond avec un message SysEx qui contient des informations telles que :
- Manufacturer ID : Identifiant du fabricant de l'appareil.
- Device ID : Identifiant unique pour cet appareil particulier.
- Version du Firmware : Informations sur la version du firmware.
- Nom ou Modèle de l'Appareil : Optionnellement, le nom ou le modèle de l'appareil peut être inclus.
  
nous ajouterons pour notre besoin une information sur le delais d'action de l'instrument

#### Exemple reponse de SysEx
``` 
F0 7E <Device ID> 06 02 <Manufacturer ID> <Family Code> <Family Number> <Software Revision> F7
```
- F0 : Début d'un message SysEx.
- 7E : Universel non réel-temps.
- <Device ID> : Identifiant de l'appareil (retourne l'ID).
- 06 : Sous-ID #1 (indique "Device Inquiry").
- 02 : Sous-ID #2 (indique "Reply").
- <Manufacturer ID> : Identifiant du fabricant (ex. 41 pour Roland, 7D pour les projet open source, etc.).
- <Family Code> : Code de la famille de produits (deux octets).
- <Family Number> : Numéro de modèle ou série (deux octets).
- <Software Revision> : Version du firmware ou du logiciel (quatre octets).
- F7 : Fin du message SysEx.

on utilisera l'octets de <Device ID> avec les codes general midi 1 pour les Program Change Instrument Mapping pour identifier l'instrument
on utilisera les 2 octets de <Family Number> pour informer sur le temps de delais moyen pour jouer une note
on utilisera les 4 octets de <Software Revision> separément pour informer le controleur sur : la premiere note midi, le nombre de notes jouable, le type de gamme utilisé.
on a encore les 2 octets de <Family Code> pour d'autre infos si necessaire

#### Association instrument / Device ID 
General MIDI 1 - Program Change Instrument Mapping

| Famille                 | Numéro du Programme | Instrument                      |
|-------------------------|---------------------|----------------------------------|
| Piano                   | 1 - 8               | Acoustic Grand Piano - Clavinet  |
| Chromatic Percussion     | 9 - 16              | Celesta - Glockenspiel           |
| Organs                  | 17 - 24             | Drawbar Organ - Rock Organ       |
| Guitars                 | 25 - 32             | Acoustic Guitar (nylon) - Jazz Guitar |
| Basses                  | 33 - 40             | Acoustic Bass - Synth Bass 2     |
| Strings                 | 41 - 48             | Violin - String Ensemble 2       |
| Ensemble                | 49 - 56             | Synth Strings 1 - Choir Aahs     |
| Brass                   | 57 - 64             | Trumpet - Synth Brass 2          |
| Reed                    | 65 - 72             | Soprano Sax - Bassoon            |
| Pipe                    | 73 - 80             | Piccolo - Ocarina               |
| Synth Lead              | 81 - 88             | Square Lead - Clav Lead          |
| Synth Pad               | 89 - 96             | New Age Pad - Halo Pad           |
| Synth Effects           | 97 - 104            | Rain Effect - Sci-Fi Effect      |
| Ethnic                  | 105 - 112           | Sitar - Shanai                  |
| Percussive              | 113 - 120           | Tinkle Bell - Agogo             |
| Sound Effects           | 121 - 128           | Telephone Ring - Gunshot        |






  
