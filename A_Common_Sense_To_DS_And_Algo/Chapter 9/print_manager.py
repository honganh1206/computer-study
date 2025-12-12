from custom_queue import Queue


class PrintManager:
    def __init__(self):
        self.queue = Queue()

    def queue_print_job(self, document):
        self.queue.enqueue(document)

    def run(self):
        while self.queue.read():
            print(self.queue.dequeue())


print_manager = PrintManager()
print_manager.queue_print_job("First docs")
print_manager.queue_print_job("Second docs")

print_manager.run()
