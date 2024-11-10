class BrowserHistory:
    def __init__(self):
        self.history = []

    def push(self, url):
        self.history.append(url)
        print(f"Visited: {url}")

    def pop(self):
        if not self.history:
            print("No history to go back.")
            return None
        last_url = self.history.pop()
        print(f"Removed: {last_url}")
        return last_url

    def display_history(self):
        if not self.history:
            print("History is empty.")
            return
        print("\n--- Browser History ---")
        for idx, url in enumerate(reversed(self.history), 1):
            print(f"{idx}. {url}")
        print("-----------------------")

history = BrowserHistory()
history.push("https://example.com")
history.push("https://openai.com")
history.push("https://github.com")
history.display_history()
history.pop()
history.display_history()
