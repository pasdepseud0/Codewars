##
## CODEWARS PROJECT, 2022
## bubblesort_once.py
## Author:
## pasdepseudo
##
def bubblesort_once(l):
    my_list = list(l)
    for bubble in range(len(my_list) - 1):
        if my_list[bubble] > my_list[bubble + 1]:
            my_list[bubble], my_list[bubble + 1] = my_list[bubble + 1], my_list[bubble]
    return my_list