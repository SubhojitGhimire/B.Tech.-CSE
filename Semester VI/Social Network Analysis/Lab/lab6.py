from cgitb import reset
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import community as community_louvain
import matplotlib.cm as cm
import math
import networkx as nx
from networkx.algorithms.community import LFR_benchmark_graph
import matplotlib.pyplot as plt
from itertools import combinations
import time
from collections import defaultdict

partition = {}
res = []
count = {}

# ANUI
# STRENGTH OF NODE delta(u,v)
def delta (u,v):
  return math.matrix [u][v]

# UNIFIABILITY BETWEEN CLUSTER C[i] and C[j]
def unifiability (GG, Ci, Cj, mat):
    sum1, sum2, sum3 = 0, 0, 0
    for ii in Ci:
        for jj in Cj:
            sum1 += int (mat [[ii], [jj]])
    for ii in Ci:
        for jj in GG:
            sum2 += int (mat [[ii], [jj]])
        for jj in Cj:
            sum2 -= int (mat [[ii], [jj]])
    for ii in Cj:
        for jj in GG:
            sum3 += int (mat [[ii], [jj]])
        for jj in Ci:
            sum3 -= int (mat [[ii], [jj]])
    return sum1 / (sum2 + sum3 - sum1)

# AVERAGE UNIFIABILITY
def AVU (GG, cluster, mat):
    #CALLING UNIFIABILITY FOR ALL CLUSTERS
    sum_unifiability = 0
    for ii in cluster:
        for jj in cluster:
            if ii != jj:
                sum_unifiability += unifiability (GG, ii, jj, mat)
    return sum_unifiability / len (cluster)

# ISOLABILITY OF CLUSTER C[i]:
def isolability (GG, Ci, mat):
    sum1, sum2 = 0, 0
    for ii in Ci:
        for jj in Ci:
            sum1 += int (mat [[ii], [jj]])
    for ii in Ci:
        for jj in GG:
            if ii != jj:
                sum2 += int (mat [[ii], [jj]])
    return sum1 / (sum1 + sum2)

# AVERAGE ISOLABALITY
def AVI (GG, cluster, mat):
    sum = 0
    for ii in cluster:
        sum += isolability (GG, ii, mat)
    return sum / len (cluster)

# AVERAGE UNIFIABILITY AND ISOLABILITY
def AUI (GG, cluster, mat):
    avi = AVI (GG, cluster, mat)
    avu = AVU (GG, cluster, mat)
    return (2 * avi) / (1 + avu * avi)

# AVERAGE NORMALISED UNIFIABILITY AND ISOLABILITY
def ANUI (GG, cluster, mat):
    return AUI (GG, cluster, mat) / 2

# WLC CLUSTERS PARTITIONS
def WLC (path):
    # path : the path of txt file containing edges of graph

    tt = []
    tri = []
    
    GG = nx.read_gml (path, label = 'id')
    nx.write_edgelist (GG, 'tempEdgeList.txt', delimiter = ',')
    GG = nx.read_edgelist ('tempEdgeList.txt', comments = '#', delimiter = ',', nodetype = int, encoding = 'utf-8') # txt file
    ns = len (GG.nodes ())
    NN = GG.number_of_edges ()
    tt = []
    den = nx.density (GG)
    re = []
    # res = []
    res1 = []
    res2 = []
    rx = []
    ww1 = []
    tps1 = time.time ()
    T11 = list (GG.nodes ())
    ii = 0
    while ii < len (T11):
        cpt1 = 0
        zx = list (GG.neighbors (T11 [ii]))
        aa = len (zx)
        jj = 0
        while jj < aa - 1:
            jj1 = jj + 1
            while jj1 < aa:
                if  GG.has_edge (zx [jj], zx [jj1]):
                   cpt1 = cpt1+1
                jj1 = jj1 + 1
            jj = jj + 1
        if aa > 1:
            ww1.append (2 * cpt1 / (aa * (aa - 1)))
        else:
            ww1.append (0)
        ii = ii + 1
    TT = GG.nodes ()
    while len (TT) > 0:
        nst = []
        SS = GG.subgraph (TT)
        for kk in TT:
            nst.append ([SS.degree (kk), kk])
        nst.sort (reverse = True)
        ll = nst [0][1]
        ini = list (set (SS.neighbors (ll)))
        ini.append (ll)
        nn = len (ini)
        nn1 = len (ini)
        bb = True
        while bb == True:
            mm1 = []
            temp = -1
            for rr in ini:
                aa = ww1 [T11.index (rr)]
                xx = list (SS.neighbors (rr))
                wx1 = 0
                wx2 = 0
                if len (xx) > 0:
                    for rx1 in xx:
                        dd1 = ww1 [T11.index (rx1)]
                        dd = (dd1 + len (sorted (nx.common_neighbors (GG, rr, rx1))))
                        wx1 = wx1 + dd 
                        if rx1 in ini:
                            wx2 = wx2 + dd
                    if wx1 > 0:
                        bl = wx2 / wx1
                        if bl < 0.5:
                            ini.remove (rr)
            nn1 = len (ini)
            if  nn1 < nn:  
                nn = nn1        
                bb = True
            else:
                bb = False
        bb = 1
        while bb == 1:
            xx = []
            for kk in ini:   
                xx.extend (GG.neighbors (kk))
                xx = list (set (xx) - set (ini))
            nn = len (ini)
            mm1 = []
            for rr in xx:                
                xx1 = list (GG.neighbors (rr))
                wx1 = 0
                wx2 = 0
                if len (xx1) > 0:
                    for rx1 in xx1:
                        dd1 = ww1 [T11.index (rx1)]
                        dd = (dd1 + len (sorted (nx.common_neighbors (GG, rr, rx1))))
                        wx1 = wx1 + dd
                        if rx1 in ini:
                            wx2 = wx2 + dd
                    if wx1 > 0:
                        bl = wx2 / wx1
                        if bl >= 0.4:
                            mm1.append (rr)
            ini.extend (mm1)
            nn1 = len (ini)
            if nn1 > nn:
                bb = 1
            else:   
                bb = 0
                break                   
        res.append (ini)
        rx.extend (ini)
        TT = list (set (TT) - set (ini))
        if (len (ini) == 0):
            TT.remove (ll)
    tps2 = time.time ()
    newFile = open ("results.txt", "w")
    for res1 in res:
        for kk in res1:
            newFile.write (str (kk-1))
            newFile.write (' ')
        newFile.write ('\n')
    newFile.close ()

# ENTENDED MODULARITY
def EQ (GG, cluster, mat):
    # mat = nx.to_numpy_matrix (GG)
    deg = {}
    mm = 0
    for ii in range (0, len (mat)):
        for jj  in range (0, len (mat)):
            if (mat [[ii], [jj]] == 1):
                mm += 1
                if ii in deg:
                    deg [ii] += 1
                else:
                    deg [ii] = 1
    
    eq = 0
    for cc in res:
        ans = 0
        for ii in cc:
            for jj in cc:
                if (ii != jj):
                    ans += (mat [ii, jj] - ((deg [ii] * deg [jj]) / mm)) / (count [ii] * count [jj])
        eq += ans
        
    return eq/mm

# PLOT GRAPH
def graphPlot (path, title):
    
    GG = nx.read_gml (path, label = 'id')
    community = {}
    openResult = open ('results.txt', 'r')
    readLine = openResult.readlines ()

    ii = 0
    for line in readLine:
        aa = list (map (int, line.split ()))
        for xx in range(0, len(aa)):
            aa [xx] = aa [xx] + 1
        community [ii] = aa
        ii = ii + 1

    comDict = defaultdict (lambda: 0)
    comColour = dict ()

    for ii, com in community.items ():
        comColour |= {node: ii + 10 for node in com}
        for node in com:
            comDict [node] = comDict [node] + 1

    pos = nx.spring_layout (GG, k = 0.2, seed = 4572321)

    overlappedNodes = {node for node, n_comm in comDict.items() if n_comm > 1}
    nodeColour = [0 if nn in overlappedNodes else comColour [nn] for nn in GG]

    options = {
        "pos" : pos, 
        "with_labels" : False, 
        "node_color" : nodeColour, 
        "node_size" : 250,  
    }

    plt.figure (figsize = (15, 15))
    plt.title (title)
    nx.draw_networkx (GG, **options)
    plt.show ()

def readGraph (graphName):
    GG = nx.read_gml (graphName, label = 'id')
    mat = nx.to_numpy_matrix (GG)

    var = 1
    for ii in res:
        print ("CLUSTER ", var, "= ", ii)
        var += 1

    # AVERAGE UNIFIABILITY OF GRAPH
    AVU_G = AVU (GG, res, mat)
    print ("AVERGAE UNIFIABILITY = ", AVU_G)
    # AVERAGE ISOLABILITY
    AVI_G = AVI (GG, res, mat)
    print ("AVERAGE ISOLABILITY = ", AVI_G)
    # AVERAGE UNIFIABILITY AND ISOLABILITY
    AUI_G = AVI (GG, res, mat)
    print ("AVERAGE UNIFIABILITY AND ISOLABILITY = ", AUI_G)
    # AVERAGE NORMALISED UNIFIABILITY AND ISOLABILITY
    ANUI_G = ANUI (GG, res, mat)
    print ("AVERAGE NORMALISED UNIFIABILITY AND ISOLABILITY = ", ANUI_G)
    # EXTENDED MODULARITY
    EQ_G = EQ (GG, res, mat)
    print ("EXTENDED MODULARITY = ", EQ_G)

def clearFields ():
    res.clear ()
    count.clear ()
    partition.clear ()

# KARATE CLUB
print ('\nKARATE CLUB')
karate_Graph = nx.karate_club_graph ()
nx.write_gml (karate_Graph, "karate.gml")
WLC ('karate.gml')
readGraph ("karate.gml")
graphPlot ('karate.gml', 'KARATE CLUB')
clearFields ()

# # LFR BENCHMARK
# print ('\n\n\nLFR BENCHMARK')
# # LFR_Graph = LFR_benchmark_graph (n = 1000, tau1 = 2, tau2 = 1.1, mu = 0.1, min_degree = 20, max_degree = 50, max_iters = 2500, seed = 10)
# LFR_Graph = LFR_benchmark_graph (n = 250, tau1 = 3, tau2 = 1.5, mu = 0.1, average_degree = 5, min_community = 20, seed = 10)
# # LFR_Graph = LFR_benchmark_graph (n = 100, tau1 = 3, tau2 = 1.5, mu = 0.25, average_degree = 10, min_community = 5, seed = 10)
# nx.set_node_attributes (LFR_Graph, {n: ','.join (map (str, LFR_Graph.nodes[n]['community'])) for n in LFR_Graph.nodes()}, 'community')
# nx.write_gml (LFR_Graph, "LFR_Overlapping.gml")
# WLC ('LFR_Overlapping.gml')
# readGraph ("LFR_Overlapping.gml")