# List of states to cover
states_needed = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])

stations = {}
# Keys = stations names and values = states covered
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])
final_stations = set()


def find_best_stations(states_needed):
    '''
    Iterate through each station and pick the one that covers the most uncovered states
    How it works:
    1. Use set intersection to extract the able-to-be-covered states
    2. Check if the number of able-to-be-covered states is larger than the needed one
    3. Remove the covered states from the need-to-cover states
    4. Add eligible stations to the complete station set
    '''
    while states_needed:
        best_station = None
        states_covered = set()
        for station, states in stations.items():
            # Set intersection (Find the elements that show up in both sets)
            covered = states_needed & states
            if (len(covered) > len(states_covered)):
                best_station = station
                states_covered = covered
        states_needed -= states_covered
        final_stations.add(best_station)


if __name__ == "__main__":
    find_best_stations(states_needed)
    print(final_stations)
