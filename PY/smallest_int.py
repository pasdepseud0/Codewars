##
## CODEWARS PROJECT, 2023
## smallest_int.py
## Author:
## pasdepseudo
##

def find_smallest_int(arr):
    smallest_int = arr[0]
    for num in arr:
        if num < smallest_int:
            smallest_int = num
    return smallest_int    
