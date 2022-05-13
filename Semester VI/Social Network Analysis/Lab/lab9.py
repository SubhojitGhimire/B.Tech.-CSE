import networkx as nx
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import spatial

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
    unconnectedNodes = findUnconnected (list, numOfNodes)
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
        cosineSimilarity = 1 - spatial.distance.cosine (adjMatrix [ii[0]], adjMatrix [ii[1]])
        unconnectedNodes[var].append (round (cosineSimilarity, 3))
        var += 1
    return unconnectedNodes

def precisionAUC (GG, df, preds, measure, t1, t2, train, test):
    
    # plt.figure ()
    # plt.title (measure)
    # nx.draw_networkx (GG, with_labels = True, alpha = 0.6)

    # PREDS LIST SORTED WITH HIGHEST SCORE AT THE TOP
    preds = sorted (preds, reverse = True, key = lambda x: x [2])

    # TOP 10000 LINKS SELECTED FROM THE PREDICTED LINKS
    preds = preds [:10000]

    # LINKS EXTRACTED INTO NEW LIST AND THE SDCORES ARE LEFT BEHIND
    predictedLinks = []
    for ii, jj, kk in preds:
        predictedLinks.append ([ii, jj])

    # LINKS EXTRACTED FROM TrAIN AND TEST DATAFRAMES
    l1, l2 = [], []
    x1, x2 = len (train), len (test)
    for ii in range (0, x1 - 1):
        l1.append ([train ['n1'][ii], train ['n2'][ii]])

    for ii in range (x1, x1 + x2):
        l2.append ([test ['n1'][ii], test ['n2'][ii]])

    # LINKS PUT INTO SETS FOR COMPUTATION PURPOSE
    trainSet = set (tuple (ii) for ii in l1)
    testSet = set (tuple (ii) for ii in l2)
    predictedLinksSet = set (tuple (ii) for ii in predictedLinks)

    truePositive = predictedLinksSet.intersection (testSet)
    falsePositive = predictedLinksSet.difference (truePositive)
    falseNegative = testSet.difference (truePositive)

    tpLen = len (truePositive)
    fpLen = len (falsePositive)
    fnLen = len (falseNegative)

    precision = tpLen / (tpLen + fpLen)
    print ("PRECISION = ", round (precision, 3))

    recall = tpLen / (tpLen + fnLen)
    # print ("RECALL = ", recall)

    nn, n1, n2 = 0., 0., 0.
    for ii in range (0, 10000):
        nn += 1
        tt, ff = np.random.randint (0, tpLen), np.random.randint (0, fpLen)
        if preds [tt][2] > preds [ff][2]:
            n1 += 1
        if preds [tt][2] == preds[ff][2]:
            n2 += 1
    AUC = (n1 + 0.5 * n2) / nn
    print ("AREA UNDER THE CURVE = ", round (AUC, 3))

# MAKING A RANDOM GRAPH OF FEW NODES
# GG = nx.erdos_renyi_graph (10, p = 0.8)
# GG = nx.read_gml ("dolphins.gml", label = 'id')
GG = nx.karate_club_graph ()
edges = nx.edges (GG)
print ("GRAPH EDGE SET:\n", edges)
newFile = open ('edgelist.txt', 'w')
for ii in edges:
    newFile.write (str (ii [0]))
    newFile.write (' ')
    newFile.write (str (ii [1]))
    newFile.write ('\n')
newFile.close ()
df = pd.read_csv("edgelist.txt",delimiter = ' ',header = None)
df.columns = ['n1','n2']
print (df)

# MAKING TRAINING AND TEST SETS
t1 = int (len (df) * 0.8)
t2 = len (df) - t1
train = df [:][:t1]
test = df [:][t1:t2+t1]

GG = nx.Graph ()
GG = nx.from_pandas_edgelist (train, 'n1', 'n2')

# SALTON INDEX (COSINE SIMILARITY)
preds = saltonList (GG)
print ("\nSALTON INDEX")
precisionAUC (GG, df, preds, "SALTON INDEX", t1, t2, train, test)

# ADAMIC-ADAR INDEX
preds = nx.adamic_adar_index (GG)
print ("\nADAMIC-ADAR INDEX")
precisionAUC (GG, df, preds, "ADAMIC-ADAR INDEX", t1, t2, train, test)

# JACCARD COEFFICIENT
preds = nx.jaccard_coefficient (GG)
print ("\nJACCARD COEFFICIENT")
precisionAUC (GG, df, preds, "JACCARD COEFFICIENT", t1, t2, train, test)

# PREFERENTIAL ATTACHMENT
preds = nx.preferential_attachment (GG)
print ("\nPREFERENTIAL ATTACHMENT")
precisionAUC (GG, df, preds, "PREFERENTIAL ATTACHMENT", t1, t2, train, test)

# RESOURCE ALLOCATION INDEX
preds = nx.resource_allocation_index (GG)
print ("\nRESOURCE ALLOCATION INDEX")
precisionAUC (GG, df, preds, "RESOURCE ALLOCATION INDEX", t1, t2, train, test)

# GRAPH PLOTTING
plt.figure ()
# plt.title ("ORIGINAL GRAPH")
nx.draw_networkx (GG, with_labels = True, node_color = 'green', alpha = 0.6)
plt.show ()