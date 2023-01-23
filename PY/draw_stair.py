##
## CODEWARS PROJECT, 2023
## draw_stair.py
## Author:
## pasdepseudo
##

def draw_stairs(n):
    stairs = ""
    for i in range(1, n + 1):
        stairs += " " * (i - 1) + "I\n"
    return stairs[:-1]