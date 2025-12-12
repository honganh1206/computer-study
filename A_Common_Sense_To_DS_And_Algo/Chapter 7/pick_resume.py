def pick_resume(resumes):
    eliminate = "top"
    while len(resumes) > 1:
        if eliminate == "top":
            resumes = resumes[
                len(resumes) // 2 : len(resumes) - 1
            ]  # Eliminate the top half
            eliminate = "bottom"
        elif eliminate == "bottom":
            resumes = resumes[0 : len(resumes) // 2]  # Eliminate the bottom half
            eliminate = "top"
    return resumes[0]


print(pick_resume(["Albert", "John", "Tim", "David", "Bob"]))
