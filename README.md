# Hack Assembler in C

A two-pass assembler for the Hack machine language, written in C. This project is part of the Nand2Tetris course and translates symbolic Hack assembly into 16-bit binary machine code.

---

## About The Project

This project is a from-scratch implementation of a Hack assembler. The architecture is designed to be simple and modular, with a clear separation between the core responsibilities: parsing assembly syntax, managing symbols, and translating mnemonics into binary.

### Features

- Full Hack assembly language support (A-Instructions and C-Instructions)
- Complete symbol resolution for predefined symbols, labels, and variables
- Classic two-pass architecture for resolving forward references
- Modular design separating the parser, symbol table, and translator
- Makefile-based build system for Linux and other Unix-like systems
- Strict and consistent code style enforced by `.clang-format`

### Built With

- [C](<https://en.wikipedia.org/wiki/C_(programming_language)>)
- [GNU Make](https://www.gnu.org/software/make/)
- [Clang](https://clang.llvm.org/)
- [Bear](https://github.com/rizsotto/Bear)

---

## Getting Started

To get a local copy up and running, follow these steps.

### Prerequisites

A C toolchain (`clang` is recommended), `make`, and `bear` must be installed.

#### Linux

- **On Arch Linux:**
  ```sh
  sudo pacman -S clang base-devel make bear
  ```
- **On Debian/Ubuntu:**
  ```sh
  sudo apt-get install clang build-essential make bear
  ```

### Building the Project

1.  **Clone the repository:**

    ```sh
    git clone https://github.com/francis1009/nand2tetris-assembler.git
    cd nand2tetris-assembler
    ```

2.  **Generate `compile_commands.json`:**
    This step configures the editor's language server (e.g., `clangd`). It only needs to be run once, or whenever source files are added or removed.

    ```sh
    bear -- make debug
    ```

3.  **Build the assembler:**
    This creates the executable at `bin/assembler_debug` or `bin/assembler`.

    ```sh
    # For a debug build with extra checks
    make debug

    # For an optimized release build
    make release
    ```

---

## Usage

The assembler is run from the command line, taking the name of an assembly file as an argument.

1.  Place your assembly files (e.g., `Pong.asm`) inside the `asm/` directory.

2.  Run the assembler from the project root, specifying the file name with the FILE variable. The Makefile automatically looks for the file inside the `asm/` directory.

    ```sh
    # Example using the release build
    make run FILE=Pong.asm
    ```

3.  The translated machine code will be written to `output.hack` in the project's root directory.

---

## Development

This project uses `clang-format` to maintain a consistent code style. The rules are defined in the `.clang-format` file. If you have a "format-on-save" feature configured in your editor, it will be applied automatically.

---

## Acknowledgments

This project is an implementation of the assembler described in the Nand2Tetris course. The architecture and logic are based on the principles taught in the course.

- **The Nand2Tetris Website ([nand2tetris.org](https://www.nand2tetris.org/))**: The official resource for all course materials, software tools, and forums.
