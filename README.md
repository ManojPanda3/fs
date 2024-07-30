## fs:  Lightning-Fast File Search with z-Algorithm 🚀

**fs** is a command-line tool designed for quick and efficient file searching. It employs the powerful **z-Algorithm** for string matching, offering blazing-fast results. ⚡

**Forget about sluggish searches, fs is here to rescue you!**

![fs-demo](https://i.imgur.com/ZaC0QmF.png)

As you can see from the image, `fs` (using the z-Algorithm) significantly outperforms the traditional `find` command, demonstrating its lightning-fast nature.

### How to Use:

```bash
fs [file to search...] [options...] [argsOfOptions...] 
```

**Basic Usage:**

* **`fs [file]`:** Searches for the specified file in the current directory.
* **`fs [file] -d [...dir]`:** Searches for the specified file within the provided directories. 
* **`fs [file] -d [...dir] -s`:**  Enables **strict mode**. This prevents fs from skipping hidden folders, `.git` directories, and other commonly ignored folders like `node_modules`, `vendor`, `tmp`, `coverage`, `target`, and `build`.  Be warned, strict mode might slow down the search process.
* **`fs [file] -r [regex]`:** Searches for the file using the specified regular expression.

**Examples:**

* Find a file named `index.html` in the current directory: `fs index.html`
* Find a file named `README.md` within `/home/user/projects` and `/home/user/documents`: `fs README.md -d /home/user/projects /home/user/documents`
* Find a file named `config.json` in the current directory, including hidden files and ignored directories: `fs config.json -s`
* Find files that start with "config" and end with ".json" using regular expression: `fs -r "^config.*\.json$"`

**Key Features:**

* **🚀 Fast and Efficient:**  Leverages the z-Algorithm for rapid string matching.
* **🔍 Regex Support:**  Supports regular expressions (using `pcre2`) for advanced search patterns using the `-r` flag. 
* **🗃️ Recursive Directory Traversal:**  Efficiently scans through entire directory structures.
* **🚫 Strict Mode:**  Option to include hidden folders and ignored directories in the search using the `-s` flag.
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


