class TrieNode:
    def __init__(self):
        self.letters = {}
        self.word = False

class Trie:

    def __init__(self):
        self.root = TrieNode()
        

    def insert(self, word: str) -> None:
        ptr = self.root
        for c in word:
            if c not in ptr.letters:
                ptr.letters[c] = TrieNode()

            ptr = ptr.letters[c]
        
        ptr.word = True
        

    def search(self, word: str) -> bool:
        ptr = self.root
        for c in word:
            if c not in ptr.letters:
                return False
                
            ptr = ptr.letters[c]
        
        return ptr.word
        

    def startsWith(self, prefix: str) -> bool:
        ptr = self.root
        for c in prefix:
            if c not in ptr.letters:
                return False
                
            ptr = ptr.letters[c]
        
        return True