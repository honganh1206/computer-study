A way to "stack" two different directories so they appear as one

- **Lower Directory (Lowerdir):** This is the **Read-Only** layer. In containers, this is your *Docker image* (e.g., Ubuntu or Alpine). Multiple containers can use the same `lowerdir` simultaneously to save disk space.
- **Upper Directory (Upperdir):** This is the **Read-Write** layer. Every container gets its own unique, empty `upperdir`. Anything the container creates or changes is stored here.
- **Work Directory**: Empty directory for internal use
- **Merged View/Target:** This is what the container actually "sees." The kernel combines the lower and upper layers into one unified file tree.