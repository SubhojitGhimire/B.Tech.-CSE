# FOR A GRAPH WITH HIGH NUMBER OF NODES, (LIKE KARATE CLUB GRAPH), Salton Index gives error.
# However, even for graphs with high number of nodes, the other meausres work.
# The problem is with Salton Index only.
# Instead of calling lab8Graph.gml, you can make a random graph by your own, but sometimes random graphs give error:
# ERROR IS LIKE: ValueError: operands could not be broadcast together with shapes (x, ) (y, )
# In case of such error, keep re-running the porgram. For different graphs, this error is resolved or doens't exist.
# Again, this error is associated with Salton Index only. Delete the Salton Index part, and there are no errors for other index measures.

from turtle import color
import networkx as nx
import matplotlib.pyplot as plt
from pyparsing import alphas
import numpy as np
from scipy import spatial

def saltonList (G):
    edges = nx.edges(G)
    n = G.number_of_nodes()
    list = [[]]
    for i in range (n-1):
        list += [[]]
    for i in range (n):
        for j in edges:
            if (j[0] == i):
                list [i].append (j[1])
            if (j[1] == i):
                list [i].append (j[0])
    _list = [[]]
    var = 0
    for i in range (n):
        for j in range (i+1, n):
            if j not in list[i]:
                _list[var].append (i)
                _list[var].append (j)
                var += 1
                _list += [[]]
    _list.remove ([])
    var = 0
    for i in _list:
        cosineSimilarity = 1 - spatial.distance.cosine (list [i[0]], list [i[1]])
        _list[var].append(cosineSimilarity)
        var += 1
    return _list
    
G = nx.read_gml ('lab8Graph.gml')

print ("Salton index")
preds = saltonList(G)
for p in preds:
    print (p[0], ",", p[1], "->", p[2])

print ("Adamic-Adar index")
preds = nx.adamic_adar_index(G)
for p in preds:
    print (p[0], ",", p[1], "->", p[2])

print ("Jaccard coefficient")
preds = nx.jaccard_coefficient (G)
for p in preds:
    print (p[0], ",", p[1], "->", p[2])

print ("Preferential attachment")
preds = nx.preferential_attachment (G)
for p in preds:
    print (p[0], ",", p[1], "->", p[2])

print ("Resource Allocation index")
preds = nx.resource_allocation_index (G)
for p in preds:
    print (p[0], ",", p[1], "->", p[2])

nx.draw_networkx (G, with_labels = 'True')
plt.show ()