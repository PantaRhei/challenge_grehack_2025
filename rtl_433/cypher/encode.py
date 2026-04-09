from pycipher import Vigenere
import re


def read_messages_from_file(filepath: str):
    """Lit un fichier texte et renvoie une liste de lignes non vides, sans retour à la ligne."""
    messages = []
    with open(filepath, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if line:
                messages.append(line)
    return messages


# ====== CONFIG ======
key = "RADIOWAVEAUTHMHZ"
file_path = "messages_input.txt"
output_file = "messages_000001.txt"

print("Flag:", key)

# ====== Lecture des messages ======
messages = read_messages_from_file(file_path)

cipher = Vigenere(key)

def vigenere_word_by_word(text: str, cipher: Vigenere):
    """Chiffre/déchiffre un texte mot à mot avec Vigenere, sans toucher la ponctuation."""
    words = re.findall(r"[A-Za-z]+|[^A-Za-z]+", text)
    encoded_parts = []
    for part in words:
        if part.isalpha():  # mot composé uniquement de lettres
            encoded_parts.append(cipher.encipher(part.upper()))
        else:
            encoded_parts.append(part)  # ponctuation, espaces, etc.
    return ''.join(encoded_parts)

def vigenere_word_by_word_decipher(text: str, cipher: Vigenere):
    words = re.findall(r"[A-Z]+|[^A-Z]+", text)
    decoded_parts = []
    for part in words:
        if part.isalpha():
            decoded_parts.append(cipher.decipher(part))
        else:
            decoded_parts.append(part)
    return ''.join(decoded_parts)


# ====== Traitement ======
encoded = [vigenere_word_by_word(m, cipher) for m in messages]
decoded = [vigenere_word_by_word_decipher(e, cipher) for e in encoded]


# ====== Affichage console ======
print("=== Messages d'origine ===")
for i, m in enumerate(messages):
    print(f"{i+1}. {m}")

print("\n=== Messages encodés ===")
for i, msg in enumerate(encoded):
    print(f"{i+1}. {msg}")

print("\n=== Messages décodés ===")
for i, d in enumerate(decoded):
    print(f"{i+1}. {d}")


# ====== Format Arduino ======
encoded_list = ', '.join(f'"{msg}"' for msg in encoded)
decoded_list = ', '.join(f'"{msg}"' for msg in decoded)

arduino_code = f"""// Messages encodes/decodes avec le chiffre de Vigenere
// Cle utilisee : {key}

const char* messages_cipher[] = {{{encoded_list}}};
const char* messages_clear[]  = {{{decoded_list}}};

const int messageCount = {len(messages)};
"""

# ====== Écriture du fichier ======
with open(output_file, "w", encoding="utf-8") as f:
    f.write(arduino_code)

print(f"\n[*] Fichier généré : {output_file}")
