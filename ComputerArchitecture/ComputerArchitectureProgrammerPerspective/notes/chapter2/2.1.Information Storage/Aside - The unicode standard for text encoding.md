---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
The ASCII character set in the past did not have much in the way for special characters outside of English, but the current Unicode standard has extended the repertoire to **10,000 characters** supporting a variety of languages.

The base encoding, the “Universal Character Set” of Unicode, requires **4 bytes per character**, but alternative codings are possible to *represent some characters as 1-2 bytes, while special ones require more*. Particularly, the UTF-8 representation *encodes each character as a sequence of bytes* as in ASCII

| Character | ASCII Code | UTF-8 Encoding (Binary) | UTF-8 Encoding (Hex) |
| --------- | ---------- | ----------------------- | -------------------- |
| A         | 65         | 01000001                | 41                   |
| a         | 97         | 01100001                | 61                   |
| B         | 66         | 01000010                | 42                   |
| b         | 98         | 01100010                | 62                   |
| Z         | 90         | 01011010                | 5A                   |
| z         | 122        | 01111010                | 7A                   |
| 0         | 48         | 00110000                | 30                   |
| !         | 33         | 00100001                | 21                   |
