# Orchestrion - Projet de création d'un orchestre électronique

Le projet Orchestrion est une initiative ambitieuse visant à créer un orchestre électronique complet composé d'instruments acoustiques. L'objectif de ce projet est de jouer des musiques à partir de fichiers MIDI.

Ce dépôt GitHub regroupe les explications générales du projet

Chaque type d'instrument aura un lien vers son propre dépôt pour l'instrument contenant les plans, fichiers et tutoriels spécifiques à chaque instrument.

## Contrôle de l'orchestre électronique

Tous les instruments seront contrôlés électroniquement à l'aide de microcontrôleurs Arduino, de moteurs, d'électroaimants et de servomoteurs.

L'orchestre électronique sera construit à partir de matériaux tels que du bois, du métal ou l'impression 3D. Chaque instrument sera équipé d'électronique pour contrôler les mouvements des cordes, des membranes et des clapets nécessaires pour produire les sons.

Le contrôle de l'orchestre électronique sera effectué à partir d'un ordinateur ou d'un Raspberry Pi via une page web. L'utilisateur pourra sélectionner un fichier MIDI et assigner les différents canaux à chaque instrument. Pour la communication MIDI via USB, nous utiliserons la bibliothèque MidiUSB.h.

# Code instruments actuel

- Xylophone, glokenspiel, marimba, vibraphone = [Code adaptable de 17 a 32 notes avec gestion pwm + silencieux pour noteOff + volume/vibrato](https://github.com/glloq/Orchestrion-Xylophone)
- [lyre 16 cordes](https://github.com/glloq/16-cords-lyre-midi)
- [ukulele solenoides](https://github.com/glloq/Orchestrion_ukulele)
- [ukulele moteurs PAP](https://github.com/glloq/ukulele_stepper_motor)
- [piano](https://github.com/glloq/Orchestrion_Piano)
- [percussion](https://github.com/glloq/MidiPercussion)
- [Trompette](https://github.com/glloq/Orchestrion_trumpet) 
- [flute a bec](https://github.com/glloq/servo-flute)
- [Harmonica](https://github.com/glloq/harmonica_Midi)
- [violon](https://github.com/glloq/violano-virtuoso)
- basse => je doit adapter le code du ukulele solenoides
- guitare => je doit adapter le code du ukulele solenoides
- banjo => a faire 

## Code generique

- code adaptable grattage (+/- un angle alterné) ou action avec servomoteurs (deplacement on, retour off) 1 a 88 notes :[servo midi](https://github.com/glloq/servo-midi-music)

- tests et experimentations sur un intrument a une corde de type corde frottée => [lien]([https://https://github.com/glloq/OneStringCello)
- test et experimentations sur un interument a une corde gratté => 

## identification de l'instrument

On va chercher a utiliser un message SysEx de Requête d'Identification pour informer le controleur du type d'instrument connecté et le temps de delais pour action.

L'appareil répond avec un message SysEx qui contient des informations telles que :
- Manufacturer ID : Identifiant du fabricant de l'appareil.
- Device ID : Identifiant unique pour cet appareil particulier.
- Version du Firmware : Informations sur la version du firmware.
- Nom ou Modèle de l'Appareil : Optionnellement, le nom ou le modèle de l'appareil peut être inclus.
  
nous ajouterons pour notre besoin une information sur le delais d'action de l'instrument


### demande d'identification
``` 
  F0 7E 7F 06 01 F7
```
- F0 : Début du message SysEx.
- 7E : Type de message universel non temps réel.
- 7F : Device ID, 7F est une valeur spéciale qui signifie "tous les appareils".
- 06 : Commande d'identification.
- 01 : Requête d'identification.
- F7 : Fin du message SysEx.

### Exemple reponse de SysEx
``` 
F0 7E 00 06 02 7D 01 F7
```
- F0 : Début du message SysEx.
- 7E : Type de message universel non temps réel.
- 00 : ID de l'appareil 
- 06 : Sous-ID #1 : Commande pour l'identification.
- 02 : Sous-ID #2 : Réponse d'identification.
- 7D : Manufacturer ID : 7D est réservée pour des projets non commerciaux, expérimentaux ou développement open-source.
- 01 : Indicateur minimal pour l'identification du modèle ou du firmware.
- F7 : Fin du message SysEx.

Pour permettre au controleur midi de connaitre quel instrument est branché nous utiliserons donc le parametre ID de l'appareil.  
il n'y a pas de norme concernant l'ID de l'appareil, nous utiliserons donc une numerotation de 0 a 127 ( en decimal ) pour indiquer quel instrument est branché.
  
#### Association instrument / Device ID 

Voici un exemple d'ID que nous pouvons utiliser => il faudra surement doubler ou tripler certain instruments !
  
| **Device ID (hex)** | **Instrument ** | **Device ID (hex)** | **Instrument ** |
|---------------------|-----------------|---------------------|-----------------|
| 00                  | Piano           | 0D                  |                 |
| 01                  | Guitare         | 0E                  | Xylophone       |
| 02                  | Basse           | 0F                  | Vibraphone      |
| 03                  | Ukulélé         | 10                  | Mandoline       |
| 04                  | Trompette       | 11                  | Harpe           |
| 05                  | Saxophone       | 12                  | Glockenspiel    |
| 06                  | Violon          | 13                  | Congas          |
| 07                  | Clarinette      | 14                  | Tuba            |
| 08                  | Flûte           | 15                  | Cor             |
| 09                  | percussions     | 16                  | Banjo           |
| 0A                  | Accordéon       | 17                  | Basson          |
| 0B                  | Harmonica       | 18                  | Oboe            |
| 0C                  | Tambourin       | 19                  | Violoncelle     |



  
