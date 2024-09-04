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
- [ukulele](https://github.com/glloq/Orchestrion_ukulele)
- [piano ](https://github.com/glloq/Orchestrion_Piano)
- 


