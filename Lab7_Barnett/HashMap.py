class HashTable:

    def __init__(self, size):
        self.size = size
        self.hash_g = self._hash_function()
 
    def _hash_function(self):
        return [[] for _ in range(self.size)]

    def put(self, key, val):
        hashk = hash(key) % self.size
        temporary = self.hash_g[hashk]
        target = False
        for index, record in enumerate(temporary):
            record_k, record_v = record
            if record_k == key:
                target = True
                break
        if target:
            temporary[index] = (key, val)
        else:
            temporary.append((key, val))

    def get(self, key):
        hashk = hash(key) % self.size
        temporary = self.hash_g[hashk]
        target = False
        for index, record in enumerate(temporary):
            record_k, record_v = record
            if record_k == key:
                target = True
                break
        if target:
            return record_v
        else:
            return "Not in the Hashmap"
 
    def remove(self, key):
        hashk = hash(key) % self.size
        temporary = self.hash_g[hashk]
 
        target = False
        for index, record in enumerate(temporary):
            record_k, record_v = record
            if record_k == key:
                target = True
                break
        if target:
            temporary.pop(index)
        return
 
    def __str__(self):
        return "".join(str(item) for item in self.hash_g)