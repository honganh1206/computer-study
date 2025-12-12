ASCII table has 128 characters (7 bit representing $2^7=128$ characters).

Since the creation of Unicode with emojis, some characters may require up to four bytes. The Unicode standard defines several ways to encode characters, including UTF-8

```bash
$ head -c 2 tests/inputs/one.txt
Ö # 2 bytes long, so we request 2 bytes with head
$ head -c 1 tests/inputs/one.txt
� # if request 1 byte only then we have a conversion problem
```