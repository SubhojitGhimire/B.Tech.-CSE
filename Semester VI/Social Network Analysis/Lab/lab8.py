# UPDATED CODE: NO LIMITATION
# WORKS FOR ALL KARATE CLUB GRAPH, FOOTBALL CLUB GRAPH, DOLPHIN GRAPH, GRAPH WITH LARGE NUMBER OF NODES, ETC.

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

    adjMatrix = [[]]
    var = 0
    for ii in range (n):
        for jj in range (n):
            if jj not in list [ii]:
                adjMatrix[var].append (0)
            else:
                adjMatrix[var].append (1)
        var += 1
        adjMatrix += [[]]
    adjMatrix.remove ([])

    var = 0
    for i in _list:
        cosineSimilarity = 1 - spatial.distance.cosine (adjMatrix [i[0]], adjMatrix [i[1]])
        _list[var].append(cosineSimilarity)
        var += 1
    return _list
    
# G = nx.read_gml ('lab8Graph.gml')
G = nx.karate_club_graph ()

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
