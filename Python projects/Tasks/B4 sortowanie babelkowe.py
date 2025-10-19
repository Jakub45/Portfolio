def mispuchkita(k):
    x = len(k)
    while x > 1:
        zamien = False
        for m in range (0, x-1):
            if k[m] > k[m+1]:
                k[m], k[m+1] = k[m+1] , k[m] 
                zamien = True
                print (k)
        x -= 1
        print (k)
        if zamien == False: break
    return k

mispuchkita([9, 0, 4, 2, -8])
