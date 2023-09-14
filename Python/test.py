import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 1000)
y = -np.sqrt(1 - x**2)

plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Graph of y = -√(1 - x^2)')
plt.grid(True)
plt.show()