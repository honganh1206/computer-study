from collections import deque

graph = {}
# 1st degree connection
graph["you"] = ["alice", "bob", "claire"]
# 2nd degree connection
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thoj", "jonnym"]
# n-th degree connection
graph["anuj"] = []
graph["peggy"] = []
graph["thoj"] = []
graph["jonnym"] = []

# Add all neighbors as graph to search queue


def find_mango_seller(name):
    search_queue = deque()
    search_queue += graph[name]
    searched_list = []
    while search_queue:
        person = search_queue.popleft()
        if not person_is_searched(person, searched_list):
            if person_is_seller(person):
                print(person + " is the mango seller")
                return True
            else:
                search_queue += graph[person]
                searched_list.append(person)
    return False

def person_is_seller(name):
    return name[-1] == 'm'

def person_is_searched(name, searched_list):
    if name in searched_list:
        return True
    return False

find_mango_seller("you")