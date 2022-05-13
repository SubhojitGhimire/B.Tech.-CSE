from turtle import color
import networkx as nx
import matplotlib.pyplot as plt
from pyparsing import alphas
import numpy as np
from scipy import spatial

def printPreds (index, preds):
    print ("\n", index)
    for ii in preds:
        print ("(", ii [0], ", ", ii [1], ") = ", round (ii [2], 3))

def findUnconnected (list, numOfNodes):
    unconnectedList = [[]]
    var = 0
    for ii in range (numOfNodes):
        for jj in range (ii+1, numOfNodes):
            if jj not in list[ii]:
                unconnectedList[var].append (ii)
                unconnectedList[var].append (jj)
                var += 1
                unconnectedList += [[]]
    unconnectedList.remove ([])
    return (unconnectedList)

def saltonList (GG):
    edges = nx.edges (GG)
    numOfNodes = GG.number_of_nodes()
    list = [[]]
    for ii in range (numOfNodes-1):
        list += [[]]
    for ii in range (numOfNodes):
        for jj in edges:
            if (jj[0] == ii):
                list [ii].append (jj[1])
            if (jj[1] == ii):
                list [ii].append (jj[0])
    # print ("LISTS")
    # var = 0
    # for ii in list:
    #     print ("LIST ", var, " = ", ii)
    #     var += 1
    unconnectedNodes = findUnconnected (list, numOfNodes)
    # print (unconnectedNodes)

    adjMatrix = [[]]
    var = 0
    for ii in range (numOfNodes):
        for jj in range (numOfNodes):
            if jj not in list [ii]:
                adjMatrix[var].append (0)
            else:
                adjMatrix[var].append (1)
        var += 1
        adjMatrix += [[]]
    adjMatrix.remove ([])

    var = 0
    for ii in unconnectedNodes:
        # cosineSimilarity = dot (adjMatrix [ii[0]], adjMatrix [ii[1]]) / (norm (adjMatrix[ii[0]]) * norm (adjMatrix[ii[1]]))
        cosineSimilarity = 1 - spatial.distance.cosine (adjMatrix [ii[0]], adjMatrix [ii[1]])
        unconnectedNodes[var].append (round (cosineSimilarity, 3))
        var += 1
    return unconnectedNodes
    
# MAKING A RANDOM GRAPH OF FEW NODES
numOfNodes = 5
GG = nx.erdos_renyi_graph (numOfNodes, p = 0.6)
# GG = nx.karate_club_graph ()
edges = nx.edges (GG)
print ("GRAPH EDGE SET:\n", edges)

# SALTON INDEX (COSINE SIMILARITY)
preds = saltonList (GG)
printPreds ("SALTON INDEX", preds)

# ADAMIC-ADAR INDEX
preds = nx.adamic_adar_index (GG)
printPreds ("ADAMIC-ADAR INDEX", preds)
# with open ('adamicadar.txt', 'w') as file:
#     for ii in preds:
#         file.write (str (ii))
#         file.write ('\n')

# JACCARD COEFFICIENT
preds = nx.jaccard_coefficient (GG)
printPreds ("JACCARD COEFFICIENT", preds)

# PREFERENTIAL ATTACHMENT
preds = nx.preferential_attachment (GG)
printPreds ("PREFERENTIAL ATTACHMENT", preds)

# RESOURCE ALLOCATION INDEX
preds = nx.resource_allocation_index (GG)
printPreds ("RESOURCE ALLOCATION INDEX", preds)

# GRAPH PLOTTING
plt.figure (figsize = (15, 15))
nx.draw_networkx (GG, with_labels = 'True', node_color = 'green', alpha = 0.6)
plt.show ()