# @brief Computing One-Way Hash in Python
# @author Seed
# @date 2022-07-18
import hashlib

m = hashlib.sha256()
m.update(b'message')
print(m.hexdigest())