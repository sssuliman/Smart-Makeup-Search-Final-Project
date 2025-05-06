SMART MAKEUP SEARCH - PROJECT WALKTHROUGH

About the Program
-----------------
This program allows users to search through a simulated Sephora product dataset using a multi-prefix search powered by the Trie data structure.
It functions as a keyword-based lookup system, returning full product lines that match all given prefix terms. The project was built to demonstrate
efficient string search through the use of Trie trees.

Project Goal
------------
The goal of this project was to apply the Trie data structure to develop a prefix-based search engine for a makeup product database.
The Trie supports fast autocomplete-like matching on any prefix and allows the return of entire product records from a structured dataset.
The dataset is organized by brand, category, skin type, and product name.

Trie Design Overview
---------------------
The Trie is implemented using a nested character node system, where each node contains:
- A map of children pointing to next character nodes
- A set of full product lines (strings) attached to each word's end node

The Trie allows:
- Insertion of individual words from each product line
- Retrieval of all full product lines that contain words starting with a given prefix
- Multi-prefix query support by intersecting matched lines from each prefix

Key Trie operations:
- insert(string word, string line): inserts each word in the dataset and stores the full line at the end
- getMatchingLines(string prefix): finds and returns all full lines that include words starting with the given prefix

Implementation Notes
---------------------
The input dataset is stored in `data/products_organized_full.txt`.
Each product entry includes Brand, Skin Type, Category, and Product.

On program startup, the file is read line by line. Each line is:
1. Lowercased
2. Split into words
3. Each word is cleaned of punctuation and inserted into the Trie

During search:
- User enters one or more prefixes
- For each prefix, getMatchingLines is called
- Only lines matching all prefixes are returned

File Summary:
-------------
- main.cpp        → Handles reading, searching, and user interaction
- Trie.h / Trie.cpp → Implements the prefix-based Trie with full line storage
- Makefile        → Compiles main and Trie source files
- data/products_organized_full.txt → Makeup product dataset

Running the Program
--------------------
To compile and run the program:
1. Open terminal in the root project folder
2. Run `make`
3. Run `./SmartMakeupSearch`
4. Enter one or more prefix terms (e.g., `foun oily`)
5. Type `exit` to quit

Example Queries
---------------
Input: foun oily
Result: Shows products that include both a word starting with "foun" (like foundation) and "oily"

Input: lip gloss
Result: Lists lip gloss products regardless of brand or skin type

Citations and References
-------------------------
- Trie Data Structure Overview: https://en.wikipedia.org/wiki/Trie
- Trie Visual Explanation: https://www.youtube.com/watch?v=2ENTVJQ-1rM
- Trie Basics Explained: https://youtu.be/c6OXmAlpS9c
- zyBooks CSPB 2270: Computer Science 2: Data Structures
- Makeup product references based on Sephora.com for educational use only
