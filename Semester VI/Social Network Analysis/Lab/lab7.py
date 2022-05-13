import networkx as nx
import numpy as np
import time
import matplotlib.pyplot as plt
from collections import defaultdict
from networkx.algorithms.community import LFR_benchmark_graph

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

def WLC (path):
    # path : the path of txt file containing edges of graph

    tt = []
    tri = []
    
    GG = nx.read_gml (path, label = 'id') # GML file
    nx.write_edgelist (GG, 'tempEdgeList.txt', delimiter = ',')
    GG = nx.read_edgelist ('tempEdgeList.txt', comments = '#', delimiter = ',', nodetype = int, encoding = 'utf-8') # txt file
    ns = len (GG.nodes ()) # number of nodes in GG
    NN = GG.number_of_edges () # number of edges in GG
    tt = []
    den = nx.density (GG)
    re = []
    res = []
    res1 = []
    res2 = []
    rx = []
    ww1 = []
    tps1 = time.time ()
    T11 = list (GG.nodes ()) # list of nodes
    # Compute the clustering coeficient of nodes in GG
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
        # aj = [cpt1, aa]
        if aa > 1:
            ww1.append (2 * cpt1 / (aa * (aa - 1)))
        else:
            ww1.append (0)
        ii = ii + 1
    # print ('b', ww1)
    # ww1 is the list of clustering coeficient of nodes in GG
    TT = GG.nodes () # List of nodes in GG
    while len (TT) > 0:
        nst = []
        SS = GG.subgraph (TT) # the subgraph of GG containning elements in TT
        for kk in TT:
            nst.append ([SS.degree (kk), kk]) # list of nodes degrees in TT  
        nst.sort (reverse = True) # sort of nodes degree 
        ll = nst [0][1] # select the node with the highest node degree ll
        print ('PROCESSING NODE ', ll)
        ini = list (set (SS.neighbors (ll))) # list of neighbors of ll
        ini.append (ll) # add ll to its list of neighbor to construct the initial community
        nn = len (ini)
        nn1 = len (ini)
        # print ('ini', ini)
        bb = True
        # the supprsion of nodes with weak ties with the elements in ini
        while bb == True:
            mm1 = []
            temp = -1
            for rr in ini:
                aa = ww1 [T11.index (rr)] # the clustering coeficient of rr
                xx = list (SS.neighbors (rr)) # the neighbors of rr
                # print (xx)
                wx1 = 0 # the clustering coeficient and common_neighbors similarity of the set of neighbors of rr
                wx2 = 0 # the clustering coeficient and common_neighbors similarity of neighbors of rr belonging to ini
                if len (xx) > 0:
                    for rx1 in xx:
                        dd1 = ww1 [T11.index (rx1)]
                        dd = (dd1 + len (sorted (nx.common_neighbors (GG, rr, rx1)))) # /(len (GG.neighbors (rr1)) + len(xx))
                        # print (dd)
                        wx1 = wx1 + dd 
                        if rx1 in ini:
                            wx2 = wx2 + dd
                    if wx1 > 0:
                        bl = wx2 / wx1 # the weighted belonging degree of rr
                        # print (rr, ':' , bl)
                        if bl < 0.5:
                            ini.remove (rr)   # remove rr from initial community if its weighted belonging degree < 0.5
            # print (nn1)
            # ini = list (set (ini) - set (mm1))
            nn1 = len (ini) # the new size of the initial community 
            if  nn1 < nn:  
                nn = nn1        
                bb = True
            else:
                bb = False # stop when the size of the initial community remain stable    
        bb = 1
        # print ('EXPANSION OF COMMUNITY')
        while bb == 1:
            xx = []
            for kk in ini:   
                xx.extend (GG.neighbors (kk))
                xx = list (set (xx) - set (ini))
            # xx is the list of neighbors of elements in the initial community
            nn = len (ini)
            mm1 = []
            for rr in xx:                
                xx1 = list (GG.neighbors (rr))
                # print (xx)
                wx1 = 0 # the clustering coeficient and common_neighbors similarity of the set of neighbors of rr
                wx2 = 0 # the clustering coeficient and common_neighbors similarity of neighbors of rr belonging to ini
                if len (xx1) > 0:
                    for rx1 in xx1:
                        dd1 = ww1 [T11.index (rx1)]
                        dd = (dd1 + len (sorted (nx.common_neighbors (GG, rr, rx1))))
                        wx1 = wx1 + dd
                        if rx1 in ini:
                            wx2 = wx2 + dd
                    if wx1 > 0:
                        bl = wx2 / wx1 # the weighted belonging degree of rr
                        if bl >= 0.4:
                            mm1.append (rr) # select the node rr as its belonging degree > 0.4
            ini.extend (mm1) # expand the initial community with the node having their belonging degree > 0.4   
            nn1 = len (ini)  # the new lenght of the community   
            if nn1 > nn:
                bb = 1
            else:   
                bb = 0 # stop when the size of the community remain stable  
                break                   
        res.append (ini) # load the community in the list of communities 
        rx.extend (ini) # list of selected nodes
        TT = list (set (TT) - set (ini)) # keep only unselected nodes in TT
        if (len (ini) == 0):
            TT.remove (ll) # when the resulted community is empty ignore the node ll in the selection of the node with highest node strength
    # print (res)
    tps2 = time.time ()
    # print ('TIME TAKEN: ', tps2 - tps1) # the consumed time in the algorithm
    newFile = open ("results.txt", "w")
    for res1 in res:
        for kk in res1:
            newFile.write (str (kk-1))
            newFile.write (' ')
        newFile.write ('\n')
    newFile.close ()

def GEI (graph, attr):
    nn = graph.number_of_nodes ()
    gt_membership = [graph.nodes [v][attr] for v in graph.nodes ()]
    gt_communities = {}
    for ii in range (0, nn):
        if gt_membership [ii] not in gt_communities:
            gt_communities [gt_membership [ii]] = []      
        gt_communities [gt_membership [ii]].append (ii)
    communities = {}
    ii = 0
    file = open ('results.txt', 'r')
    Lines = file.readlines ()
    for line in Lines:
        aa = list (map (int, line.split ()))
        if len (aa):
            communities [ii] = aa
            ii = ii + 1
    num = len (communities)

    alpha_psi = []
    for ii in range (0, nn + 1):
        alpha_psi.append (list (np.zeros (nn + 1, dtype = int)))

    for ii in range (0, nn):
        for jj in range (ii + 1, nn):
            for cc in range (0, num):
                if ii in communities [cc] and jj in communities [cc]:
                    alpha_psi [ii][jj] += 1
    alpha_gt = []
    for ii in range (0, nn + 1):
        alpha_gt.append (list (np.zeros (nn + 1, dtype = int)))

    for ii in range (0, nn):
        for jj in range (ii + 1, nn):
            for cc in gt_communities.keys ():
                if ii in gt_communities [cc] and jj in gt_communities [cc]:
                    alpha_gt [ii][jj] += 1
    beta_psi = [0 for ii in range (0, nn)]
    for ii in range (0, nn):
        for cc in range (0, num):
            if ii in communities [cc]:
                beta_psi [ii] += 1
        beta_psi [ii] -= 1
    beta_gt = [0 for ii in range (0, nn)]
    for ii in range (0, nn):
        for cc in gt_communities.keys ():
            if ii in gt_communities [cc]:
                beta_gt [ii] += 1
        beta_gt [ii] -= 1
    aa_GG = []
    for ii in range(0, nn + 1):
        aa_GG.append (list (np.zeros (nn + 1, dtype = int)))
    for ii in range (0, nn):
        for jj in range (ii + 1, nn):
            aa_GG [ii][jj] = min (alpha_psi [ii][jj], alpha_gt [ii][jj]) + min (beta_psi [ii], beta_gt [ii]) + min (beta_psi [jj], beta_gt [jj])
    dd_GG = []
    for ii in range (0, nn + 1):
        dd_GG.append (list (np.zeros (nn + 1, dtype = int)))
    for ii in range (0, nn):
        for jj in range (ii + 1, nn):
            dd_GG [ii][jj] = abs (alpha_psi [ii][jj] - alpha_gt [ii][jj]) + abs (beta_psi [ii] - beta_gt [ii]) + abs (beta_psi [jj] - beta_gt [jj])
    aa = np.sum (aa_GG)
    dd = np.sum (dd_GG)
    GEI = aa / (aa + dd)
    return GEI

# KARATE CLUB
print ('\nKARATE CLUB')
karate_Graph = nx.karate_club_graph ()
nx.write_edgelist (karate_Graph, "karateedgelist.txt", delimiter = ',')
nx.write_gml (karate_Graph, "karate.gml")
WLC ('karate.gml')
print ("GEI Value = ", GEI (karate_Graph, 'club'))
graphPlot ('karate.gml', 'KARATE CLUB')

# LFR BENCHMARK
print ('\n\n\nLFR BENCHMARK')
# LFR_Graph = LFR_benchmark_graph (n = 1000, tau1 = 2, tau2 = 1.1, mu = 0.1, min_degree = 20, max_degree = 50, max_iters = 2500, seed = 10)
LFR_Graph = LFR_benchmark_graph (n = 250, tau1 = 3, tau2 = 1.5, mu = 0.1, average_degree = 5, min_community = 20, seed = 10)
# LFR_Graph = LFR_benchmark_graph (n = 100, tau1 = 3, tau2 = 1.5, mu = 0.25, average_degree = 10, min_community = 5, seed = 10)
nx.set_node_attributes (LFR_Graph, {n: ','.join (map (str, LFR_Graph.nodes[n]['community'])) for n in LFR_Graph.nodes()}, 'community')
nx.write_edgelist (LFR_Graph, "lfredgelist.txt", delimiter = ',')
nx.write_gml (LFR_Graph, "LFR_Overlapping.gml")
WLC ('LFR_Overlapping.gml')
print ("GEI Value = ", GEI (LFR_Graph, 'community'))
graphPlot ('LFR_Overlapping.gml', 'LFR BENCHMARK')