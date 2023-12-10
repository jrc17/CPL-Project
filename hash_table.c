// C program to implement a dictionary using a hash table.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Structure to represent a word-definition pair
// This is an imperative paradigm, not an object-oriented concept.

typedef struct WordDefPair {
    char* key;                  // Word
    char* value;                // Definition
    struct WordDefPair* next;   // Pointer to the next pair in case of collisions
} WordDefPair;

// Structure for the hash table
typedef struct {
    WordDefPair* table[TABLE_SIZE]; // Array of WordDefPair pointers
} HashTable;

// Hash function to compute the index for a given key
// Imperative paradigm shown through the assignment and iterations
unsigned int hash(const char* key) {
    unsigned int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31 + *key++) % TABLE_SIZE;
    }
    return hash_value;
}

// Create a new WordDefPair
WordDefPair* createWordDefPair(const char* key, const char* value) {
    // We define how to alloate memory using the malloc functions
    WordDefPair* pair = (WordDefPair*)malloc(sizeof(WordDefPair));
    if (pair) {
        pair->key = strdup(key);
        pair->value = strdup(value);
        pair->next = NULL;
    }
    return pair;
}

// Create a new HashTable
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            ht->table[i] = NULL;
        }
    }
    return ht;
}

// Insert a word-definition pair into the hash table
void insert(HashTable* ht, const char* key, const char* value) {
    unsigned int index = hash(key);
    WordDefPair* pair = createWordDefPair(key, value);
    if (ht->table[index] == NULL) {
        ht->table[index] = pair;
    } else {
        WordDefPair* current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pair;
    }
}

// Search for the definition of a word in the hash table
const char* search(HashTable* ht, const char* key) {
    unsigned int index = hash(key);
    WordDefPair* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return "Word not found in the dictionary.";
}

// Load dictionary data from a file into the hash table
void loadDictionaryFromFile(HashTable* ht, const char* filename) {
    FILE* file = fopen(filename, "r");
    // If dictionary file does not exist , exit program
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        exit;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, "\n");
        if (key && value) {
            insert(ht, key, value);
        }
    }

    fclose(file);
}

// Free memory for a WordDefPair
// Since there is no automatic way to deallocate memory we use 'free' to do that
void freeWordDefPair(WordDefPair* pair) {
    free(pair->key);
    free(pair->value);
    free(pair);
}

// Free memory for the entire hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordDefPair* current = ht->table[i];
        while (current != NULL) {
            WordDefPair* temp = current;
            current = current->next;
            freeWordDefPair(temp);
        }
    }
    free(ht);
}

int main() {
    HashTable* dictionary = createHashTable();
    loadDictionaryFromFile(dictionary, "dictionary.txt");

    char str[100];
    while (1) {
        printf("Enter a word to find its definition or press # to exit (word should be in lowercase): ");
        scanf("%s", str);
        if (str[0] == '#') {
            break;
        }
        const char* word = str;

        printf("'%s': %s\n", word, search(dictionary, word));
    }

    freeHashTable(dictionary);
    return 0;
}
