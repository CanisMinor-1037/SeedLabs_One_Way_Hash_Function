# Most Linux distributions come with utility programs that implement a variety
# of hash algorithms. Show examples in the following: 
md5sum file
sha224sum file
sha256sum file
sha384sum file

# Another way to calculate hash is to use openssl command
# show a list of the hash algorithms current implemented by openssl
openssl dgst -list

# use the openssl to calculate on-way hashes
openssl dgst -sha256 file
openssl sha256 file
openssl dgst -md5 file
openssl md5 file