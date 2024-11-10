class ContactList:
    def __init__(self):
        self.contacts = []

    def add_contact(self, name, phone):
        self.contacts.append({"name": name, "phone": phone})
        print(f"Added: {name}")

    def delete_contact(self, name):
        for c in self.contacts:
            if c["name"].lower() == name.lower():
                self.contacts.remove(c)
                print(f"Deleted: {name}")
                return
        print(f"{name} not found!")

    def display_contacts(self):
        if not self.contacts:
            print("No contacts available.")
        else:
            for c in self.contacts:
                print(f"{c['name']} - {c['phone']}")
contacts = ContactList()
contacts.add_contact("Alice", "12345")
contacts.add_contact("Bob", "67890")
contacts.display_contacts()
contacts.delete_contact("Alice")
contacts.display_contacts()
