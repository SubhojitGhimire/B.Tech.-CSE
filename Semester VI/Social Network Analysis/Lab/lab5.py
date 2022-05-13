# WLC OVERLAPPING COMMUNITY ALGORITHM RESEARCH PAPER: https://dl.acm.org/doi/pdf/10.1145/3333165.3333172
# CODE REFERENCED FROM: https://github.com/khawka/WLC/blob/master/

import networkx as nx
import time
import matplotlib.pyplot as plt
from collections import defaultdict

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

def modu1 (GG, NN, res):
    mm = 0
    for UU in res:
        nn = len (UU)
        SS = GG.subgraph (UU)
        rx = []
        for kx in res:
            if not kx == UU:
                rx.extend (kx)
        ov = list (set (UU).intersection (set (rx)))
        sum1 = 0
        ii = 0
        while ii < len (UU):
            jj = ii + 1
            while jj < len (UU):
                if UU [ii] in ov :                    
                    oo = SS.degree (UU [ii])            
                    oo1 = 0
                    for lx in res:
                        if UU [ii] in lx:
                            SS1 = GG.subgraph (lx)
                            oo1 = oo1 + SS1.degree (UU [ii])                    
                    al1 = oo / oo1
                else:   
                    al1 = 1 
                if UU [jj] in ov:                    
                    ox = SS.degree (UU [jj])                  
                    ox1 = 0
                    for lx in res:
                        if UU [jj] in lx:
                            SS1 = GG.subgraph (lx)
                            ox1 = ox1 + SS1.degree (UU [jj]) 
                    al2 = ox / ox1    
                else :   
                    al2 = 1
                # tt = 2 * cpt
                if GG.has_edge (UU [jj], UU [ii]):
                    xx = ((1 - ((GG.degree (UU [ii]) * GG.degree (UU [jj])) / (2 * NN))) * al1 * al2)
                    sum1 = sum1 + 2 * xx  
                else:                    
                    sum1 = sum1 + 2 * ((0 - ((GG.degree (UU [ii]) * GG.degree (UU [jj])) / (2 * NN))) * al1 * al2)
                jj = jj + 1
            ii = ii + 1
        mm = mm + sum1
    mm = mm / (2 * NN) # compute the total modularity 
    return (mm)

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
    mm = 0 
    newFile = open ("results.txt", "w")
    for res1 in res:
        for kk in res1:
            newFile.write (str (kk-1))
            newFile.write (' ')
        newFile.write ('\n')
    newFile.close ()
    # compute overlapping modularity
    mm = modu1 (GG, NN, res)
    print ("OVERLAPPING MODULARITY: ", mm)

# KARATE CLUB
print ('\n\nKARATE CLUB\n')
WLC ('karate.gml')
graphPlot ('karate.gml', 'KARATE CLUB')

# FOOTBALL CLUB
print ('\n\nFOOTBALL CLUB\n')
WLC ("football.gml")
graphPlot ('football.gml', 'FOOTBALL CLUB')

# DOLPHIN NETWORK
print ("\n\nDOLPHINS NETWORK\n")
WLC ("dolphins.gml")
graphPlot ('dolphins.gml', 'DOLPHIN NETWORK')