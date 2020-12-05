t = int(input())

while t:
    S, k = input().split()
    k = int(k)

    #buscamos las posiciones de todos los numeros
    #guardaremos rangos

    numbersPos = []
    number = ''
    begin = 0
    end = 0
    for i in range(0, len(S)):
        if S[i].isdigit():
            if begin == end:
                begin = end = i
            end += 1
        else: #es letra
            if begin != end:
                numbersPos.append([begin, end - 1])
                begin = end = i
    
    #DEBEMOS CHECAR SI HAY NUMERO Y A SU DERECHA NO HAY LETRA?

    #calculamos el tamaño
    size = len(S) - 2 * len(numbersPos)
    numbers = []
    for r in numbersPos:
        number = int(S[r[0]:r[1]+1])
        numbers.append(number)
        size += number
    
    if size > k:
        print('unfeasible')
    else:
        #print('es válido')
        for i in range(0, len(S)):
            ok = 0
            #checamos si la posición esta dentro de un rango
            for j in range(0, len(numbersPos)):
                if i == numbersPos[j][0]:
                    print((numbers[j]-1) * S[i + 1], end = '')
                    i = numbersPos[j][1]
                    ok = 1
                    break
            if not ok:
                print(S[i], end = '')

        print('') #salto de linea
        
    t -= 1

"""
4
5a2bc 8
5a2bc 7
asdf4x 50
asjkdf10000000000kz 1000000
"""