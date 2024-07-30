## fs: Blazing Fast File Search 🔍

**fs** is a command-line utility designed to help you quickly and efficiently find files on your system. It leverages the power of the **KMP (Knuth-Morris-Pratt)** search algorithm and recursive directory traversal to deliver lightning-fast results. ⚡

**Think of it as `fd`'s close cousin, but with a sprinkle of extra features!**

### How to Use:

```bash
fs [file to search...] [options...] [argsOfOptions...] 
```

**Basic Usage:**

* **`fs [file]`:** Searches for the specified file in the current directory.
* **`fs [file] -d [...dir]`:** Searches for the specified file within the provided directories. 
* **`fs [file] -d [...dir] -s`:**  Enables **strict mode**. This prevents fs from skipping hidden folders, `.git` directories, and other commonly ignored folders like `node_modules`, `vendor`, `tmp`, `coverage`, `target`, and `build`. Be warned, strict mode might slow down the search process.

**Examples:**

* Find a file named `index.html` in the current directory: `fs index.html`
* Find a file named `README.md` within `/home/user/projects` and `/home/user/documents`: `fs README.md -d /home/user/projects /home/user/documents`
* Find a file named `config.json` in the current directory, including hidden files and ignored directories: `fs config.json -s`

**Key Features:**

* **🚀 Fast and Efficient:**  Utilizes the KMP algorithm for rapid file searching.
* **🔍 Regex Support:**  Supports regular expressions for more advanced search patterns. 
* **🗃️ Recursive Directory Traversal:**  Efficiently scans through entire directory structures.
* **🚫 Strict Mode:**  Option to include hidden folders and ignored directories in the search.
* **🖥️ Single-Threaded:**  Currently runs on a single thread, but multi-threading support is planned for future releases.

**Building:**

fs is built using `pcre2` for regular expression support.  You can install pcre2 on your system and build fs using make. 

```bash
# Install pcre2 (e.g., on Ubuntu)
sudo apt-get install libpcre2-dev

# Build fs
make
```

**Current Build Support:**

* **Linux (x86, ARM):**  Builds are currently available for Linux systems with x86 and ARM architectures. 

**Get Started:**

1. **Clone the repository:** `git clone [repo URL]`
2. **Build:**  Follow the building instructions above.
3. **Run:** `./fs [file]`

**Let us know your feedback and suggestions to help us improve fs!** 
