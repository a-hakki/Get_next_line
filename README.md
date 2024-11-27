# Get_next_line

## **42 Get Next Line Project: README**

---

#### **Introduction**

The **Get Next Line (GNL)** project challenges you to implement a function that reads a line from a file descriptor (FD), one at a time, regardless of line length. The project is a great opportunity to work with file descriptors, buffers, dynamic memory allocation, and efficient file reading techniques.

---

#### **Objective**

To create a function:  

```c
char *get_next_line(int fd);
```

- **Input**: A file descriptor `fd`.
- **Output**: Returns the next line (terminated by `\n`) read from `fd`. If the end of the file is reached or an error occurs, return `NULL`.

---

#### **Features**

- Handles any valid file descriptor (e.g., files, stdin).
- Reads lines of arbitrary length efficiently.
- Utilizes a **buffer** of customizable size to minimize system calls and optimize performance.
- Manages memory dynamically to handle partial reads and leftovers between calls.

---

#### **Implementation Highlights**

1. **Static Variables**:
   - Use static variables to retain leftover data between function calls for the same file descriptor.

2. **File Descriptor (FD)**:
   - The function can handle multiple file descriptors simultaneously, ensuring data integrity for each.

3. **Buffer Management**:
   - The buffer size (`BUFFER_SIZE`) determines how much data is read at a time.
   - Balance between memory usage and performance.

4. **Edge Cases**:
   - Handle invalid file descriptors, empty files, and memory allocation failures gracefully.

5. **Memory Safety**:
   - Ensure no memory leaks by properly freeing allocated memory.

---

#### **Allowed Functions**

- `read`
- `malloc`
- `free`
- `write`
- `close`

---

#### **Project Structure**

```
📂 get_next_line
├── 📄 get_next_line.c       // Main function logic
├── 📄 get_next_line_utils.c // Helper functions
├── 📄 get_next_line.h       // Header file with prototypes and macros
└── 📄 Makefile              // Compilation rules
```

---

#### **Compilation**

Use the provided `Makefile` to compile the project:

```bash
make
```

- **Output**: A library `get_next_line.a` containing all necessary functions.

---

#### **Usage**

1. Include the header file in your program:
   ```c
   #include "get_next_line.h"
   ```

2. Call the function:
   ```c
   int fd = open("file.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL) {
       printf("%s\n", line);
       free(line);
   }
   close(fd);
   ```

---

#### **Testing**

- Test with various files:
  - Empty files.
  - Files with varying line lengths.
  - Files without `\n` at the end.
  - Standard input (e.g., piping input from the terminal).
  
- Use Valgrind or similar tools to check for memory leaks:
  ```bash
  valgrind ./your_program
  ```

---

#### **Bonus Features**

If you complete the mandatory part perfectly, you can implement the following bonus features:

1. **Support for Multiple FDs**:
   - Allow `get_next_line` to handle multiple file descriptors concurrently.

2. **Customizable Buffer Size**:
   - Define `BUFFER_SIZE` at compile time for flexible testing:
     ```bash
     gcc -D BUFFER_SIZE=42
     ```

---

#### **Tips for Success**

- Break down the problem into manageable pieces:
  - Reading data into a buffer.
  - Handling leftover data between calls.
  - Allocating and appending strings dynamically.

- Write helper functions to simplify and reuse code (e.g., string manipulation utilities).
- Test incrementally to debug effectively.

---

#### **Resources**

- **Man Pages**: `man read`, `man malloc`, `man free`
- **42 Forum**: Collaborate with peers for debugging tips.
- **Online References**: Explore how `read` and buffers work under the hood.

---