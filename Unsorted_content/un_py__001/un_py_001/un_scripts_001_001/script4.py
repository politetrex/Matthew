from argon2 import PasswordHasher
from argon2.exceptions import VerifyMismatchError, VerificationError
import time

# Initialize the hasher
ph = PasswordHasher(
    memory_cost=131071,
    time_cost=5, 
    parallelism=2
)

# Test password
password = "test_password_123"

print("ARGON2 TEST")
print("=" * 50)

# Hash a password
start = time.perf_counter()
hash_value = ph.hash(password)
hash_time = (time.perf_counter() - start) * 1000

print(f"Hash time: {hash_time:.1f} ms")
print(f"Hash: {hash_value}")
print()

# Verify correct password
start = time.perf_counter()
try:
    ph.verify(hash_value, password)
    verify_time = (time.perf_counter() - start) * 1000
    print(f"Verification time: {verify_time:.1f} ms")
    print("✅ Correct password verified!")
except:
    print("❌ Verification failed (shouldn't happen)")

print()

# Verify wrong password
try:
    ph.verify(hash_value, "wrong_password")
    print("❌ Wrong password accepted (BAD!)")
except VerifyMismatchError:
    print("✅ Wrong password rejected (good!)")
except VerificationError as e:
    print(f"Verification error: {e}")