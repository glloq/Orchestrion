# Orchestrion - Projet de création d'un orchestre électronique

Le projet Orchestrion est une initiative ambitieuse visant à créer un orchestre électronique complet composé d'instruments acoustiques. L'objectif de ce projet est de jouer des musiques à partir de fichiers MIDI.

Ce dépôt GitHub regroupe les explications générales du projet, y compris l'interface Raspberry Pi, l'actionneur MIDI Arduino, les choix de matériaux et différents électroaimants, servomoteurs, électronique de puissance, etc.

Chaque type d'instrument aura un lien vers son propre dépôt pour l'instrument contenant les plans, fichiers et tutoriels spécifiques à chaque instrument.
## Composition de l'orchestre électronique

### L'orchestre électronique est composé des types d'instruments suivants :

   - Instruments à cordes frottées : violon, alto, violoncelle, contrebasse.
   - Instruments à cordes pincées : harpe, guitare, mandoline, ukulele.
   - Instruments à vents : flûte, piccolo, clarinette, hautbois, cor anglais, basson, saxophone, trompette, cornet, cor d'harmonie, trombone, tuba, orgue, harmonica, accordéon.
  -  Instruments à percussion : timbales, xylophone, marimba, vibraphone, marimba, cymbales, gongs, triangle, tambourin, castagnettes, carillon.
  -  Instruments à clavier : piano, orgue, accordéon, harmonium.

l'objectif est d'utiliser des instruments acoustique uniquement.

## Contrôle de l'orchestre électronique

Tous les instruments seront contrôlés électroniquement à l'aide de microcontrôleurs Arduino, de moteurs, d'électroaimants et de servomoteurs.

L'orchestre électronique sera construit à partir de matériaux tels que du bois, du métal ou l'impression 3D. Chaque instrument sera équipé d'électronique pour contrôler les mouvements des cordes, des membranes et des clapets nécessaires pour produire les sons.

Le contrôle de l'orchestre électronique sera effectué à partir d'un ordinateur ou d'un Raspberry Pi via une page web. L'utilisateur pourra sélectionner un fichier MIDI et assigner les différents canaux à chaque instrument. Pour la communication MIDI via USB, nous utiliserons la bibliothèque MidiUSB.h.

## Choix électroniques

- Nous utiliserons des MCP23017 pour ajouter jusqu'à 128 sorties supplémentaires pour gérer les électroaimants. 
- Pour la gestion de la puissance, nous utiliserons soit des modules ULN2803 ou ULN2804, soit des MOSFETs, soit des relais. 
- Les moteurs utilisés seront des moteurs DC contrôlés par PWM ou des moteurs pas à pas pour un contrôle plus précis des mouvements. 
- Pour les servomoteurs, nous utiliserons des modèles adaptés à la partie puissance choisie et qui sont silencieux.
- La gestion de la vélocité sera assurée par la modification de la puissance envoyée aux électroaimants avec un découpage de l'alimentation en utilisant un relais SSR.

# Code instruments actuel
-Xylophone, marimba, vibraphone = [Code adaptable de 17 a 32 notes avec gestion pwm + silencieux pour noteOff + volume/vibrato](https://github.com/glloq/Orchestrion-Xylophone)

# Contributions

Les contributions au projet sont les bienvenues. Les utilisateurs sont encouragés à soumettre des suggestions, des améliorations et des ajouts de nouvelles fonctionnalités. Les contributions doivent être soumises sous la forme de pull requests.

