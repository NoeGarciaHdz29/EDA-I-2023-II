def fac_recur(numero):
    if numero < 2:
        return 1
    return numero * fac_recur(numero - 1)

print(fac_recur(5))
    