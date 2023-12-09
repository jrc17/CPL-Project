# Class to represent a key-value pair (word-definition pair)
# It is an Object-oriented concept with both variables and functions included inside the class
class WordDefPair:
   # We can mention how to initialize the object with, but there is no need to take care of how memory is allocated.
    def __init__(self, word, definition):
        self.key = word
        self.value = definition
        self.next = None

# Class for the dictionary hash table
class DicHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    # Hash function to compute the index for a given key
    def hash(self, key):
        hash_value = 0
        for char in key:
            hash_value = (hash_value * 31 + ord(char)) % self.size
        return hash_value

    # Insert a new word-definition pair into the hash table
    def insert(self, key, value):
        index = self.hash(key)
        new_pair = WordDefPair(key, value)
        if self.table[index] is None:
           self.table[index] = new_pair
        else:
           current = self.table[index]
           while current.next:
             current = current.next
           current.next = new_pair

    # Search for the definition of a word in the hash table
    def search(self, key):
        index = self.hash(key)
        current = self.table[index]
        while current:
             if current.key == key:
                return current.value
             current = current.next

        return "Word not found in the dictionary."

# Function to load dictionary data from a file into a hash table
def load_dictionary(file_path):
    dictionary = DicHashTable(100)

    try:
        with open(file_path, 'r') as file:
            for line in file:
                parts = line.strip().split(':')  # Assuming ':' is the delimiter
                if len(parts) == 2:
                    word, meaning = parts
                    dictionary.insert(word, meaning)
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
    return dictionary

# Main function to interact with the user
def main():
    file_path = "dictionary.txt"
    dictionary = load_dictionary(file_path)

    while True:
        word = input("Enter a word to find its definition or press # to exit (word should be in lowercase): ").strip()
        if word == '#':
            break

        print(f"'{word}': {dictionary.search(word)}")

if __name__ == "__main__":
    main()
