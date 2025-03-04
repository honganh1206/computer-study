
## Explore the Azure Blob storage lifecycle

### Access tiers

Several considerations applied to different access tiers

- Set access tier on a blob during upload
- Hot + Cool access tiers can be set at the account level / Archive tier can only be set at the blob level
- Data in the archive access tier is stored offline. => Low storage cost + high access costs and latency
- The hot and cool tiers support **all redundancy options**.
- Data storage limits are set at the account level and not per access tier.

### Manage the data lifecycle

Lifecycle management policy allows you to

- Transition blobs to a cooler storage tiers
- Delete blobs at the end of their lifecycles
- Define + Apply rules


## Discover Blob storage lifecycle policies

- A lifecycle management policy is a collection of rules in a JSON document.

```json
{
  "rules": [
    {
      "name": "rule1",
      "enabled": true, // Optional
      "type": "Lifecycle",
      "definition": {...} // Define the lifecycle rule
    },
    {
      "name": "rule2",
      "type": "Lifecycle",
      "definition": {...}
    }
  ]
}
```


### Rules

```json
{
   "definition": {
        "filters": { // Set limit rule actions to a certain set of objects
          "blobTypes": [ "blockBlob" ],
          "prefixMatch": [ "container1/foo" ]
        },
        "actions": { // Apply the tier or delete actions to the filtered set of objects when run condition is met
          "baseBlob": {
            "tierToCool": { "daysAfterModificationGreaterThan": 30 },
            "tierToArchive": { "daysAfterModificationGreaterThan": 90 },
            "delete": { "daysAfterModificationGreaterThan": 2555 }
          },
          "snapshot": {
            "delete": { "daysAfterCreationGreaterThan": 90 }
          }
        }
      }
}
```


## Rehydrate blob data from the archive tier

- Blobs in archive tier cannot be read or modified => You must first rehydrate the blob to an online tier (hot/cool). There are two options:
	- Copy the archived blobs to an online tier
	- Change the blobs’ access tier to an online one

### Rehydration priority

Rehydration priority options include:
- Standard priority
- High priority