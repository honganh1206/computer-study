#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Structure of header - similar to a linked list
// Store metadata about memory blocks in a memory allocator implementation
struct block_meta {
  size_t size;
  struct block_meta *next; // Pointer to the next block
  int free;                // Flag to check free block or not
  int magic; // Debugging only to see which code modifies the struct last. TODO:
             // Remove this in non-debug mode
};

#define META_SIZE sizeof(struct block_meta)

void *first_block = NULL; // A head for our linked list

// A pointer to another pointer as a parameter
// Optimize re-using free space
struct block_meta *find_free_block(struct block_meta **last, size_t size) {
  struct block_meta *current = first_block;
  // Iterate through the linked list for a free block
  while (current && (current->free && current->size >= size)) {
    // Point to the last node of the list
    *last = current;
    current = current->next;
  }
  return current;
};

void init_memory();
void free_memory();

// BIG block of memory
void *memory = NULL;
// Position where the LAST block ends
/*size_t endpos = 0;*/

#define MINREQ 0x20000
#define TOTAL_MEMORY_SIZE (1024 * 1024) // 1MB

// Get the largest chunk of memory the OS can provide
void init_memory() {
  size_t required = PTRDIFF_MAX;

  while (memory == NULL) {
    // Try to allocate maximum amount of memory
    memory = malloc(required);
    if (required < MINREQ) {
      if (memory) {
        // Free any successful allocation
        free(memory);
      }
      printf("Cannot allocate enough memory\n");
      // Program crashes if there is not at least 128KB of memory available
      exit(ENOMEM);
    }
    // Divine the amount by 2 every time the allocation fails
    required >>= 1;
  }
}

// Free the big chunk of memory
void free_memory() { free(memory); }

// Request the OS some space and add the new block to the end of the linked list
// This function returns a pointer
struct block_meta *request_space(struct block_meta *last, size_t size) {
  struct block_meta *block;
  block = sbrk(0); // Return the pointer to the CURRENT top of the heap
  void *request =
      sbrk(size + META_SIZE);       // System call to increment the heap size
  assert((void *)block == request); // Not thread safe

  // If there is a free block
  // Set it as occupied and return that block
  /*if (block) {*/
  /*  block->free = 0;*/
  /*  return block;*/
  /*}*/
  if (request == (void *)-1) {
    return NULL; // sbrk fail will return -1 cast as a void pointer aka no more
                 // memory available
  }

  /**/
  /*if (memory == NULL) {*/
  /*  return NULL;*/
  /*}*/
  /**/
  /*// Check overflow*/
  /*if (endpos + META_SIZE + size > TOTAL_MEMORY_SIZE) {*/
  /*  return NULL;*/
  /*}*/
  /**/
  // If not append a new block to list
  /*block = memory + endpos;*/
  /*endpos += META_SIZE + size;*/

  if (last) { // NULL on 1st request
    // Point the last node to the new block
    last->next = block;
  }
  /**/
  /*else {*/
  /*  // First call -> Point the head to the new block*/
  /*  first_block = block;*/
  /*}*/
  block->free = 0; // Set the new block as occupied - VIOLATE MEMORY here 139
  block->next = NULL;
  block->size = size;
  block->magic = 0x12345678;

  return block;
}

void *custom_malloc(size_t size) {
  struct block_meta *block;
  // TODO: align size?

  if (size <= 0) {
    return NULL;
  }

  if (!first_block) { // 1st call
    block = request_space(NULL, size);
    if (!block) {
      return NULL;
    }
    first_block = block;
  } else {
    struct block_meta *last = first_block;
    block = find_free_block(&last, size);
    if (!block) { // Failed to find free block
      block = request_space(last, size);
      if (!block) {
        return NULL;
      } else { // Found free block, occupy it then
        // TODO: Consider splitting blocks here
        block->free = 0;
        block->magic = 0x77777777;
      }
    }
  }

  // Return a pointer to the region AFTER block_meta
  // +1 increments the address by one sizeof(struct block_meta)
  return block + 1;
}

// Get the address of our struct in multiple places in our code
struct block_meta *get_block_ptr(void *ptr) {
  return (struct block_meta *)ptr - 1;
}

void custom_free(void *ptr) {
  /*struct block_meta *block = ptr - META_SIZE;*/
  /*block->free = 1;*/
  if (!ptr) {
    return;
  }

  // TODO: Consider merging blocks once splitting blocks is implemented
  struct block_meta *block_ptr = get_block_ptr(ptr);
  // We don't really need these, but they make debugging simpler

  assert(block_ptr->free == 0); // Fail here because ptr free == 1
  assert(block_ptr->magic == 0x77777777 || block_ptr->magic == 0x12345678);

  block_ptr->free = 1;
  block_ptr->magic = 0x55555555;
}

// Adjust the size of the memory block returned from calloc
void *custom_realloc(void *ptr, size_t size);

// The point of realloc: malloc new space and free old space
// Then copy old data to new space
void *custom_realloc(void *ptr, size_t size) {
  if (!ptr) {
    // Treat null ptr like how custom_malloc does
    return custom_malloc(size);
  }
  struct block_meta *block_ptr = get_block_ptr(ptr);
  // Given size bigger than prior size
  if (block_ptr->size >= size) {
    // Enough space. Could free some more if we implement splitting
    return ptr;
  }

  // Given size smaller than prior size => Allocate a smaller block and fit data
  // into it
  void *new_ptr;
  new_ptr = custom_malloc(size);
  if (!new_ptr) {
    return NULL; // TODO Set errno on failure
  }
  memcpy(new_ptr, ptr, block_ptr->size);
  custom_free(ptr);
  return new_ptr;
}

// Initialize the memory to 0
void *custom_calloc(size_t nelem, size_t elsize) {
  size_t size = nelem * elsize;
  if (size > TOTAL_MEMORY_SIZE) {
    return NULL;
  }

  void *ptr = custom_malloc(size);
  memset(ptr, 0, size);
  return ptr;
}

int main() {
  /*init_memory();*/
  int *p;
  double *new_p;
  p = custom_malloc(sizeof(int));
  if (p == NULL) {
    printf("Bad malloc error\n");
    exit(1);
  }

  *p = 6;
  printf("%d\n", *p);
  printf("%p\n", &p);
  printf("%zu\n", sizeof(*p));
  new_p = custom_realloc(p, sizeof(double));
  if (new_p == NULL) {
    printf("Bad realloc error\n");
    exit(1);
  }

  printf("%p\n", &new_p);
  printf("%zu\n", sizeof(*new_p));
  /*free_memory();*/

  // Allocate array of 5 ints, init to 0
  int *arr = (int *)custom_calloc(5, sizeof(int));
  if (arr == NULL) {
    printf("Calloc failed\n");
    exit(1);
  }

  for (int i = 0; i < 5; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  /*custom_free(arr);*/
  return 0;
}
