import os
from pathlib import Path

def count_cpp_lines(directory):
    totalLines = 0
    filesCount = 0

    for filepath in Path(directory).rglob('*.cpp'):
        try:
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as file:
                lines = file.readlines()
                totalLines += len(lines)
                filesCount += 1
        except Exception as e:
            print(f"Error reading {filepath}: {e}")

    return totalLines, filesCount

if __name__ == "__main__":
    projectFolder = '.' 
    
    print(f"Scanning for .cpp files in {os.path.abspath(projectFolder)}...")
    lines, files = count_cpp_lines(projectFolder)
    
    print("-" * 30)
    print(f"Total .cpp files found: {files}")
    print(f"Total lines of code: {lines}")