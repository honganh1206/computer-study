For data being used internally, we use formats that are easy to parse (the same for small datasets). However when the data gets too big, the choice of data format matters.

JSON is less verbose compared to XML but still use a lot of space. Alternatives are BSON, BJSON, etc. These formats extend the set of data types sometimes but mostly keep the JSON/XML data model unchanged.

An example of encoding JSON with MessagePack:

```json
{
	"userName": "Martin",
	"favoriteNumber": 1337,
	"interests": ["daydreaming", "hacking"]
}
```

When we binary encode this with MessagePack, the output is 66 bytes long, only a little less than 81 bytes from the textual JSON.