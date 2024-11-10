class ShoppingList:
    def __init__(self):
        self.items = []

    
    def add_item(self, item):
        self.items.append(item)
        print(f"Added: {item}")

    
    def remove_item(self, item):
        if item in self.items:
            self.items.remove(item)
            print(f"Removed: {item}")
        else:
            print(f"{item} not found in the list!")

    
    def display_list(self):
        if not self.items:
            print("The shopping list is empty.")
        else:
            print("\n--- Shopping List ---")
            for idx, item in enumerate(self.items, 1):
                print(f"{idx}. {item}")
            print("----------------------")
if __name__ == "__main__":
    shopping_list = ShoppingList()
    
    
    shopping_list.add_item("Apples")
    shopping_list.add_item("Bread")
    shopping_list.add_item("Milk")
    
    
    shopping_list.display_list()
    
    
    shopping_list.remove_item("Bread")
    
    shopping_list.display_list()
    shopping_list.remove_item("Eggs")
