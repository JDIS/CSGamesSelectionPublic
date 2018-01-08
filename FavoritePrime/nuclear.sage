# nuclear.sage
from sage.all import *

def encode(message_str):
    return int(message_str.encode('hex'), 16)

def decode(message_int):
    h = hex(message_int)[2:]
    if h[-1] == "L": h = h[:-1]
    if len(h) % 2 != 0: h = "0" + h
    return h.decode('hex')

# This is my favorite prime. Don't listen to the #FAKENEWS that I shouldn't reuse it
p = # MEMORY CORRUPTED # 
q = random_prime(2**1024-1, False, 2**1023)
N = p * q

e = 65537
m = # MEMORY CORRUPTED #
assert(decode(encode(m)) == m)

c = pow(encode(m), e, N)

print("N: ")
print(N)
print("Encrypted message: ")
print(c)
# Signed: DT.
