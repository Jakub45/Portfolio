# import matplotlib.pyplot as plt
# import numpy as np
# import math

# plt.style.use('_mpl-gallery')
# x, y, z = np.indices((8, 8, 8))
# # x = [ 0,100 ]
# # y = [ 0,100 ]

# plt.plot ( x, y , z )
# plt.show (  )
# plt.grid( True )

# # x.append( np.random.randint( 0, 100 ) )
# y.append( np.random.randint( 0, 100 ) )

# plt.plot ( x,y )
# plt.show(  )
# plt.grid( True )


# import matplotlib.pyplot as plt
# import numpy as np

# plt.style.use('_mpl-gallery')

# # Prepare some coordinates
# x, y, z = np.indices((8, 8, 8))

# # Draw cuboids in the top left and bottom right corners
# cube1 = (x < 3) & (y < 3) & (z < 3)
# cube2 = (x >= 5) & (y >= 5) & (z >= 5)

# # Combine the objects into a single boolean array
# voxelarray = cube1 | cube2

# # Plot
# fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
# ax.voxels(voxelarray, edgecolor='k')

# ax.set(xticklabels=[],
#        yticklabels=[],
#        zticklabels=[])

# plt.show()


# from mpl_toolkits.mplot3d import axes3d
# import matplotlib.pyplot as plt

# plt.style.use('_mpl-gallery')

# # Make data
# X, Y, Z = axes3d.get_test_data(0.01)

# # Plot
# fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
# ax.plot_wireframe(X, Y, Z, rstride=10, cstride=10)

# ax.set(xticklabels=[0,1000],
#        yticklabels=[0,1000],
#        zticklabels=[0,1000])

# plt.show()