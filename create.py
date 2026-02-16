import os

BASE_DIR = "codeforces"

userInput = input("Enter file names (e.g. A.fileName.fileExtension): ")

entries = userInput.split()

for entry in entries:
    if "." not in entry:
        continue

    letter, fileName = entry.split(".", 1)
    letter = letter.upper()

    letterPath = os.path.join(BASE_DIR, letter)
    os.makedirs(letterPath, exist_ok=True)

    filePath = os.path.join(letterPath, fileName)
    if not os.path.exists(filePath):
        open(filePath, "w").close()