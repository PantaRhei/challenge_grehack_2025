=========BOLOW FRENCH TEXT============
# 433 MHz Radio

The goal of this challenge is to introduce participants to basic radio concepts.
The challenge is based on the software [rtl_433](https://github.com/merbanan/rtl_433), which can receive many types of IoT signals operating around 433 MHz.

# Context

Phrases are transmitted using a 433 MHz transmitter controlled by an **Arduino MKR WiFi 1010**.
The text is encrypted with a Vigenère cipher whose key is part of the FLAG. The key is transmitted in clear text in the format `FLAG`, and the final flag format is `GH{FLAG}` — participants must prepend `GH{` and append `}` to the recovered key.
Captures were recorded in a noisy, dense RF environment, so many received signals are unrelated to the challenge. Messages relevant to the challenge are fictional/concocted payloads embedded among other transmissions.

# Provided files

The captures were recorded with an **RTL-SDR v4** while the Arduino MKR WiFi 1010 transmitted the data. Because the RTL-SDR receives the whole radio environment in parallel, you will see many signals unrelated to the Arduino transmissions. Several capture files are provided so you can identify and isolate the challenge-relevant signals.


=========FRENCH VERSION============
Voici la version française corrigée et rédigée proprement :



# Radio 433 MHz

## Objectif

Le but de ce challenge est d’initier les participants à la radio.
Le challenge s’appuie sur le logiciel **rtl_433** ([https://github.com/merbanan/rtl_433](https://github.com/merbanan/rtl_433)), qui permet de recevoir de nombreux objets communicants autour de 433 MHz.

## Contexte

Des phrases sont transmises à l’aide d’un émetteur 433 MHz piloté par une **Arduino MKR WiFi 1010**.
Le texte est chiffré avec un chiffre de **Vigenère** dont la clé constitue une partie du FLAG.
La clé est transmise en clair au format `FLAG`; le FLAG final est au format `GH{FLAG}` — le participant devra donc ajouter le préfixe `GH{` et la terminaison `}` au terme récupéré.

Les captures ont été réalisées dans un environnement RF dense : de nombreuses réceptions sont donc étrangères au challenge. Les messages liés au challenge sont des charges utiles fictives placées parmi d’autres transmissions.

## Fichiers fournis

Les captures ont été réalisées avec un **RTL-SDR v4** pendant que l’Arduino envoyait les données.
Comme le RTL-SDR reçoit l’ensemble du spectre, vous verrez de nombreux signaux parasites ou provenant d’autres émetteurs. Plusieurs fichiers de capture sont fournis pour vous permettre d’identifier et d’isoler les transmissions pertinentes au challenge.


