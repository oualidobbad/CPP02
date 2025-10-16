#!/usr/bin/env python3
"""
RSA Decryption - Verification Script
"""

import math
from random import randint

# RSA Parameters
C = 0x02c1bc79b068ba0c31244e6b81d17727fa934ea65c0df85cfc678160a0a0f4fe5e0e00c717d9d45a75d72ceaa87b4c34fe04
E = 0xC0DE - 1  # = 49373
N = 0x168164dbddb07afe12e5be8cabecfc694eff9643d51f533915ee55b217697cc78256503276ee00af4dfe166c0725fdc1447f

print("[*] RSA Decryption - Verification")
print(f"[*] User: oualidobbad")
print(f"[*] Time: 2025-10-16 17:31:57")
print(f"[*] E = {E}")

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def pollard_rho(n):
    """Pollard's Rho - simpler and reliable"""
    if n == 1:
        return n
    if n % 2 == 0:
        return 2
    
    x = randint(2, n - 1)
    y = x
    c = randint(1, n - 1)
    d = 1
    
    f = lambda x: (x * x + c) % n
    
    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gcd(abs(x - y), n)
    
    if d != n:
        return d
    else:
        return pollard_rho(n)  # Retry with different values

print("\n[*] Factoring N...")
p = pollard_rho(N)
q = N // p

print(f"[+] p = {p}")
print(f"[+] q = {q}")
print(f"[+] p * q == N: {p * q == N}")

# Calculate phi
phi = (p - 1) * (q - 1)
print(f"\n[+] phi(N) = {phi}")

# Extended GCD
def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd_val, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd_val, x, y

gcd_val, D, _ = extended_gcd(E, phi)
D = D % phi

print(f"[+] D = {D}")
print(f"[+] Verification: (E * D) mod phi = {(E * D) % phi}")

# Decrypt
print(f"\n[*] Decrypting C^D mod N...")
M = pow(C, D, N)

print(f"[+] M (decimal) = {M}")
print(f"[+] M (hex) = {hex(M)}")

# Convert to bytes and try different encodings
hex_str = hex(M)[2:]
if len(hex_str) % 2:
    hex_str = '0' + hex_str

print(f"\n[*] Attempting different decodings...")

# Try UTF-8
try:
    plaintext_utf8 = bytes.fromhex(hex_str).decode('utf-8')
    print(f"[+] UTF-8: {plaintext_utf8}")
except:
    print(f"[-] UTF-8 decoding failed")

# Try ASCII
try:
    plaintext_ascii = bytes.fromhex(hex_str).decode('ascii')
    print(f"[+] ASCII: {plaintext_ascii}")
except:
    print(f"[-] ASCII decoding failed")

# Try Latin-1
try:
    plaintext_latin1 = bytes.fromhex(hex_str).decode('latin-1')
    print(f"[+] Latin-1: {plaintext_latin1}")
except:
    print(f"[-] Latin-1 decoding failed")

# Print raw bytes
print(f"\n[+] Raw hex bytes: {hex_str}")
print(f"[+] Raw bytes: {bytes.fromhex(hex_str)}")

# Try splitting into chunks
print(f"\n[*] Trying different interpretations...")
byte_data = bytes.fromhex(hex_str)
print(f"[+] Bytes length: {len(byte_data)}")
print(f"[+] As string (errors='ignore'): {byte_data.decode('utf-8', errors='ignore')}")
print(f"[+] As string (errors='replace'): {byte_data.decode('utf-8', errors='replace')}")