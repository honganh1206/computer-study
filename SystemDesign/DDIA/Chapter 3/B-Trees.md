Like [[SSTables and LSM-Trees]], B-Trees keep key-value pairs sorted by key, but instead of breaking down data into segments, B-Trees breaks down the data into *fixed-sized blocks and pages*, and read & write one page at a time.

Each page can be identified using an address like a pointer, and pages can refer to each other.

One page works as a root containing keys and references to child pages.

## Branching factor

The number of references to child pages, typically several hundred.

When we update the value, we search for the leaf page containing the key -> write the page back to disk.

When adding a key, we search for the page whose range encompasses the new key then add it to the page.

If there is not enough space to accommodate the new key, we split the page into two half-full pages, and the parent page is updated with references to the new child pages -> Maintain a balanced tree with depth of $O\log(n)$

## Making B-Trees reliable

Overwriting a page on disk with new data should not change the location of the page.

> [!info] Think of overwriting a page on disk like an actual hardware operation
> We first move the disk head to the right place -> Wait for the right position on the spinning platter to come around -> Overwrite the sector with new data.

We maintain a *Write-Ahead Log* (WAL), an append-only file to which every B-tree modification must be written before it can be applied to the pages.

For currency control, we protect the tree's data structure with latches (lightweight locks)

## Optimizing B-Trees

- Use copy-on-write schema (LMDB): A modified page is written to a different location, and a new version of the parent page is created, pointing to the new location.
- Abbreviate the keys instead of storing the entirety of them to save space.
- (Sometimes) lay out leaf pages in sequential orders when scanning a large part of the key range.
- Make leaf pages carry references to their sibling pages
- Use logs to reduce disk seeks (fractal trees for example)