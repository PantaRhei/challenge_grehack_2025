#!/usr/bin/env python3
"""
num_to_ascii.py

Lit un fichier ligne par ligne, remplace chaque nombre (ex: 65 ou 0x41)
par son équivalent ASCII, et affiche la ligne transformée.

Usage:
    python3 num_to_ascii.py fichier.txt
"""

import sys
import re

def convert_numbers_to_ascii(line: str) -> str:
    """
    Trouve tous les nombres dans la ligne et les remplace par leur caractère ASCII.
    Accepte les formats décimaux (65) et hexadécimaux (0x41).
    """

    def repl(match):
        num_str = match.group(0)
        try:
            value = int(num_str, 0)  # base 0 => auto (0x.. = hex, sinon décimal)
            if 0 <= value <= 0x10FFFF:
                return chr(value)
        except Exception:
            pass
        # si invalide, on garde le texte original
        return num_str

    # Remplace tous les nombres isolés (entourés d'espaces, virgules ou séparateurs)
    return re.sub(r'\b(0x[0-9A-Fa-f]+|\d+)\b', repl, line)


def main():

    path = "data_m4/fichier.log"

    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as f:
            for line in f:
                converted = convert_numbers_to_ascii(line.rstrip("\n"))
                print(converted)
    except FileNotFoundError:
        print(f"Erreur: fichier '{path}' introuvable.", file=sys.stderr)
        sys.exit(2)


if __name__ == "__main__":
    main()
