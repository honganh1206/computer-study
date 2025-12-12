---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
```python
def find_directories_recursive(dir):
    for fileName in os.listdir(dir):
        file_dir = os.path.join(dir, fileName)
        # Exclude the current dir and parent dir the function is checking
        if os.path.isdir(file_dir) and fileName != "." and fileName != "..":
            print(file_dir)
            '''
            As this script encounters files that are themselves subdirectories,
            it calls the find_directories method upon that very subdirectory.
            '''
            find_directories_recursive(file_dir)
```