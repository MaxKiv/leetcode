import gdb

# Define a pretty-printer for the HashTable
class HashTablePrinter:
    def __init__(self, val):
        self.val = val

    def to_string(self):
        # Access the fields of the HashTable struct
        length = self.val['length']
        capacity = self.val['capacity']
        entries = self.val['entries']

        # Format the information as a string
        result = f"Custom HashTable - Length: {length}, Capacity: {capacity}\n"
        result += "Entries:\n"

        for i in range(capacity):
            entry = (entries + i).dereference()
            key = entry['key']
            type = gdb.lookup_type('int').pointer()
            value = entry['value'].cast(type)

            if value == 0:
                result += f"Entry {i}: Empty\n"
            else:
                result += f"Entry {i}: Key={key.dereference()} Value={value.dereference()}\n"

        return result

def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("my_hashtable_printer")
    pp.add_printer('ht', '^ht$', HashTablePrinter)
    return pp

gdb.printing.register_pretty_printer(gdb.current_objfile(), build_pretty_printer())

