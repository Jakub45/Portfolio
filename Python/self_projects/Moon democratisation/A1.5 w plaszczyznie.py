import matplotlib.pyplot as plt
import random

x = float( random.randint(0,100) )
y = float( random.randint(0,100) )

plt.plot(x,y)

plt.grid(True)
plt.show()