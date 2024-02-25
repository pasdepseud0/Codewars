##
## CODEWARS PROJECT, 2024
## is_a_number_prime.py
## Author:
## pasdepseudo
##

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True
